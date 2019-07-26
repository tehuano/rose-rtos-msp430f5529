/*
 * Tasks.h
 *
 *  Created on: 14 jul. 2019
 *      Author: Rommel
 */

#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

#define RBIT_DELAY 500
#define NUM7       0b00000111

void Task_5msInit(void);
void Task_10msInit(void);
void Task_20msInit(void);
void Task_40msInit(void);
void Task_80msInit(void);
void Task_Aperiodic_ADCInit();
void Task_Aperiodic_ButtonInit();
void Task_PeriodicServer6msInit();


/**********************************************************************************************************************
 *  Task_5ms()
 *********************************************************************************************************************/
/*! \brief         Conversiones de ADC con filtrado a 8 bits. Detecciónn de estados del botón.
 *  \details       This function generates  Conversiones de ADC con filtrado a 8 bits. Detecciónn de estados del botón.
 *  \param[in]     void
 *  \return        void
 *  \pre           nothing
 *
 *  \startuml
 *    Sender->Receiver  : Command()
 *    Sender<--Receiver : Ack()
 *  \enduml
 *********************************************************************************************************************/
void Task_5ms(void);
void Task_10ms(void);
void Task_20ms(void);
void Task_40ms(void);
void Task_80ms(void);
void Task_Aperiodic_ADC();
void Task_Aperiodic_Button();
void Task_PeriodicServer6ms();

#endif /* INCLUDE_TASKS_H_ */
