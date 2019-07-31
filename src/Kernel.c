/*
 * Kernel.c
 *
 *  Created on: 13 jul. 2019
 *      Author: Rommel
 */

#include <msp430.h>
#include "Hardware.h"
#include "Kernel.h"
#include "Task_Cfg.h"

unsigned int event_vector;
static unsigned char kernel_initilized = 0x00;
//unsigned long int sys_tick = 0;

void KernelInit() {
    WDTCTL = WDTPW | WDTHOLD;   /* stop watchdog timer */
    HardwareInitIO();           /* Initialize io */
    HardwareInitTimerA2();      /* Initialize the timer module */
    kernel_initilized = 0x01;
}

void KernelRun() {
    if (kernel_initilized == 0x00) {
        return;
    }
    /* Kernel init tasks */
    Scheduler_InitTasks();
    __bis_SR_register(GIE); /* Enable maskable interrupts */
    /* Run all the tasks in this part, not scheduling implemented yet */
    for (;;) {
        Scheduler_RunTasks();
    }
}
