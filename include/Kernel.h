/** ************************************************************************************************
 * @file       Kernel.h
 * @brief      Hardware independent part of rtos TBD
 *
 * Implements the Kernel layer of the RTOS.
 *
 * @date       2019-07-01
 * $Revision: 1.0$
 * @author     Rommel García Hernández
 * @copyright  Guenda Tecnología de México
 */

#ifndef INCLUDE_KERNEL_H_
#define INCLUDE_KERNEL_H_

#include "Hardware.h"

//#define SAVE_CONTEXT()           \
//  asm volatile ( "push r4  \n\t" \
//                 "push r5  \n\t" \
//                 "push r6  \n\t" \
//                 "push r7  \n\t" \
//                 "push r8  \n\t" \
//                 "push r9  \n\t" \
//                 "push r10 \n\t" \
//                 "push r11 \n\t" \
//                 "push r12 \n\t" \
//                 "push r13 \n\t" \
//                 "push r14 \n\t" \
//                 "push r15 \n\t" \
//               );
//
//#define RESTORE_CONTEXT()       \
//  asm volatile ( "pop r15 \n\t" \
//                 "pop r14 \n\t" \
//                 "pop r13 \n\t" \
//                 "pop r12 \n\t" \
//                 "pop r11 \n\t" \
//                 "pop r10 \n\t" \
//                 "pop r9  \n\t" \
//                 "pop r8  \n\t" \
//                 "pop r7  \n\t" \
//                 "pop r6  \n\t" \
//                 "pop r5  \n\t" \
//                 "pop r4  \n\t" \
//                 "reti    \n\t" \
//               );

extern unsigned int event_vector;

/**********************************************************************************************************************
 * KernelInit()
 *********************************************************************************************************************/
/**
 * @brief  Creates the sys_tick and starts the kernel
 *
 * Creates the sys_tick and starts the kernel by calling hardware services.
 *
 * @pre    Watchdog timer is stopped
 * @post   sys_tick is enabled
 *
 * @return void
 *
 * @startuml
 *    Kernel->Hardware  : HardwareInitTimerA2()
 *    Kernel<-Kernel : Kernel_Initialized
 * @enduml
 */
void KernelInit(void);


/**********************************************************************************************************************
 * KernelRun()
 *********************************************************************************************************************/
/**
 * @brief  Calls periodically the scheduler
 *
 * Calls periodically the scheduler and initiates the tasks.
 *
 * @pre    Watchdog timer is stopped
 * @post   sys_tick is enabled
 *
 * @return void
 *
 * @startuml
 * start
 *
 * if (kernel_initilized != 0x00) then (yes)
 *   :Scheduler_InitTasks();
 *   :Enable Interrupts;
 *   while (True)
 *     :Scheduler_RunTasks();
 *   endwhile
 * else (no)
 *   :return;
 * endif
 *
 * stop
 * @enduml
 */
void KernelRun(void);

#endif /* INCLUDE_KERNEL_H_ */
