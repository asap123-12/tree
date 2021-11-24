#pragma once
#include "treeNode.h"
#define MAX_QUEUE_SIZE 10

typedef struct {

	int front, rear, count;
	TreeNode* data[MAX_QUEUE_SIZE];

} QueueType;

void enQueue(QueueType* q, TreeNode* node);
TreeNode* deQueue(QueueType* q);
void initQueue(QueueType* q);
int isFull(QueueType* q);
int isEmpty(QueueType* q);