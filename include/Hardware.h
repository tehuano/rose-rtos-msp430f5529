/** ************************************************************************************************
 *  \file       Hardware.h
 *
 *  \brief      Hardware independent part of rtos TBD
 *
 *  \date       2019-07-01
 *  \revision   $Revision: 1.0$
 *  \author     Rommel García-Hernández
 *  \copyright  Guenda Tecnología de México
 *
 *  Implements the hardware independent part of the rtos TBD
 */

#ifndef INCLUDE_HARDWARE_H_
#define INCLUDE_HARDWARE_H_

#define NUM_OF_INTERRUPTS_ERROR 141
#define TRUE 0x01
#define FALSE 0x00

typedef struct {
    /* input button */
    volatile unsigned char *p_in;
    volatile unsigned char *p_in_dir;
    volatile unsigned char *p_in_ren;
    volatile unsigned char *p_in_pull;
    unsigned char b_in;
    /* output related to the button */
    volatile unsigned char *p_out;
    volatile unsigned char *p_out_dir;
    unsigned char b_out;
    unsigned char state;
    unsigned char counter;
} button_t;

typedef struct {
    /* input button */
    volatile unsigned char *pin_in;
    volatile unsigned char *pin_out;
    volatile unsigned char *pin_dir;
    volatile unsigned char *pin_ren;
    unsigned char pin_bit;
} pin_t;

/**********************************************************************************************************************
 *  HardwareInitIO()
 *********************************************************************************************************************/
/*! \brief         TBD
 *  \details       TBD

 *  \param[in]     TBD                       TBD



 *  \return        TBD


 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \diagram       HardwareGetTick.png
 *********************************************************************************************************************/
void HardwareInitIO();

/**********************************************************************************************************************
 *  HardwareToggleP47()
 *********************************************************************************************************************/
/*! \brief         TBD
 *  \details       TBD

 *  \param[in]     TBD                       TBD



 *  \return        TBD


 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \diagram       HardwareGetTick.png
 *********************************************************************************************************************/
void HardwareToggleP47();

/**********************************************************************************************************************
 *  HardwareInitTimerA2()
 *********************************************************************************************************************/
/*! \brief         TBD
 *  \details       TBD

 *  \param[in]     TBD                       TBD



 *  \return        TBD


 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \diagram       HardwareGetTick.png
 *********************************************************************************************************************/
void HardwareInitTimerA2();

/**********************************************************************************************************************
 *  HardwareGetTick()
 *********************************************************************************************************************/
/*! \brief         TBD
 *  \details       TBD

 *  \param[in]     TBD                       TBD



 *  \return        TBD


 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \diagram       HardwareGetTick.png
 *********************************************************************************************************************/
unsigned long long int HardwareGetTick();

/**********************************************************************************************************************
 *  start_output_pin()
 *********************************************************************************************************************/
/*! \brief         TBD
 *  \details       TBD

 *  \param[in]     TBD                       TBD



 *  \return        TBD


 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \diagram       HardwareGetTick.png
 *********************************************************************************************************************/
void start_output_pin(pin_t pin);


/**********************************************************************************************************************
 *  HardwareGetTick()
 *********************************************************************************************************************/
/*! \brief         TBD
 *  \details       TBD

 *  \param[in]     TBD                       TBD



 *  \return        TBD


 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \diagram       HardwareGetTick.png
 *********************************************************************************************************************/
void rising_edge_pin(pin_t pin);

/**********************************************************************************************************************
 *  falling_edge_pin()
 *********************************************************************************************************************/
/*! \brief         TBD
 *  \details       TBD

 *  \param[in]     TBD                       TBD



 *  \return        TBD


 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \diagram       HardwareGetTick.png
 *********************************************************************************************************************/
void falling_edge_pin(pin_t pin);

/**********************************************************************************************************************
 *  low_pulse_pin()
 *********************************************************************************************************************/
/*! \brief         TBD
 *  \details       TBD

 *  \param[in]     TBD                       TBD



 *  \return        TBD


 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \diagram       HardwareGetTick.png
 *********************************************************************************************************************/
void low_pulse_pin(pin_t pin);

#endif /* INCLUDE_HARDWARE_H_ */
