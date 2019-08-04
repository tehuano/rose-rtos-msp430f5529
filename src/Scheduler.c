/** ************************************************************************************************
 *  \file       Scheduler.c
 *  \brief      Hardware independent part of rtos TBD
 *  \date       2019-07-01
 *  \revision   $Revision: 1.0$
 *  \author     Rommel García Hernández
 *  \copyright  Guenda Tecnología de México
 *  Implements the hardware independent part of the rtos TBD
 */

#include "Task_Cfg.h"
#include "Hardware.h"
#include "Scheduler.h"

unsigned long long int ci_time = 0;
unsigned char tasks_init_done = FALSE;

void Scheduler_InitTasks() {
    unsigned char idx = 0;
    for (idx = 0; idx < NUMBER_OF_TASKS; idx++) {
        if (Tasks[idx].state != DISABLED) {
            Tasks[idx].pInit();
            start_output_pin(Tasks[idx].led);
        }
    }
    tasks_init_done = TRUE;
}

void Scheduler_RunTasks() {
    unsigned long long int start_time = 0;
    node_t *task = NULL;
    update_ready_list();
    /* run all the tasks if the elapsed time is >= than the tasks period*/
    while ((task = dequeue(&ready_list)) != NULL) {
        start_time = HardwareGetTick();
        task_state_transition(&Tasks[task->id], RUNNING);
        Tasks[task->id].pTask();
        task_state_transition(&Tasks[task->id], BLOCKED);
        ci_time = HardwareGetTick() - start_time;
        //Tasks[task->id].last_tick = start_time;
    }
}

void task_state_transition(TaskControlBlock_t *task, TaskState new_state) {
    if (!task) return;
    switch(task->state) {
        case BLOCKED:
            if (new_state == READY) {
                task->state = new_state;
                rising_edge_pin(task->led);
            }
        break;
        case READY:
            if (new_state == RUNNING) {
                task->state = new_state;
                low_pulse_pin(task->led);
            }
        break;
        case RUNNING:
            if (new_state == BLOCKED) {
                task->state = new_state;
                falling_edge_pin(task->led);
            }
        break;
        default:
            task->state = READY;
    }
}

void update_ready_list() {
    unsigned int idx = 0;
    unsigned long long int sys_tick = 0;
    unsigned long long int elapsed_time = 0;
    /* update all the tasks if the elapsed time is >= than the tasks period*/
    sys_tick = HardwareGetTick();
    for (idx = 0; idx < NUMBER_OF_TASKS; idx++) {
        elapsed_time = sys_tick - Tasks[idx].last_tick;
        if ((elapsed_time >= Tasks[idx].period || 0 == Tasks[idx].last_tick) && BLOCKED == Tasks[idx].state) {
            Tasks[idx].last_tick = sys_tick;
            task_state_transition(&Tasks[idx], READY);
            enqueue(&ready_list,&tasks_ids[idx]);
        }
    }
}
