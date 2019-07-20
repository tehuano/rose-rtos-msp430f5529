/*
 * Kernel.c
 *
 *  Created on: 13 jul. 2019
 *      Author: Rommel
 */

#include <msp430.h>
#include "Hardware.h"
#include "Kernel.h"
#include "Task_Cfg.h"

unsigned char KernelInitilized;

/**********************************************************************************************************************
 *  KernelRun()
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
 *  \diagram       KernelRun.png
 *********************************************************************************************************************/
void KernelRun() {
    unsigned char id = 0;
    /* Run all the tasks in this part, not scheduling implemented yet*/
    for (;;) {
        Tasks[id++].pTask();
        if ((NUMBER_OF_TASKS -1) == id) {
            id = 0;
        }
    }
}

/**********************************************************************************************************************
 *  KernelCallBack()
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
 *  \diagram       KernelCallBack.png
 *********************************************************************************************************************/
void KernelCallBack() {
    HardwareToggleP47();
}
