/*
 * Behavior.c
 *
 *  Created on: 14 jul. 2019
 *      Author: Rommel
 */
#include "Behavior.h"
#include <msp430.h>

void task1(void) {
  volatile unsigned int i;

  P1DIR |= BIT0; /*for LED P1.0*/

  while(1)
  {
    if(1)
    {
      for (i=0; i < 65535; i++);
      for (i=0; i < 65535; i++);
      for (i=0; i < 65535; i++);

      P1OUT ^= BIT0;    // Toggle P1.0 (LED)
    }
  }
}

void task2(void) {
  volatile unsigned int i;

  P4DIR |= BIT7; /*for LED P4.7*/

  while(1)
  {
    if(1)
    {
      for (i=0; i < 65535; i++);

      P4OUT ^= BIT7;
    }
  }
}

void task3(void) {
  /*get both button states and exchange data */

  unsigned char b1,b2;
  volatile unsigned int i;

  P2REN |= BIT1;
  P2OUT |= BIT1;

  P1REN |= BIT1;
  P1OUT |= BIT1;

  while(1)
  {

    b1 = (P2IN & BIT1);
    b2 = (P1IN & BIT1);

    if(b2!=BIT1)
    {

    }

    for (i=0; i < 20000; i++); //software debouncing

  }
}
