/*
 * Tasks.h
 *
 *  Created on: 14 jul. 2019
 *      Author: Rommel
 */

#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

#include "Kernel.h"
#include "Task_Cfg.h"

/**********************************************************************************************************************
 *  macros used in tasks
 *********************************************************************************************************************/
#define RBIT_DELAY 500
#define NUM7       0b00000111
#define MAX_SPEED  200

/**********************************************************************************************************************
 *  macros used in log
 *********************************************************************************************************************/
#define LOG_MAX_SPEED       0
#define LOG_CRITICAL_ERROR  16


/**********************************************************************************************************************
 *  Task_5msInit()
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
void Task_5msInit(void);

/**********************************************************************************************************************
 *  Task_10msInit()
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
void Task_10msInit(void);

/**********************************************************************************************************************
 *  Task_20msInit()
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
void Task_20msInit(void);

/**********************************************************************************************************************
 *  Task_40msInit()
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
void Task_40msInit(void);

/**********************************************************************************************************************
 *  Task_80msInit()
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
void Task_80msInit(void);

/**********************************************************************************************************************
 *  Task_Aperiodic_ADCInit()
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
void Task_Aperiodic_ADCInit();

/**********************************************************************************************************************
 *  Task_Aperiodic_ButtonInit()
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
void Task_Aperiodic_ButtonInit();

/**********************************************************************************************************************
 *  Task_PeriodicServer6msInit()
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

/**********************************************************************************************************************
 *  Task_10ms()
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
void Task_10ms(void);

/**********************************************************************************************************************
 *  Task_20ms()
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
void Task_20ms(void);

/**********************************************************************************************************************
 *  Task_40ms()
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
void Task_40ms(void);

/**********************************************************************************************************************
 *  Task_80ms()
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
void Task_80ms(void);

/**********************************************************************************************************************
 *  Task_Aperiodic_ADC()
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
void Task_Aperiodic_ADC();

/**********************************************************************************************************************
 *  Task_Aperiodic_Button()
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
void Task_Aperiodic_Button();

/**********************************************************************************************************************
 *  Task_PeriodicServer6ms()
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
void Task_PeriodicServer6ms();

/**********************************************************************************************************************
 *  write_SegC()
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
void write_SegC();

void write_log(unsigned char id, void *value);

#endif /* INCLUDE_TASKS_H_ */
