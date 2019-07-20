#include <msp430.h> 
#include "Kernel.h"
#include "Task.h"
#include "Behavior.h"
#include "Hardware.h"

/**
 * # Sistema operativo de tiempo real con las siguientes características.
 * - Sistema Operativo Cooperativo
 * - Manejo de tareas periódicas:
 *   - 5 ms
 *   - 20 ms
 *   - 40 ms
 *   - 80 ms
 * - Manejo de tareas Aperiódicas.
 *   - Tarea de Bot�n presionado/liberado
 *   - Tarea valores de ADC.
 *
 * # Details
 * - Prioridad de tareas est�ticas y definidas por el estudiante.
 * - Para cada una de las tareas el estudiante deberá asignar un pin del microcontrolador para mostrar el estado de la tarea de la siguiente manera:
 *   - Flanco de subida sencillo: cambio de Blocked a Ready.
 *   - Pulso de bajada: cambio de Ready a Start
 *   - Flanco de bajada: Cambio a Blocked.
 *
 * # Descripci�n de tareas
 * - Task_5ms()
 *   - Conversiones de ADC con filtrado a 8 bits
 *   - Detecci�nn de estados del bot�nn
 * - Task_10ms()
 *   - Rotabit de 8 bits con espacios entre transición de 500 ms.
 * - Task_20ms()
 *   - Variación de Intensidad de un LED en forma de se�al Rampa Triangular con Periodo de 2 segundos.
 * - Task_40ms()
 *   - Rotabit de 8 bits con espacios entre transición de 500 ms.
 *   - Controlar un servomotor dependiendo de un valor de entrada de ADC. (0 cuentas de ADC significa 45°, 255 cuentas de ADC significa 135°)
 * - Task_80ms()
 *   - Implementación Libre
 * - Tarea de Bot�n presionado/liberado
 *   - Cambio de estado de un LED.
 * - Tarea valores de ADC.
 *   - Si la cuenta de ADC es mayor a 200 un LED comienzan a parpadear
 */

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    /* Initialize the timer module */
    HardwareInitIO();
    /* Initialize the timer module */
    HardwareInitTimerA0();
    /* run everything by interrupts */
    while (1) {}
    return 0;
}
