/** ************************************************************************************************
 *  \file       Hardware.h
 *
 *  \brief      Hardware independent part of the ECC hardware selftest (header file)
 *
 *  \date       2015-08-03
 *  \revision   $Revision: 1.5 $
 *  \author     Rommel García-Hernández
 *  \copyright  Guenda Tecnología de México
 *
 *  Implements the hardware independent part of the the ECC selftest for all processor platforms.
 */

#ifndef INCLUDE_HARDWARE_H_
#define INCLUDE_HARDWARE_H_

#define NUM_OF_INTERRUPTS_ERROR 141
#define TRUE 0x01
#define FALSE 0x00

void HardwareInitIO();
void HardwareToggleP47();
void HardwareInitTimerA2();
unsigned long long int HardwareGetTick();

#endif /* INCLUDE_HARDWARE_H_ */
