/** ************************************************************************************************
 * @file       Kernel.c
 * @brief      Implementation RTOS Kernel logic (source file)
 * @date       2019-07-01
 * @revision   $Revision: 1.0$
 * @author     Rommel García Hernández
 * @copyright  Guenda Tecnología de México
 *  Implements funtionality of RTOS kernel, scheduler and hw invocations.
 */

#include <msp430.h>
#include "Kernel.h"
#include "Scheduler.h"

unsigned int event_vector; /* event vector, used to pass info among tasks */
static unsigned char kernel_initilized = 0x00; /* Kernel is initialized */

/**********************************************************************************************************************
 *  KernelInit()
 *********************************************************************************************************************/
void KernelInit() {
    WDTCTL = WDTPW | WDTHOLD;   /* stop watchdog timer */
    HardwareInitTimerA2();      /* Initialize the timer module */
    kernel_initilized = 0x01;   /* now kernel is initilized */
}

/**********************************************************************************************************************
 *  KernelRun()
 *********************************************************************************************************************/
void KernelRun() {
    /* first check is kernel was initialized properly */
    if (0x00 == kernel_initilized) {
        return;
    }
    /* Kernel init tasks */
    Scheduler_InitTasks();
    __bis_SR_register(GIE); /* Enable maskable interrupts */
    /* Run all the tasks in this part, not scheduling implemented yet */
    for (;;) {
        Scheduler_RunTasks();
    }
}
