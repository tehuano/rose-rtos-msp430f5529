/** ************************************************************************************************
 *  \file       Task_Cfg.c
 *  \brief      Hardware independent configurtion of the TCBs (source file)
 *  \date       2019-07-01
 *  \revision   $Revision: 1.0 $
 *  \author     Rommel García-Hernández
 *  \copyright  Guenda Tecnología de México
 *  Implements Hardware independent configurtion of the TCBs (source file).
 */

#include <msp430.h>
#include <stdlib.h>
#include "Tasks.h"
#include "Task_Cfg.h"

TaskControlBlock_t Tasks[NUMBER_OF_TASKS] = {
    /* id, task pointer, init ptr, period, last_tick, priority, state, stack pointer */
    {0, Task_5ms,               Task_5msInit,                5,  0, 1, READY, NULL},
    {1, Task_PeriodicServer6ms, Task_PeriodicServer6msInit,  6,  0, 2, READY, NULL},
    {2, Task_10ms,              Task_10msInit,               10, 0, 3, READY, NULL},
    {3, Task_20ms,              Task_20msInit,               20, 0, 4, READY, NULL},
    {4, Task_40ms,              Task_40msInit,               40, 0, 5, READY, NULL},
    {5, Task_80ms,              Task_80msInit,               80, 0, 6, READY, NULL}
};
