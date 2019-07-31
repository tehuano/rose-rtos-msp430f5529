/** ************************************************************************************************
 *  \file       Scheduler.c
 *  \brief      Hardware independent part of the ECC hardware selftest (header file)
 *  \date       2015-08-03
 *  \revision   $Revision: 1.5 $
 *  \author     Andreas Menge (uidg4118)
 *  \copyright  Guenda Tecnología de México
 *  Implements the hardware independent part of the the ECC selftest for all processor platforms.
 */

#include "Task_Cfg.h"
#include "Hardware.h"
#include "Scheduler.h"

void Scheduler_InitTasks() {
    unsigned char idx = 0;
    for (idx = 0; idx < NUMBER_OF_TASKS; idx++) {
        if (Tasks[idx].state != DISABLED) {
            Tasks[idx].pInit();
        }
    }
}

unsigned long long int ci_time = 0;

void Scheduler_RunTasks() {
    unsigned char idx = 0;
    unsigned long long int sys_tick = 0;
    unsigned long long int elapsed_time = 0;
    unsigned long long int start_time = 0;
    /* run all the tasks if the elapsed time is >= than the tasks period*/
    for (idx = 0; idx < NUMBER_OF_TASKS; idx++) {
        sys_tick = HardwareGetTick();
        elapsed_time = sys_tick - Tasks[idx].last_tick;
        if (elapsed_time >= Tasks[idx].period || 0 == Tasks[idx].last_tick) {
            if (Tasks[idx].state == READY) {
                start_time = HardwareGetTick();
                Tasks[idx].pTask();
                ci_time = HardwareGetTick() - start_time;
            }
            Tasks[idx].last_tick = sys_tick;
        }
    }
}
