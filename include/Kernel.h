/** ************************************************************************************************
 *  \file       Kernel.h
 *  \brief      Hardware independent part of rtos TBD
 *  \date       2019-07-01
 *  \revision   $Revision: 1.0$
 *  \author     Rommel García Hernández
 *  \copyright  Guenda Tecnología de México 2015
 *  Implements the hardware independent part of the rtos TBD
 */

#ifndef INCLUDE_KERNEL_H_
#define INCLUDE_KERNEL_H_

#define SAVE_CONTEXT()           \
  asm volatile ( "push r4  \n\t" \
                 "push r5  \n\t" \
                 "push r6  \n\t" \
                 "push r7  \n\t" \
                 "push r8  \n\t" \
                 "push r9  \n\t" \
                 "push r10 \n\t" \
                 "push r11 \n\t" \
                 "push r12 \n\t" \
                 "push r13 \n\t" \
                 "push r14 \n\t" \
                 "push r15 \n\t" \
               );

#define RESTORE_CONTEXT()       \
  asm volatile ( "pop r15 \n\t" \
                 "pop r14 \n\t" \
                 "pop r13 \n\t" \
                 "pop r12 \n\t" \
                 "pop r11 \n\t" \
                 "pop r10 \n\t" \
                 "pop r9  \n\t" \
                 "pop r8  \n\t" \
                 "pop r7  \n\t" \
                 "pop r6  \n\t" \
                 "pop r5  \n\t" \
                 "pop r4  \n\t" \
                 "reti    \n\t" \
               );

extern unsigned int event_vector;

/**********************************************************************************************************************
 *  KernelInit()
 *********************************************************************************************************************/
/*! \brief         TBD
 *  \details       TBD

 *  \param[in]     TBD                       TBD



 *  \return        TBD


 *  \pre           nothing
 *
 *  \startuml
 *    Sender->Receiver  : Command()
 *    Sender<--Receiver : Ack()
 *  \enduml
 *********************************************************************************************************************/
void KernelInit(void);


/**********************************************************************************************************************
 *  KernelRun()
 *********************************************************************************************************************/
/*! \brief         TBD
 *  \details       TBD

 *  \param[in]     TBD                       TBD



 *  \return        TBD


 *  \pre           nothing
 *
 *  \startuml
 *    Sender->Receiver  : Command()
 *    Sender<--Receiver : Ack()
 *  \enduml
 *********************************************************************************************************************/
void KernelRun(void);

#endif /* INCLUDE_KERNEL_H_ */
