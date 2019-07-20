#include <msp430.h> 
#include "Kernel.h"
#include "Task.h"
#include "Behavior.h"
#include "Hardware.h"

/**
 * # Sistema operativo de tiempo real con las siguientes caracter铆sticas.
 * - Sistema Operativo Cooperativo
 * - Manejo de tareas peri贸dicas:
 *   - 5 ms
 *   - 20 ms
 *   - 40 ms
 *   - 80 ms
 * - Manejo de tareas Aperi贸dicas.
 *   - Tarea de Bot髇 presionado/liberado
 *   - Tarea valores de ADC.
 *
 * # Details
 * - Prioridad de tareas est醫icas y definidas por el estudiante.
 * - Para cada una de las tareas el estudiante deber谩 asignar un pin del microcontrolador para mostrar el estado de la tarea de la siguiente manera:
 *   - Flanco de subida sencillo: cambio de Blocked a Ready.
 *   - Pulso de bajada: cambio de Ready a Start
 *   - Flanco de bajada: Cambio a Blocked.
 *
 * # Descripci髇 de tareas
 * - Task_5ms()
 *   - Conversiones de ADC con filtrado a 8 bits
 *   - Detecci髇n de estados del bot髇n
 * - Task_10ms()
 *   - Rotabit de 8 bits con espacios entre transici贸n de 500 ms.
 * - Task_20ms()
 *   - Variaci贸n de Intensidad de un LED en forma de se馻l Rampa Triangular con Periodo de 2 segundos.
 * - Task_40ms()
 *   - Rotabit de 8 bits con espacios entre transici贸n de 500 ms.
 *   - Controlar un servomotor dependiendo de un valor de entrada de ADC. (0 cuentas de ADC significa 45掳, 255 cuentas de ADC significa 135掳)
 * - Task_80ms()
 *   - Implementaci贸n Libre
 * - Tarea de Bot髇 presionado/liberado
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
