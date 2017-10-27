/*
* My Queue library
* AUTHOR: Yue Pan zxc479773533@gmail.com
*/

#ifndef __LIBQUEUE_H_
#define __LIBQUEUE_H_

#include <stdio.h>
#include <stdlib.h>

// the data type in queue
typedef char* ElemType;

// queue node struct
typedef struct QNode {
    ElemType data;
    struct QNode *next;
} QNode;

// queue based in linklist
typedef struct {
    QNode* front;
    QNode* tail;
} LinkQueue;

// input:LinkQueue
// output:status
int InitQueue(LinkQueue *Q) {
    Q->front = Q->tail = (QNode*)malloc(sizeof(QNode));
    if (Q->front == NULL)
        return -1;
    Q->front->next = NULL;
    return 0;
}

// input:LinkQueue
// output:status
int DestroyQueue(LinkQueue *Q) {
    while (Q->front != NULL) {
        Q->tail = Q->front->next;
        free(Q->front);
        Q->front = Q->tail;
    }
    return 0;
}

// input:LinkQueue
// output:the length
int QueueLength(LinkQueue *Q) {
    int count = 0;
    QNode *p = Q->front;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

// input:LinkQueue, the data
// output:status
int EnQueue(LinkQueue *Q, char *str) {
    QNode* p = (QNode*)malloc(sizeof(QNode));
    if (p == NULL)
        return -1;
    p->data = str;
    p->next = NULL;
    Q->tail->next = p;
    Q->tail = Q->tail->next;
    return 0;
}

// input:LinkQueue
// output:the first
ElemType DeQueue(LinkQueue *Q) {
    if (Q->front == Q->tail)
        return NULL;
    QNode *p = Q->front->next;
    char *str = p->data;
    Q->front->next = p->next;
    if (p == Q->tail)
        Q->front = Q->tail;
    free(p);
    return str;
}

// input:LinkQueue
// output:null
void PrintQueue(LinkQueue *Q) {
    QNode* p = Q->front->next;
    while (p != NULL) {
        printf("%s\n", p->data);
        p = p->next;
    }
}

// input:LinkQueue
// output:the first
ElemType GetQueueHead(LinkQueue *Q) {
    return Q->front->next->data;
}

// input:LinkQueue
// output:status
int isEmpty(LinkQueue *Q) {
    if (Q->front == Q->tail)
        return -1;
    else
        return 1;
}

#endif // !__LIBQUEUE_H_