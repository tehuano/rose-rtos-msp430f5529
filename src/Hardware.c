/**
 * @file       Hardware.c
 * @brief      Hardware dependent part of RTOS
 *
 * Implements the hardware dependent part of the RTOS. Configures timers and interruptions.
 *
 * @date       2019-07-01
 * $Revision: 1.0$
 * @author     Rommel García Hernández
 * @copyright  Guenda Tecnología de México 2015
 */

#include <msp430.h>
#include "Hardware.h"

/**
 * @brief      Hardware tick counter
 * @range      TBD
 * @resolution 64
 * @unit       None
 */
static unsigned long long int hardware_tick;

/**
 * @brief      Counter to make a leap in the tick counter
 * @range
 * @resolution 16
 * @unit       None
 */
static unsigned int leap_cnt;

/**********************************************************************************************************************
 *  HardwareInitTimerA2()
 *********************************************************************************************************************/
void HardwareInitTimerA2() {
    TA2CTL   = TASSEL_1 | ID_0 | MC_1; // ACLK, Divider 1, Up mode
    TA2CCR0  = 32;
    TA2CCTL0 = CCIE; // Enable timer interrupts
    __bis_SR_register(GIE);
}

/**********************************************************************************************************************
 *  HardwareGetTick()
 *********************************************************************************************************************/
unsigned long long int HardwareGetTick() {
    return hardware_tick;
}

/**********************************************************************************************************************
 *  Timer_A2()
 *********************************************************************************************************************/
/**
 * @brief  Generates sys_tick
 *
 * Generates sys_tick by using an interrupt service called each 1 millisecond.
 *
 * @pre    None
 * @post   None
 *
 * @param[in] pin of type pin_t with the information of the pin to be used.
 *
 * @return void
 *
 * @startuml
 * start
 * if (leap_cnt < NUM_OF_INTERRUPTS_ERROR) then (yes)
 *     :hardware_tick++;
 *     :leap_cnt++;
 * else (no)
 *     :hardware_tick += 2;
 *     :leap_cnt = 0;
 * endif
 * stop
 * @enduml
 */
#pragma vector=TIMER2_A0_VECTOR
__interrupt void Timer_A2(void) {
    if(leap_cnt < NUM_OF_INTERRUPTS_ERROR) {
        hardware_tick++;
        leap_cnt++;
    } else {
        /* Add an extra count to catch up */
        hardware_tick += 2;
        leap_cnt = 0;
    }
}

/**********************************************************************************************************************
 *  start_output_pin()
 *********************************************************************************************************************/
void start_output_pin(pin_t pin) {
    *(pin.pin_dir) |= pin.pin_bit; /* sets the bit as output */
    *(pin.pin_out) &= ~pin.pin_bit; /* starts to 0 */
}

/**********************************************************************************************************************
 *  rising_edge_pin()
 *********************************************************************************************************************/
void rising_edge_pin(pin_t pin) {
    *(pin.pin_out) |= pin.pin_bit;
}

/**********************************************************************************************************************
 *  falling_edge_pin()
 *********************************************************************************************************************/
void falling_edge_pin(pin_t pin) {
    *(pin.pin_out) &= ~pin.pin_bit;
}

/**********************************************************************************************************************
 *  low_pulse_pin()
 *********************************************************************************************************************/
void low_pulse_pin(pin_t pin) {
    *(pin.pin_out) &= ~pin.pin_bit;
    __delay_cycles(10);
    *(pin.pin_out) |= pin.pin_bit;
}
