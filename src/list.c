/*
 * list.c
 *
 *  Created on: 2 ago. 2019
 *      Author: Rommel
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
    int ret;
    if(NULL == s) {
        ret = VAL_ERR;
    } else if(NULL == s->head && NULL == s->tail) {
        ret = VAL_SUCC;
    } else if(NULL == s->head || NULL == s->tail) {
        ret = VAL_ERR;
    } else {
        p = s->head;
        /* if last element */
        if(NULL == s->head->next && NULL == s->tail->next) {
            s->head = s->tail = NULL;
        } else {
            s->head = s->head->next;
        }
        ret = VAL_SUCC;
    }
    return p;
}