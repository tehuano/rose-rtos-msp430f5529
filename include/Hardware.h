/**
 * @file       Hardware.h
 * @brief      Hardware dependent part of rtos TBD
 *
 * Implements the hardware dependent part of the RTOS. Configures timers and interruptions.
 *
 * @date       2019-07-01
 * $Revision: 1.0$
 * @author     Rommel García-Hernández
 * @copyright  Guenda Tecnología de México
 */

#ifndef INCLUDE_HARDWARE_H_
#define INCLUDE_HARDWARE_H_

#define NUM_OF_INTERRUPTS_ERROR 141
#define TRUE 0x01
#define FALSE 0x00

/**
* A structure to represent push buttons and its output
*/
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

/**
* A structure to represent Hardware pins
*/
typedef struct {
    /* input button */
    volatile unsigned char *pin_in;
    volatile unsigned char *pin_out;
    volatile unsigned char *pin_dir;
    volatile unsigned char *pin_ren;
    unsigned char pin_bit;
} pin_t;

/**********************************************************************************************************************
 *  HardwareInitTimerA2()
 *********************************************************************************************************************/
/**
 * @brief  Creates sys tick of the RTOS
 *
 * Configures timer A2 and starts the interupt services. Starts TA2CCR0 to 32 and selects
 * ACLK, Divider 1 and Up mode.
 *
 * @pre    Watchdog timer is stopped
 * @post   None
 *
 * @return void
 *
 * @startuml
 * start
 * :TA2CTL = TASSEL_1 | ID_0 | MC_1;
 * :TA2CCR0 = 32;
 * note right
 *     Counter to obtain one millisecond delay,
 *      process requires signal to proceed
 * end note
 * :TA2CCTL0 = CCIE;
 * stop
 * @enduml
 */
void HardwareInitTimerA2();

/**********************************************************************************************************************
 *  HardwareGetTick()
 *********************************************************************************************************************/
/**
 * @brief  Returns the sys_tick value
 *
 * Returns the value of the tick counter of the system.
 *
 * @pre    sys_tick is created
 * @post   None
 *
 * @return unsigned long long int
 *
 * @startuml
 * Application -> Hardware : Request sys_tick
 * Application <- Hardware : Returns sys_tick
 * @enduml
 */
unsigned long long int HardwareGetTick();

/**********************************************************************************************************************
 *  start_output_pin()
 *********************************************************************************************************************/
/**
 * @brief  Configures a pin to work as an output
 *
 * Configures a pin to work as an output.
 *
 * @pre    Pin is referenced in pin_t pin argument
 * @post   Pin is configured as output
 *
 * @param[in] pin Struct pin_t with the information of the pin to be used.
 *
 * @return void
 *
 * @startuml
 * start
 * :pin.pin_dir[0] |= pin.pin_bit;
 * :pin.pin_out[0] &= ~pin.pin_bit;
 * stop
 * @enduml
 */
void start_output_pin(pin_t pin);


/**********************************************************************************************************************
 *  rising_edge_pin()
 *********************************************************************************************************************/
/**
 * @brief  Generates rising edge in the pin
 *
 * Generates a low to high transition in pin_t pin passed as argument.
 *
 * @pre    None
 * @post   None
 *
 * @param[in] pin of type pin_t with the information of the pin to be used.
 *
 * @return void
 *
 * @startuml
 * start
 * :pin.pin_out[0] |= pin.pin_bit;
 * stop
 * @enduml
 */
void rising_edge_pin(pin_t pin);

/**********************************************************************************************************************
 *  falling_edge_pin()
 *********************************************************************************************************************/
/**
 * @brief  Generates falling edge in the pin
 *
 * Generates a high to low transition in pin_t pin passed as argument.
 *
 * @pre    None
 * @post   None
 *
 * @param[in] pin of type pin_t with the information of the pin to be used.
 *
 * @return void
 *
 * @startuml
 * start
 * :pin.pin_out[0] &= ~pin.pin_bit;
 * stop
 * @enduml
 */
void falling_edge_pin(pin_t pin);

/**********************************************************************************************************************
 *  low_pulse_pin()
 *********************************************************************************************************************/
/**
 * @brief  Generates low pulse in the pin
 *
 * Generates a low pulse in pin_t pin passed as argument.
 *
 * @pre    None
 * @post   None
 *
 * @param[in] pin of type pin_t with the information of the pin to be used.
 *
 * @return void
 *
 * @startuml
 * start
 * :pin.pin_out[0] &= ~pin.pin_bit;
 * :__delay_cycles(10);
 * :pin.pin_out[0] |= pin.pin_bit;
 * stop
 * @enduml
 */
void low_pulse_pin(pin_t pin);

#endif /* INCLUDE_HARDWARE_H_ */
