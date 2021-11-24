#include <stdio.h>
#include "circularQueue.h"


void initQueue(QueueType* q) {
	q->front = q->rear = 0;
	q->count = 0;
}


int isFull(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

int isEmpty(QueueType* q) {
	return (q->front == q->rear);
}

void enQueue(QueueType* q, TreeNode* item) {
	if (isFull(q)) {
		printf("Queue is Full\n");
		return;
	}
	q->count++;
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

TreeNode* deQueue(QueueType* q) {
	if (isEmpty(q)) {
		printf("Queue is Empty\n");
		return NULL;
	}
	q->count--;
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}


