/** ************************************************************************************************
 *  \file       Hardware.h
 *
 *  \brief      Hardware independent part of rtos TBD
 *
 *  \date       2015-08-03
 *  \revision   $Revision: 1.5 $
 *  \author     Rommel Garc�a-Hern�ndez
 *  \copyright  Guenda Tecnolog�a de M�xico
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
/*! \brief         Initialize the seed
 *  \details       TBD

 *  \param[in]     cryptoKeyId             Holds the identifier of the key for which a new seed shall be generated.
 *  \param[in]     entropyPtr              Holds a pointer to the memory location which contains the
 *                                         data to feed the entropy.
 *  \param[in]     entropyLength           Contains the length of the entropy in bytes.
 *  \return        E_OK                    Request successful.
 *                 E_NOT_OK                Request failed.
 *                 CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *                 CRYPTO_E_SMALL_BUFFER   Request failed, the provided buffer is too small to store the result.
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
/*! \brief         Initialize the seed
 *  \details       TBD

 *  \param[in]     cryptoKeyId             Holds the identifier of the key for which a new seed shall be generated.
 *  \param[in]     entropyPtr              Holds a pointer to the memory location which contains the
 *                                         data to feed the entropy.
 *  \param[in]     entropyLength           Contains the length of the entropy in bytes.
 *  \return        E_OK                    Request successful.
 *                 E_NOT_OK                Request failed.
 *                 CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *                 CRYPTO_E_SMALL_BUFFER   Request failed, the provided buffer is too small to store the result.
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
/*! \brief         Initialize the seed
 *  \details       TBD

 *  \param[in]     cryptoKeyId             Holds the identifier of the key for which a new seed shall be generated.
 *  \param[in]     entropyPtr              Holds a pointer to the memory location which contains the
 *                                         data to feed the entropy.
 *  \param[in]     entropyLength           Contains the length of the entropy in bytes.
 *  \return        E_OK                    Request successful.
 *                 E_NOT_OK                Request failed.
 *                 CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *                 CRYPTO_E_SMALL_BUFFER   Request failed, the provided buffer is too small to store the result.
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
/*! \brief         Initialize the seed
 *  \details       TBD

 *  \param[in]     cryptoKeyId             Holds the identifier of the key for which a new seed shall be generated.
 *  \param[in]     entropyPtr              Holds a pointer to the memory location which contains the
 *                                         data to feed the entropy.
 *  \param[in]     entropyLength           Contains the length of the entropy in bytes.
 *  \return        E_OK                    Request successful.
 *                 E_NOT_OK                Request failed.
 *                 CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *                 CRYPTO_E_SMALL_BUFFER   Request failed, the provided buffer is too small to store the result.
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
/*! \brief         Initialize the seed
 *  \details       TBD

 *  \param[in]     cryptoKeyId             Holds the identifier of the key for which a new seed shall be generated.
 *  \param[in]     entropyPtr              Holds a pointer to the memory location which contains the
 *                                         data to feed the entropy.
 *  \param[in]     entropyLength           Contains the length of the entropy in bytes.
 *  \return        E_OK                    Request successful.
 *                 E_NOT_OK                Request failed.
 *                 CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *                 CRYPTO_E_SMALL_BUFFER   Request failed, the provided buffer is too small to store the result.
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
/*! \brief         Initialize the seed
 *  \details       TBD

 *  \param[in]     cryptoKeyId             Holds the identifier of the key for which a new seed shall be generated.
 *  \param[in]     entropyPtr              Holds a pointer to the memory location which contains the
 *                                         data to feed the entropy.
 *  \param[in]     entropyLength           Contains the length of the entropy in bytes.
 *  \return        E_OK                    Request successful.
 *                 E_NOT_OK                Request failed.
 *                 CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *                 CRYPTO_E_SMALL_BUFFER   Request failed, the provided buffer is too small to store the result.
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
/*! \brief         Initialize the seed
 *  \details       TBD

 *  \param[in]     cryptoKeyId             Holds the identifier of the key for which a new seed shall be generated.
 *  \param[in]     entropyPtr              Holds a pointer to the memory location which contains the
 *                                         data to feed the entropy.
 *  \param[in]     entropyLength           Contains the length of the entropy in bytes.
 *  \return        E_OK                    Request successful.
 *                 E_NOT_OK                Request failed.
 *                 CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *                 CRYPTO_E_SMALL_BUFFER   Request failed, the provided buffer is too small to store the result.
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
/*! \brief         Initialize the seed
 *  \details       TBD

 *  \param[in]     cryptoKeyId             Holds the identifier of the key for which a new seed shall be generated.
 *  \param[in]     entropyPtr              Holds a pointer to the memory location which contains the
 *                                         data to feed the entropy.
 *  \param[in]     entropyLength           Contains the length of the entropy in bytes.
 *  \return        E_OK                    Request successful.
 *                 E_NOT_OK                Request failed.
 *                 CRYPTO_E_BUSY           Request failed, Crypto Driver Object is busy.
 *                 CRYPTO_E_SMALL_BUFFER   Request failed, the provided buffer is too small to store the result.
 *  \pre           -
 *  \context       TASK
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \diagram       HardwareGetTick.png
 *********************************************************************************************************************/
void low_pulse_pin(pin_t pin);

#endif /* INCLUDE_HARDWARE_H_ */
