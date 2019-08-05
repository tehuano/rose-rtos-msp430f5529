/** ************************************************************************************************
 *  \file       main.c
 *  \brief      Implements the core logic of the rtos
 *  \date       2019-07-01
 *  \revision   $Revision: 1.0$
 *  \author     Rommel García Hernández
 *  \copyright  Guenda Tecnología de México
 *  Implements the core logic of the RTOS. This program calls the functions from kernel directly.
 */

#include "main.h"

/*
 * # Sistema operativo de tiempo real con las siguientes caracteristicas.
 * - Sistema Operativo Cooperativo
 * - Manejo de tareas periódicas:
 *   - 5 ms
 *   - 20 ms
 *   - 40 ms
 *   - 80 ms
 * - Manejo de tareas Aperiódicas.
 *   - Tarea de Botón presionado/liberado
 *   - Tarea valores de ADC.
 *
 * # Detalles
 * - Prioridad de tareas estáticas y definidas por el estudiante.
 * - Para cada una de las tareas el estudiante deberá asignar un pin del microcontrolador para mostrar el estado de la tarea de la siguiente manera:
 *   - Flanco de subida sencillo: cambio de Blocked a Ready.
 *   - Pulso de bajada: cambio de Ready a Start
 *   - Flanco de bajada: Cambio a Blocked.
 *
 * # Descripción de tareas
 * - Task_5ms()
 *   - Conversiones de ADC con filtrado a 8 bits
 *   - Detecciónn de estados del botón
 * - Task_10ms()
 *   - Rotabit de 8 bits con espacios entre transición de 500 ms.
 * - Task_20ms()
 *   - Variación de Intensidad de un LED en forma de señal Rampa Triangular con Periodo de 2 segundos.
 * - Task_40ms()
 *   - Controlar un servomotor dependiendo de un valor de entrada de ADC. (0 cuentas de ADC significa 45°, 255 cuentas de ADC significa 135°)
 * - Task_80ms()
 *   - Log de máxima velocidad en la ejecución
 *
 * - Tarea de Botón presionado/liberado
 *   - Cambio de estado de un LED.
 * - Tarea valores de ADC.
 *   - Si la cuenta de ADC es mayor a 200 un LED comienzan a parpadear
 */

/**********************************************************************************************************************
 *  main()
 *********************************************************************************************************************/
int main(void) {
    /* Kernel_Init */
    KernelInit();
    /* run everything by interrupts */
    KernelRun();
    return 0;
}
