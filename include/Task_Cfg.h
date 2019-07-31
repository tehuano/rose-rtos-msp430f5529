/** ************************************************************************************************
 *  \file       Task_Cfg.h
 *  \brief      Hardware independent configurtion of the TCBs (header file)
 *  \date       2019-07-01
 *  \revision   $Revision: 1.0 $
 *  \author     Rommel García-Hernández
 *  \copyright  Guenda Tecnología de México
 *  Implements the hardware independent part of the the ECC selftest for all processor platforms.
 */

#ifndef INCLUDE_TASK_CFG_H_
#define INCLUDE_TASK_CFG_H_

#include "Scheduler.h"

#define NUMBER_OF_TASKS 6
#define FLASH_WRITE_EVENT 0b0000000000100000

extern TaskControlBlock_t Tasks[NUMBER_OF_TASKS];

#endif /* INCLUDE_TASK_CFG_H_ */
