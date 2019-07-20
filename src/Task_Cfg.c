/*
 * Task_Cfg.c
 *
 *  Created on: 14 jul. 2019
 *      Author: Rommel
 */

#include <msp430.h>
#include <stdlib.h>
#include "Task.h"
#include "Behavior.h"
#include "Task_Cfg.h"

const TaskControlBlock_t Tasks[NUMBER_OF_TASKS] = {
    /* state, task pointer, identifier, period, priority, stack pointer */
    {READY, task1, 0,  5, 2, NULL},
    {READY, task2, 0, 10, 3, NULL},
    {READY, task3, 0,  3, 1, NULL}
};
