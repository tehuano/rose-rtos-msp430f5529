/*
 * Tasks.h
 *
 *  Created on: 14 jul. 2019
 *      Author: Rommel
 */

#ifndef INCLUDE_TASK_H_
#define INCLUDE_TASK_H_

/* Task states */
typedef enum {
    BLOCKED,
    READY,
    RUNNING
} TaskState;

/* Task Control Block (TCB) */
typedef struct {
    /* Task Control Data */
    TaskState state;         /* ready, running, blocked  */
    void (* pTask)(void);    /* Pointer to the task code */
    unsigned int id;         /* Task identifier          */
    unsigned int period;     /* Task Period              */
    unsigned int priority;   /* Task Priority            */
    /* Task Context Data */
    void *sp;                /* stack pointer            */
} TaskControlBlock_t;

#endif /* INCLUDE_TASK_H_ */
