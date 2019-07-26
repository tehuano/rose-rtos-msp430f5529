/** ************************************************************************************************
 *  \file       main.c
 *
 *  \brief      Implements the core logic of the rtos
 *
 *  \date       2015-08-03
 *  \revision   $Revision: 1.5 $
 *  \author     Andreas Menge (uidg4118)
 *  \copyright  Continental Automotive 2015
 *
 *  Implements the hardware independent part of the the ECC selftest for all processor platforms.
 */

#include "Kernel.h"
#include "Scheduler.h"

/*
 * # Sistema operativo de tiempo real con las siguientes caracteristicas.
 * - Sistema Operativo Cooperativo
 * - Manejo de tareas peri�dicas:
 *   - 5 ms
 *   - 20 ms
 *   - 40 ms
 *   - 80 ms
 * - Manejo de tareas Aperi�dicas.
 *   - Tarea de Bot�n presionado/liberado
 *   - Tarea valores de ADC.
 *
 * # Detalles
 * - Prioridad de tareas est�ticas y definidas por el estudiante.
 * - Para cada una de las tareas el estudiante deber� asignar un pin del microcontrolador para mostrar el estado de la tarea de la siguiente manera:
 *   - Flanco de subida sencillo: cambio de Blocked a Ready.
 *   - Pulso de bajada: cambio de Ready a Start
 *   - Flanco de bajada: Cambio a Blocked.
 *
 * # Descripci�n de tareas
 * - Task_5ms()
 *   - Conversiones de ADC con filtrado a 8 bits
 *   - Detecci�nn de estados del bot�n
 * - Task_10ms()
 *   - Rotabit de 8 bits con espacios entre transici�n de 500 ms.
 * - Task_20ms()
 *   - Variaci�n de Intensidad de un LED en forma de se�al Rampa Triangular con Periodo de 2 segundos.
 * - Task_40ms()
 *   - Controlar un servomotor dependiendo de un valor de entrada de ADC. (0 cuentas de ADC significa 45�, 255 cuentas de ADC significa 135�)
 * - Task_80ms()
 *   - Implementaci�n Libre
 *
 * - Tarea de Bot�n presionado/liberado
 *   - Cambio de estado de un LED.
 * - Tarea valores de ADC.
 *   - Si la cuenta de ADC es mayor a 200 un LED comienzan a parpadear
 */

int main(void) {
    /* Kernel_Init */
    KernelInit();
    /* run everything by interrupts */
    KernelRun();
    return 0;
}
