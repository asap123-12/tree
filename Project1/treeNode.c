#include <stdio.h>
#include <stdlib.h>
#include "treeNode.h"
#include "circularQueue.h"

TreeNode* makeNode(element key) {
	TreeNode* temp = malloc(sizeof(TreeNode));
	temp->data = key;
	temp->leftChild = temp->rightChild = NULL;
	return temp;
}

TreeNode* insertNode(TreeNode* node, element key) {
	if (!node) {
		return makeNode(key);
	}

	if (key < node->data)
		node->leftChild = insertNode(node->leftChild, key);
	else
		node->rightChild = insertNode(node->rightChild, key);

	return node;
}

void printInorder(TreeNode* node) {
	if (node) {
		printInorder(node->leftChild);
		printf("[ %d ] ", node->data);
		printInorder(node->rightChild);
	}
}

void printPreorder(TreeNode* node) {
	if (node) {
		printf("[ %d ] ", node->data);
		printInorder(node->leftChild);
		printInorder(node->rightChild);
	}
}

void printPostorder(TreeNode* node) {
	if (node) {
		printInorder(node->leftChild);
		printInorder(node->rightChild);
		printf("[ %d ] ", node->data);
	}
}

void printLevelorder(TreeNode* node) {
	if (!node)
		return;

	QueueType* q;
	q = (QueueType*)malloc(sizeof(QueueType));
	initQueue(q);

	enQueue(q, node);

	while (q->count) {
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		printf("[%d ] ", temp->data);

		if (temp->leftChild)
			enQueue(q, temp->leftChild);
		if (temp->rightChild)
			enQueue(q, temp->rightChild);
	}
}
