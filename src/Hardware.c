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
#include "Kernel.h"

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
static unsigned long int u_Hardware_Tick;

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
    P4DIR |= BIT7;             // P4.7 como salida
    P4OUT |= BIT7;            // Apagamos al inicio P4.7
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
void HardwareInitTimerA0() {
    TA0CCTL0 = CCIE;                   /* CCR0 interrupt enabled */
    TA0CTL = TASSEL_2 | MC_1 | ID_3;   /* SMCLK/8, up mode */
    TA0CCR0  = 10000;                  /* 12.5 Hz */
    __bis_SR_register(GIE);            /* Enable maskable interrupts */
}

/**********************************************************************************************************************
 *  HardwareGetTick()
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
 *  \diagram       HardwareGetTick.png
 *********************************************************************************************************************/
unsigned long int HardwareGetTick() {
    return u_Hardware_Tick;
}

/* Timer A0 interrupt service routine */
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A0 (void)
{
    u_Hardware_Tick++;
    KernelCallBack();
}

/*
 *   Changing MAX_CNT means changing the value for TA2CCR0 0.001 s = (x + 1 ticks / 32768 Hz) MAX_CNT = x ~= 32;
 *   Thus, we would set TA2CCR0 = 32; However, the error in our elapsed time will now grow faster, so leap counting is even
 *   more important! How long until we are off by 0.001 seconds? 0.001 sec = (x interrupts)(Reported time - Actual time)
 *   Reported time = 0.001 sec Actual time = 33 / 32768 Hz = 0.00100708 sec This is greater than 0.001 sec,
 *   so clock is running slow! (ie, more time has elapsed than what we assume has elapsed.) 0.001 s = (x interrupts)*(0.001s - (33/32768)) x = 141
 *   interrupts, or ~ 141 ms! Thus, our timer wouldn't stay accurate for long! Here is how we can add a leap count for this example:
 *   #pragma vector=TIMER2_A0_VECTOR __interrupt void TIMER_A2_ISR(void) { // timer and leap_cnt are global unsigned integers
 *   // *** leap_cnt counts the number of intervals until we need // to add a leap count *** if(leap_cnt < 141) { timer++; leap_cnt++; }
 *   else { timer += 2; // Add an extra count to catch up leap_cnt = 0; } }
 * */
