/** ************************************************************************************************
 *  \file       Task.c
 *  \brief      Implementation of periodic and aperiodic tasks (source file)
 *  \date       2019-07-01
 *  \revision   $Revision: 1.0 $
 *  \author     Rommel García Hernández
 *  \copyright  Guenda Tecnología de México
 *  Implements the behavior of periodic and aperiodic tasks.
 */

#include <msp430.h>
#include <string.h>
#include <stdio.h>
#include "Hardware.h"
#include "Tasks.h"

#define MCU_CLOCK           1000000
#define PWM_FREQUENCY       46           // In Hertz, ideally 50Hz.
#define SERVO_STEPS         180          // Maximum amount of steps in degrees (180 is common)
#define SERVO_MIN           650          // The minimum duty cycle for this servo
#define SERVO_MAX           2700         // The maximum duty cycle
#define SERVO_VAL           (90.0/255.0)
#define RAMP_PWM_PERIOD     511

unsigned int PWM_Period     = (MCU_CLOCK / PWM_FREQUENCY);  // PWM Period
unsigned int PWM_Duty       = 0;

unsigned int servo_lut[ SERVO_STEPS+1];
static unsigned char ram_buffer[128] = {0};
static unsigned char rbit = 0x00;
static unsigned long long int rbit_last_move = 0;
static unsigned char vdigital = 0x00;
static unsigned char blinking_led_enable =  FALSE;
static float voltage = 0.0;
static unsigned long long int bled_last_move = 0;
static unsigned int duty_cycle = 0;

static button_t button0;

const char max_speed_message[32] = "maximum speed reached: ";
unsigned int last_max_speed = 0;

void Task_5msInit() {

}

void Task_5ms(void) {
    evaluate_button();
    ADC12CTL0 |= ADC12ENC+ADC12SC;        /* starts analogic conversion */
    while (!(ADC12IFG0 & ADC12IFG));      /* Espera mientras no está lista la conversión */
    vdigital = ADC12MEM0 >> 4;            /* Transfiere el dato a digital */
    voltage = vdigital*0.01294117;        /* Convierte de 0 a 3.3 */
}

void Task_10msInit() {
    P3DIR |= BIT0; /* for LED P3.0 */
    P3DIR |= BIT1; /* for LED P3.1 */
    P3DIR |= BIT2; /* for LED P3.2 */
    P3OUT &= ~NUM7;
    P3OUT |= (NUM7 & rbit);
}

void Task_10ms(void) {
    unsigned long long int sys_tick = HardwareGetTick();
    if (RBIT_DELAY <= (sys_tick - rbit_last_move)) {
        rbit_last_move = sys_tick;
        if (NUM7 == rbit) {
            rbit = 0x00;
        } else {
            rbit++;
        }
        P3OUT &= ~NUM7;
        P3OUT |= (NUM7 & rbit);
    }
    if (RBIT_DELAY <= (sys_tick - bled_last_move)) {
        bled_last_move = sys_tick;
        if (TRUE == blinking_led_enable) {
            P4OUT ^= BIT7;
        } else {
            P4OUT &= ~BIT7;
        }
    }
}

void Task_20msInit() {
    /* ACLK = 32kHz */
    duty_cycle = 0;
    P2DIR |= BIT0;                            // P2.0
    P2SEL |= BIT0;                            // P2.0 options select
    TA1CCR0  = RAMP_PWM_PERIOD;                           // PWM Period
    TA1CCTL1 = OUTMOD_7;                      // CCR1 reset/set
    //TA1CCR1  =  0;                            // CCR1 PWM duty cycle
    TA1CTL   = TASSEL_1 + MC_1 + TACLR;       // ACLK, up mode, clear TAR
}

void Task_20ms(void) {
    TA1CCR1 = duty_cycle;       /* Set next duty cycle value */
    duty_cycle += 5;            /* Add Offset to CCR0 */
    /* If counter is at the end of the array */
    if (duty_cycle >= RAMP_PWM_PERIOD) {
        duty_cycle = 0; /* Reset counter */
    }
}

void Task_40msInit() {
    unsigned int servo_stepval, servo_stepnow;
    unsigned int i;

   /* Calculate the step value and define the current step, defaults to minimum. */
   servo_stepval   = ( (SERVO_MAX - SERVO_MIN) / SERVO_STEPS );
   servo_stepnow   = SERVO_MIN;

   /* Fill up the LUT */
   for (i = 0; i < SERVO_STEPS; i++) {
       servo_stepnow += servo_stepval;
       servo_lut[i] = servo_stepnow;
   }

   /* Setup the PWM, etc. */
   TA0CCTL1 = OUTMOD_7;            /* TACCR1 reset/set */
   TA0CTL   = TASSEL_2 + MC_1;     /* SMCLK, upmode */
   TA0CCR0  = PWM_Period-1;        /* PWM Period */
   TA0CCR1  = servo_lut[45];       /* TACCR1 PWM Duty Cycle */
   P1DIR   |= BIT2;                /* P1.2 = output */
   P1SEL   |= BIT2;                /* P1.2 = TA1 output */
}

void Task_40ms(void) {
    TA0CCR1 = servo_lut[45 + (unsigned int)(vdigital * SERVO_VAL)];
    __delay_cycles(10);
    if (vdigital >= MAX_SPEED && last_max_speed < vdigital) {
        last_max_speed = vdigital;
        write_log(LOG_MAX_SPEED, (void *)&last_max_speed);
    }
}

void Task_80msInit() {
    unsigned int i;
    for (i = 0; i < 128; i++) {
        ram_buffer[i] = 0x00; /* Write 0 to all ram buffer */
    }
}

void Task_80ms(void) {
    write_SegC();
}

void write_SegC() {
  unsigned int i;
  char * Flash_ptr;                             /* Initialize Flash pointer */
  Flash_ptr = (char *) 0x1880;
  if (event_vector & FLASH_WRITE_EVENT) {
      FCTL3 = FWKEY;                            /* Clear Lock bit */
      FCTL1 = FWKEY+ERASE;                      /* Set Erase bit */
      *Flash_ptr = 0;                           /* Dummy write to erase Flash seg */
      FCTL1 = FWKEY+WRT;                        /* Set WRT bit for write operation */
      for (i = 0; i < 128; i++) {
          Flash_ptr[i] = ram_buffer[i];         /* Write value to flash */
      }
      FCTL1 = FWKEY;                            /* Clear WRT bit */
      FCTL3 = FWKEY+LOCK;                       /* Set LOCK bit */
      event_vector &= ~FLASH_WRITE_EVENT;
  }
}

void Task_Aperiodic_ADCInit() {
    ADC12CTL0 = ADC12SHT02 + ADC12ON; /* Sampling time, ADC12 on */
    ADC12CTL1 = ADC12SHP;             /* Use sampling timer */
    ADC12CTL0 |= ADC12ENC;
    P6SEL |= BIT0;                    /* P6.0 ADC option select */
    P4DIR |= BIT7;                    /* for LED P4.7 */
}

void Task_Aperiodic_ADC() {
    blinking_led_enable = FALSE;
    if (200 <= vdigital) {
        blinking_led_enable = TRUE;
    }
}

void Task_Aperiodic_ButtonInit() {
    button0.p_in      = &P2IN;
    button0.p_in_dir  = &P2DIR;
    button0.p_in_ren  = &P2REN;
    button0.p_in_pull = &P2OUT;
    button0.b_in      = BIT1;

    button0.p_out     = &P1OUT;
    button0.p_out_dir = &P1DIR;
    button0.b_out     = BIT0;

    button0.counter = 0;
    button0.state   = FALSE;

    *(button0.p_in_dir)  &= ~button0.b_in; /* P2.1 as input */
    *(button0.p_in_ren)  |= button0.b_in;  /* P2.1 enable resistor */
    *(button0.p_in_pull) |= button0.b_in;  /* P2.1 pull-up */
    /* output configuration */
    *(button0.p_out_dir) |= button0.b_out;     /* P1.0 output */
    *(button0.p_out)     &= ~button0.b_out;     /* P1.0 output */
}

void Task_Aperiodic_Button() {
    if (button0.counter >= 5) {
        if (TRUE == button0.state) {
            *(button0.p_out) |= button0.b_out;
        } else {
            *(button0.p_out) &= ~button0.b_out;
        }
    }
}

void Task_PeriodicServer6msInit() {
    Task_Aperiodic_ADCInit();
    Task_Aperiodic_ButtonInit();
}

void Task_PeriodicServer6ms() {
    Task_Aperiodic_ADC();
    Task_Aperiodic_Button();
}

void write_log(unsigned char id, void *value) {
    if (LOG_MAX_SPEED == id) {
        char msg[16];
        unsigned int ln = strlen(max_speed_message);
        memcpy(&ram_buffer[LOG_MAX_SPEED], max_speed_message, ln);
        sprintf(msg, "%d", *((unsigned int *)value));
        memcpy(&ram_buffer[LOG_MAX_SPEED + ln], msg, strlen(msg));
        event_vector |= FLASH_WRITE_EVENT;
    }
}

void evaluate_button() {
    if ((~(*(button0.p_in))) & button0.b_in) {
        if (TRUE == button0.state) {
            if (button0.counter >= 5) {
                button0.counter = 5;
            }
            button0.counter++;
        } else {
            button0.state = TRUE;
            button0.counter = 1;
        }
    } else if ((*(button0.p_in)) & button0.b_in) {
        if (FALSE == button0.state) {
            if (button0.counter >= 5) {
                button0.counter = 5;
            }
            button0.counter++;
        } else {
            button0.state = FALSE;
            button0.counter = 1;
        }
    }
}
