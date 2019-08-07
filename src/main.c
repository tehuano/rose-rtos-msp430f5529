/** ************************************************************************************************
 * @file       main.c
 * @brief      Implements the core logic of the rtos
 *
 * Implements the core logic of the RTOS. This program calls the functions from kernel directly.
 *
 * @date       2019-07-01
 * $Revision: 1.0$
 * @author     Rommel García Hernández
 * @copyright  Guenda Tecnología de México
 */

#include "main.h"

/**********************************************************************************************************************
 *  main()
 *********************************************************************************************************************/
/**
 * @brief  Main function
 *
 *  Main function, calls the KernelInit function and KernelRun.
 *
 * @pre    None
 * @post   None
 *
 * @return void
 *
 * @startuml
 * start
 *   :KernelInit();
 *   :KernelRun();
 * stop
 * @enduml
 */
int main(void) {
    /* Kernel_Init */
    KernelInit();
    /* run everything by interrupts */
    KernelRun();
    return 0;
}
