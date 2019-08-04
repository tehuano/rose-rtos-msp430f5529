/*
 * Scheduler.h
 *
 *  Created on: 17 jul. 2019
 *      Author: Rommel
 */

#ifndef INCLUDE_SCHEDULER_H_
#define INCLUDE_SCHEDULER_H_

#include "Hardware.h"
#include "list.h"

#define STD_ON 0x01
#define STD_OFF 0x00
#define PREEMTIVE STD_ON

/* Task states */
typedef enum {
    BLOCKED,
    READY,
    RUNNING,
    ENABLED,
    DISABLED
} TaskState;

/* Task Control Block (TCB) */
typedef struct {
    /* Task Control Data */
    unsigned int id;         /* Task identifier */
    void (* pTask)(void);    /* Pointer to the task code */
    void (* pInit)(void);    /* Pointer to the init code */
    unsigned int period;     /* Task Period */
    unsigned long long int last_tick; /* Last tick task was ran   */
    unsigned int priority;   /* Task Priority */
    TaskState state;         /* ready, running, blocked  */
    pin_t led;               /* blinks a led according to the state */
    /* Task Context Data */
    void *sp;                /* stack pointer */
} TaskControlBlock_t;

/**********************************************************************************************************************
 *  Scheduler_InitTasks()
 *********************************************************************************************************************/
/*! \brief         Initialize the Tasks
 *  \details       TBD

 *  \param[in]     cryptoKeyId             Holds the identifier of the key for which a new seed shall be generated.
 *  \param[in]     entropyPtr              Holds a pointer to the memory location which contains the
 *                                         data to feed the entropy.
 *  \param[in]     entropyLength           Contains the length of the entropy in bytes.
 *  \return        E_OK                    Request successful.
 *                 E_NOT_OK                Request failed.
 *                 CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *                 CRYPTO_E_SMALL_BUFFER   Request failed, the provided buffer is too small to store the result.
 *  \pre           nothing
 *
 *  \startuml
 *    Sender->Receiver  : Command()
 *    Sender<--Receiver : Ack()
 *  \enduml
 *********************************************************************************************************************/
void Scheduler_InitTasks(void);

/**********************************************************************************************************************
 *  Scheduler_RunTasks()
 *********************************************************************************************************************/
/*! \brief         Initialize the Tasks
 *  \details       TBD

 *  \param[in]     cryptoKeyId             Holds the identifier of the key for which a new seed shall be generated.
 *  \param[in]     entropyPtr              Holds a pointer to the memory location which contains the
 *                                         data to feed the entropy.
 *  \param[in]     entropyLength           Contains the length of the entropy in bytes.
 *  \return        E_OK                    Request successful.
 *                 E_NOT_OK                Request failed.
 *                 CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *                 CRYPTO_E_SMALL_BUFFER   Request failed, the provided buffer is too small to store the result.
 *  \pre           nothing
 *
 *  \startuml
 *    Sender->Receiver  : Command()
 *    Sender<--Receiver : Ack()
 *  \enduml
 *********************************************************************************************************************/
void Scheduler_RunTasks(void);

/**********************************************************************************************************************
 *  task_state_transition()
 *********************************************************************************************************************/
/*! \brief         Initialize the Tasks
 *  \details       TBD

 *  \param[in]     task             Holds the identifier of the key for which a new seed shall be generated.
 *  \param[in]     new_state              Holds a pointer to the memory location which contains the
 *                                         data to feed the entropy.
 *  \pre           nothing
 *
 *  \startuml
 *    Sender->Receiver  : Command()
 *    Sender<--Receiver : Ack()
 *  \enduml
 *********************************************************************************************************************/
void task_state_transition(TaskControlBlock_t *task, TaskState new_state);

/**********************************************************************************************************************
 *  update_ready_list()
 *********************************************************************************************************************/
/*! \brief         Initialize the Tasks
 *  \details       TBD

 *  \param[in]     task             Holds the identifier of the key for which a new seed shall be generated.
 *  \param[in]     new_state              Holds a pointer to the memory location which contains the
 *                                         data to feed the entropy.
 *  \pre           nothing
 *
 *  \startuml
 *    Sender->Receiver  : Command()
 *    Sender<--Receiver : Ack()
 *  \enduml
 *********************************************************************************************************************/
void update_ready_list();

#endif /* INCLUDE_SCHEDULER_H_ */
