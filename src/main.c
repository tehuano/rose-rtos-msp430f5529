#include <msp430.h> 


/**
 * # Sistema operativo de tiempo real con las siguientes características.
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
 * # Details
 * - Prioridad de tareas estáticas y definidas por el estudiante.
 * - Para cada una de las tareas el estudiante deberá asignar un pin del microcontrolador para mostrar el estado de la tarea de la siguiente manera:
 *   - Flanco de subida sencillo: cambio de Blocked a Ready.
 *   - Pulso de bajada: cambio de Ready a Start
 *   - Flanco de bajada: Cambio a Blocked.
 *
 * # Descripción de tareas
 * - Task_5ms()
 *   - Conversiones de ADC con filtrado a 8 bits
 *   - Detección de estados del botón
 * - Task_10ms()
 *   - Rotabit de 8 bits con espacios entre transición de 500 ms.
 * - Task_20ms()
 *   - Variación de Intensidad de un LED en forma de señal Rampa Triangular con Periodo de 2 segundos.
 * - Task_40ms()
 *   - Rotabit de 8 bits con espacios entre transición de 500 ms.
 *   - Controlar un servomotor dependiendo de un valor de entrada de ADC. (0 cuentas de ADC significa 45°, 255 cuentas de ADC significa 135°)
 * - Task_80ms()
 *   - Implementación Libre
 * - Tarea de Botón presionado/liberado
 *   - Cambio de estado de un LED.
 * - Tarea valores de ADC.
 *   - Si la cuenta de ADC es mayor a 200 un LED comienzan a parpadear
 */

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    return 0;
}
