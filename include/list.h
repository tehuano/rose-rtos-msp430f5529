/*
 * list.h
 *
 *  Created on: 2 ago. 2019
 *      Author: Rommel
 */

#ifndef INCLUDE_LIST_H_
#define INCLUDE_LIST_H_

#include <stdlib.h>

enum {VAL_SUCC = 0, VAL_ERR = 1};

struct node {
    unsigned char id;
    struct node *next;
    struct node *prev;
};

typedef struct node node_t;

struct list {
    struct node *head;
    struct node *tail;
};

typedef struct list list_t;

int enqueue(list_t *l, node_t *n);
node_t* dequeue(list_t *l);

#endif /* INCLUDE_LIST_H_ */
