/** ************************************************************************************************
 *  \file       Hardware.h
 *
 *  \brief      Hardware independent part of the ECC hardware selftest (header file)
 *
 *  \date       2015-08-03
 *  \revision   $Revision: 1.5 $
 *  \author     Andreas Menge (uidg4118)
 *  \copyright  Continental Automotive 2015
 *
 *  Implements the hardware independent part of the the ECC selftest for all processor platforms.
 */

#ifndef INCLUDE_HARDWARE_H_
#define INCLUDE_HARDWARE_H_

void HardwareInitIO();
void HardwareToggleP47();
void HardwareInitTimerA0();

#endif /* INCLUDE_HARDWARE_H_ */
