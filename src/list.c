/**
 * @file       list.c
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

#include "list.h"


/* Adds an element to tail of Queue */
int enqueue(list_t* s, node_t* p) {
    int ret;
    if(NULL == s){
        ret = VAL_ERR;
    } else if(NULL == s->head && NULL == s->tail) {
        if(NULL == p) {
            ret = VAL_ERR;
        } else {
            p->prev = p->next = NULL;
            s->head = s->tail = p;
            ret = VAL_SUCC;
        }
    } else if(NULL == s->head || NULL == s->tail) {
        ret = VAL_ERR;
    } else {
        if(NULL == p) {
            ret = VAL_ERR;
        } else {
            p->prev = p->next = NULL;
            s->tail->next = p;
            p->prev = s->tail;
            s->tail = p;
            ret = VAL_SUCC;
        }
    }
    return ret;
}

node_t* dequeue(list_t* s) {
    node_t* p = NULL;
    if(NULL == s) {
        p = NULL;
    } else if(NULL == s->head && NULL == s->tail) {
        p = NULL;
    } else if(NULL == s->head || NULL == s->tail) {
        p = NULL;
    } else {
        p = s->head;
        /* if last element */
        if(NULL == s->head->next && NULL == s->tail->next) {
            s->head = s->tail = NULL;
        } else {
            s->head = s->head->next;
        }
    }
    return p;
}
