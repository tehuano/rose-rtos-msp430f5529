/** ************************************************************************************************
 *  \file       TaskPackage.c
 *  \brief      Hardware independent part of the ECC hardware selftest (header file)
 *  \date       2015-08-03
 *  \revision   $Revision: 1.5 $
 *  \author     Rommel García Hernández
 *  \copyright  Continental Automotive 2015
 *  Implements the hardware independent part of the the ECC selftest for all processor platforms.
 */

#include <msp430.h>
#include "Hardware.h"
#include "Tasks.h"
#include "sha2.h"

int sha256_example(uint32_t * hash);

static unsigned char rbit = 0x00;
static unsigned long long int rbit_last_move = 0;
static unsigned char vdigital = 0x00;
static unsigned char p1_0_state = FALSE;
static unsigned char p1_0_last_state = FALSE;
static unsigned char blinking_led_enable =  FALSE;
static float voltage = 0.0;

void Task_5msInit() {

}

void Task_5ms(void) {
    p1_0_last_state = p1_0_state;
    p1_0_state = ((P2IN & BIT1) == 0x00);
    ADC12CTL0 |= ADC12ENC+ADC12SC;        //Inicia conversión analógica
    while (!(ADC12IFG0 & ADC12IFG));      //Espera mientras no está lista la conversión
    vdigital = ADC12MEM0 >> 4;            //Transfiere el dato a digital
    voltage = vdigital*0.01294117;        //Convierte de 0 a 3.3
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
}

void Task_20msInit() {

}

void Task_20ms(void) {

}

void Task_40msInit() {

}

void Task_40ms(void) {

}

void Task_80msInit() {

}

void Task_80ms(void) {
    uint32_t hash[8];
    sha256_example(&hash[0]);
}

int sha256_example(uint32_t * hash){
  //  Input: 0xbd (1 byte)
  //  Expected Result: 68325720 aabd7c82 f30f554b 313d0570 c95accbb 7dc4b5aa e11204c0 8ffe732b
  int i;
  // Space must be reserved for 64 bytes
  uint32_t message[16];
  uint32_t expected[8];
  const uint32_t bytes_to_be_hashed = 1;
  short hash_mode;

  // expected
  expected[0] = 0x68325720;
  expected[1] = 0xaabd7c82;
  expected[2] = 0xf30f554b;
  expected[3] = 0x313d0570;
  expected[4] = 0xc95accbb;
  expected[5] = 0x7dc4b5aa;
  expected[6] = 0xe11204c0;
  expected[7] = 0x8ffe732b;
  // MSB contains message
  message[0]=0xbd000000;

  hash_mode = SHA_256;

  SHA_2( &message[0], bytes_to_be_hashed, hash, hash_mode);
  for (i=0;i<8;i++)
  {
    if (hash[i] != expected[i])
        return(-1);
  }
  return(0);
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
    if (200 < vdigital) {
        blinking_led_enable = TRUE;
    }
}

void Task_Aperiodic_ButtonInit() {
    P2DIR &= ~BIT1;            /* P2.1 como entrada */
    P2REN |= BIT1;             //P2.1 con resistencia habilitada
    P2OUT |= BIT1;             //P2.1 con resistencia pull-up
    P1DIR |= BIT0;             // P1.0 output
}

void Task_Aperiodic_Button() {
    if (p1_0_last_state > p1_0_state) {
        P1OUT ^= BIT0;
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
