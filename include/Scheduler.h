/** ************************************************************************************************
 * @file       Scheduler.h
 * @brief      Hardware independent scheduler
 *
 * Hardware independent scheduler. Implements a non-preemptive scheduler.
 *
 * @date       2019-07-01
 * @revision   $Revision: 1.0$
 * @author     Rommel García Hernández
 * @copyright  Guenda Tecnología de México
 */

#ifndef INCLUDE_SCHEDULER_H_
#define INCLUDE_SCHEDULER_H_

#include "Hardware.h"
#include "list.h"

#define STD_ON 0x01
#define STD_OFF 0x00
#define PREEMTIVE STD_ON

/**
 * Task states
 */
typedef enum {
    BLOCKED,
    READY,
    RUNNING,
    ENABLED,
    DISABLED
} TaskState;

/**
 *  Task Control Block (TCB)
 */
typedef struct {
    /** Task Control Data */
    unsigned int id;         /** Task identifier */
    void (* pTask)(void);    /** Pointer to the task code */
    void (* pInit)(void);    /** Pointer to the init code */
    unsigned int period;     /** Task Period */
    unsigned long long int last_tick; /** Last tick task was ran   */
    unsigned int priority;   /** Task Priority */
    TaskState state;         /** ready, running, blocked  */
    pin_t led;               /** blinks a led according to the state */
    /** Task Context Data */
    void *sp;                /** stack pointer */
} TaskControlBlock_t;

/**********************************************************************************************************************
 *  Scheduler_InitTasks()
 *********************************************************************************************************************/
/**
 * @brief  Runs the init functions of all enabled tasks.
 *
 * Performs all the init functions that are defined for the tasks in configuration.
 *
 * @pre    sys_tick enabled
 * @post   Ready Tasks are able to run
 *
 * @return void
 *
 *
 * @startuml
 *
 * start
 *   repeat
 *   if (Tasks[idx].state != DISABLE) then (yes)
 *     :Tasks[idx].Init();
 *     :start_output_pin(Tasks[idx].pin);
 *   endif
 *   repeat while (idx < NUMBER_OF_TASKS) is (yes)
 *   ->no;
 *   :tasks_init_done = TRUE;
 * stop
 *
 * @enduml
 */
void Scheduler_InitTasks(void);

/**********************************************************************************************************************
 *  Scheduler_RunTasks()
 *********************************************************************************************************************/
/**
 * @brief  Configures a pin to work as an output
 *
 * Serializes the tasks to prevent conflicts accessing the same hardware resource.
 * The task isn't started until it is in 'ready' state.
 *
 * @pre    Pin is referenced in pin_t pin argument
 * @post   Pin is configured as output
 *
 * @param[in] pin Struct pin_t with the information of the pin to be used.
 *
 * @return void
 *
 * @startuml
 *
 * start
 * :update_ready_list();
 * while ((task = dequeue(&ready_list)) != NULL)
 *   :start_time = HardwareGetTick();
 *   :task_state_transition(&Tasks[task->id], RUNNING);
 *   :Tasks[task->id].pTask();
 *   :task_state_transition(&Tasks[task->id], BLOCKED);
 *   :ci_time = HardwareGetTick() - start_time;
 * endwhile
 *
 * stop
 *
 * @enduml
 */
void Scheduler_RunTasks(void);

/**********************************************************************************************************************
 *  task_state_transition()
 *********************************************************************************************************************/
/**
 * @brief  Generates a state transition of the task
 *
 * Generates a state transition of the task.
 *
 * @pre    Task was analyzed by the scheduler
 * @post   Task in new state
 *
 * @param[in] task of type TaskControlBlock_t* with the information TCB
 * @param[in] new_state of type TaskState with the information state to transition
 *
 * @return void
 *
 * @startuml
 * start
 *
 *   if (conditions correct) then (yes)
 *     :Tasks.state = new_state;
 *   endif
 *
 * stop
 * @enduml
 */
void task_state_transition(TaskControlBlock_t *task, TaskState new_state);

/**********************************************************************************************************************
 *  update_ready_list()
 *********************************************************************************************************************/
/**
 * @brief  Update all the ready list
 *
 * Updates all the ready list depending on the period time of the tasks
 *
 * @pre    Task was analyzed by the scheduler
 * @post   Task in new state
 *
 * @param[in] task of type TaskControlBlock_t* with the information TCB
 * @param[in] new_state of type TaskState with the information state to transition
 *
 * @return void
 *
 * @startuml
 *
 * start
 *   repeat
 *   if (is_ready(Tasks[idx])) then (yes)
 *     :task_state_transition(Tasks[idx], READY);
 *     :enqueue(&ready_list,&Tasks[idx]);
 *   endif
 *   repeat while (idx < NUMBER_OF_TASKS) is (yes)
 *   ->no;
 * stop
 *
 * @enduml
 */
void update_ready_list();

#endif /* INCLUDE_SCHEDULER_H_ */
