/**
 * @file       list.h
 * @brief      Implementation of a linked list
 *
 * Implements functionality and data types of a linked list. This linked list definition
 * will be used to create the ready list of the RTOS.
 *
 * @date       2019-07-01
 * $Revision: 1.0$
 * @author     Rommel García Hernández
 * @copyright  Guenda Tecnología de México
 */

#ifndef INCLUDE_LIST_H_
#define INCLUDE_LIST_H_

#include <stdlib.h>

/**
 * Information about the resuult of list operations.
 */
enum {VAL_SUCC = 0, VAL_ERR = 1};

/**
* A structure to represent nodes of a linked list.
*/
struct node {
    unsigned char id;
    struct node *next;
    struct node *prev;
};
typedef struct node node_t;

/**
* A structure to represent a linked list.
*/
struct list {
    struct node *head;
    struct node *tail;
};
typedef struct list list_t;

/**********************************************************************************************************************
 *  int enqueue()
 *********************************************************************************************************************/
/**
 * @brief  Adds a new node to the linked list
 *
 * Adds a new node to the linked list.
 *
 * @pre    None
 * @post   None
 *
 * @param[in] list_t *l pointer to the list
 * @param[in] node_t *n pointer to the new node to be added
 *
 * @return int VAL_SUCC if process was correct and VAL_ERR when it fails.
 *
 * @startuml
 * start
 *
 * if (is_empty(s)) then (yes)
 *   :list.head = node;
 *   :list.tail = node;
 * else (no)
 *   :list.tail = node;
 * endif
 *
 * stop
 * @enduml
 */
int enqueue(list_t *l, node_t *n);

/**********************************************************************************************************************
 * node_t* dequeue(list_t *l);
 *********************************************************************************************************************/
/**
 * @brief  Returns the node at the top of the queue
 *
 * Return the node at the top of the queue.
 *
 * @pre    None
 * @post   None
 *
 * @param[in] list_t *l pointer to the list
 *
 * @return node_t* pointing to the node from the top of the list
 *
 * @startuml
 * start
 *
 * if (is_empty(s)) then (yes)
 *   :return NULL;
 * else (no)
 *   :node = list.head;
 *   :update references;
 *   :return node;
 * endif
 *
 * stop
 * @enduml
 */
node_t* dequeue(list_t *l);

#endif /* INCLUDE_LIST_H_ */
