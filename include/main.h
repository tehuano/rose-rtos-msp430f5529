/** ************************************************************************************************
 * @file       main.h
 * @brief      Main function
 *
 * Main function definition.
 *
 * @date       2019-07-01
 * $Revision: 1.0$
 * @author     Rommel Garc�a Hern�ndez
 * @copyright  Guenda Tecnolog�a de M�xico 2015
 */

#ifndef INCLUDE_MAIN_H_
#define INCLUDE_MAIN_H_

#include "Kernel.h"

/**
 * @mainpage
 *
 * @brief RTOS with the following functionalities.
 *
 * @section Introduction
 *
 * Specific documentation of ROSE RTO interest to a reader. Doxygen will
 * document pretty much every part of your code, so do your best here to
 * point the reader to the actual API.
 *
 * If your codebase is fairly large or has different sets of APIs, you
 * should use the doxygen 'group' tag to keep these APIs together. For
 * example, the roscpp documentation has 'libros' and 'botherder' groups
 * so that those can be viewed separately. The rospy documentation
 * similarly has a 'client-api' group that pulls together APIs for a
 * Client API page.
 *
 * @section ROSE RTOS Task Definitions
 *
 * @subsection Sistema operativo de tiempo real con las siguientes caracteristicas
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
 * Detalles
 * - Prioridad de tareas est�ticas y definidas por el estudiante.
 * - Para cada una de las tareas el estudiante deber� asignar un pin del microcontrolador para mostrar el estado de la tarea de la siguiente manera:
 *   - Flanco de subida sencillo: cambio de Blocked a Ready.
 *   - Pulso de bajada: cambio de Ready a Start
 *   - Flanco de bajada: Cambio a Blocked.
 *
 * Descripci�n de tareas
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
 *   - Log de m�xima velocidad en la ejecuci�n
 *
 * - Tarea de Bot�n presionado/liberado
 *   - Cambio de estado de un LED.
 * - Tarea valores de ADC.
 *   - Si la cuenta de ADC es mayor a 200 un LED comienzan a parpadear
 */

#endif /* INCLUDE_MAIN_H_ */
