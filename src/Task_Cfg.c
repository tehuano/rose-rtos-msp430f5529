/** ************************************************************************************************
 * @file       Task_Cfg.c
 * @brief      Hardware independent configurtion of the TCBs (source file)
 * @date       2019-07-01
 * @revision   $Revision: 1.0 $
 * @author     Rommel García-Hernández
 * @copyright  Guenda Tecnología de México
 *  Implements Hardware independent configurtion of the TCBs (source file).
 */

#include <msp430.h>
#include <stdlib.h>
#include "Tasks.h"
#include "Task_Cfg.h"

TaskControlBlock_t Tasks[NUMBER_OF_TASKS] = {
    /* id, task pointer,        init ptr,               period, last_tick, priority, state, state pin, stack pointer */
    {0, Task_5ms,               Task_5msInit,                5,  0, 1, BLOCKED, {&P6IN,&P6OUT,&P6DIR,&P6REN,BIT1}, NULL},
    {1, Task_PeriodicServer6ms, Task_PeriodicServer6msInit,  6,  0, 2, BLOCKED, {&P6IN,&P6OUT,&P6DIR,&P6REN,BIT2}, NULL},
    {2, Task_10ms,              Task_10msInit,               10, 0, 3, BLOCKED, {&P6IN,&P6OUT,&P6DIR,&P6REN,BIT3}, NULL},
    {3, Task_20ms,              Task_20msInit,               20, 0, 4, BLOCKED, {&P6IN,&P6OUT,&P6DIR,&P6REN,BIT4}, NULL},
    {4, Task_40ms,              Task_40msInit,               40, 0, 5, BLOCKED, {&P6IN,&P6OUT,&P6DIR,&P6REN,BIT5}, NULL},
    {5, Task_80ms,              Task_80msInit,               80, 0, 6, BLOCKED, {&P6IN,&P6OUT,&P6DIR,&P6REN,BIT6}, NULL}
};

/* Array of nodes of id tasks */
node_t tasks_ids[NUMBER_OF_TASKS] = {
    {0, NULL, NULL},
    {1, NULL, NULL},
    {2, NULL, NULL},
    {3, NULL, NULL},
    {4, NULL, NULL},
    {5, NULL, NULL},
};

list_t ready_list = {NULL, NULL};

