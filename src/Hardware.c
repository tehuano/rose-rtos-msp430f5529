/** ************************************************************************************************
 *  \file       Hardware.c
 *
 *  \brief      Hardware independent part of the ECC hardware selftest (header file)
 *
 *  \date       2015-08-03
 *  \revision   $Revision: 1.5 $
 *  \author     Andreas Menge (uidg4118)
 *  \copyright  Continental Automotive 2015
 *
 *  Implements the hardware independent part of the the ECC selftest for all processor platforms.
 */

#include <msp430.h>
#include "Hardware.h"

/** **********************************************************************************************
 *  \brief  ECC test structure
 *
 *  Flags array to indicate if ECC test is running and what the result of the test is. This
 *  array is used to pass information between interrupt and normal program mode during ECC
 *  self test. Each core has its own structure in this array.
 *
 *  \range      see enumeration FS_Ecc_t_TestResults
 *  \resolution 1
 *  \unit       None
 */
static unsigned long long int hardware_tick;
static unsigned int leap_cnt;

/**********************************************************************************************************************
 *  HardwareInitIO()
 *********************************************************************************************************************/
/*! \brief         Initialize the seed
 *  \details       This function generates the internal seed state using the provided entropy source.
 *                 Furthermore, this function can be used to update the seed state with new entropy
 *  \param[in]     cryptoKeyId             Holds the identifier of the key for which a new seed shall be generated.
 *  \param[in]     entropyPtr              Holds a pointer to the memory location which contains the
 *                                         data to feed the entropy.
 *  \param[in]     entropyLength           Contains the length of the entropy in bytes.
 *  \return        E_OK                    Request successful.
 *                 E_NOT_OK                Request failed.
 *                 CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *                 CRYPTO_E_SMALL_BUFFER   Request failed, the provided buffer is too small to store the result.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \diagram       HardwareInitIO.png
 *********************************************************************************************************************/
void HardwareInitIO() {

}

/**********************************************************************************************************************
 *  HardwareToggleP47()
 *********************************************************************************************************************/
/*! \brief         Initialize the seed
 *  \details       This function generates the internal seed state using the provided entropy source.
 *                 Furthermore, this function can be used to update the seed state with new entropy
 *  \param[in]     cryptoKeyId             Holds the identifier of the key for which a new seed shall be generated.
 *  \param[in]     entropyPtr              Holds a pointer to the memory location which contains the
 *                                         data to feed the entropy.
 *  \param[in]     entropyLength           Contains the length of the entropy in bytes.
 *  \return        E_OK                    Request successful.
 *                 E_NOT_OK                Request failed.
 *                 CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *                 CRYPTO_E_SMALL_BUFFER   Request failed, the provided buffer is too small to store the result.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \diagram       HardwareToggleP47.png
 *********************************************************************************************************************/
void HardwareToggleP47() {
    P4OUT ^= BIT7;           /* Toggle P4.7 */
}

/**********************************************************************************************************************
 *  HardwareInitTimerA0()
 *********************************************************************************************************************/
/*! \brief         Initialize the seed
 *  \details       This function generates the internal seed state using the provided entropy source.
 *                 Furthermore, this function can be used to update the seed state with new entropy
 *  \param[in]     cryptoKeyId             Holds the identifier of the key for which a new seed shall be generated.
 *  \param[in]     entropyPtr              Holds a pointer to the memory location which contains the
 *                                         data to feed the entropy.
 *  \param[in]     entropyLength           Contains the length of the entropy in bytes.
 *  \return        E_OK                    Request successful.
 *                 E_NOT_OK                Request failed.
 *                 CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *                 CRYPTO_E_SMALL_BUFFER   Request failed, the provided buffer is too small to store the result.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \diagram       HardwareInitTimerA0.png
 *********************************************************************************************************************/
void HardwareInitTimerA2() {
//   TA2CTL   = TASSEL_2 + ID_0 + MC_1; /* Using SMCLK */
//   TA2CCR0  = 104; /* 1.048576 MHz */
//   TA2CCTL0 = CCIE; /* Enable timer interrupts */
    TA2CTL   = TASSEL_1 | ID_0 | MC_1; // ACLK, Divider 1, Up mode
    TA2CCR0  = 32;
    TA2CCTL0 = CCIE; // Enable timer interrupts
    __bis_SR_register(GIE);
}

unsigned long long int HardwareGetTick() {
    return hardware_tick;
}

/* Timer A2 interrupt service routine */
#pragma vector=TIMER2_A0_VECTOR
__interrupt void Timer_A2 (void) {
    if(leap_cnt < NUM_OF_INTERRUPTS_ERROR) {
        hardware_tick++;
        leap_cnt++;
    } else {
        /* Add an extra count to catch up */
        hardware_tick += 2;
        leap_cnt = 0;
    }
}

void start_output_pin(pin_t pin) {
    *(pin.pin_dir) |= pin.pin_bit; /* sets the bit as output */
    *(pin.pin_out) &= ~pin.pin_bit; /* starts to 0 */
}

void rising_edge_pin(pin_t pin) {
    *(pin.pin_out) |= pin.pin_bit;
}

void falling_edge_pin(pin_t pin) {
    *(pin.pin_out) &= ~pin.pin_bit;
}

void low_pulse_pin(pin_t pin) {
    *(pin.pin_out) &= ~pin.pin_bit;
    __delay_cycles(10);
    *(pin.pin_out) |= pin.pin_bit;
}
