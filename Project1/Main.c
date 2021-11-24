#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "treeNode.h"
#define NODE_COUNT 10
#define MAX_VALUE 100

int main() {
	TreeNode* root = NULL;

	element keys[NODE_COUNT] = { 0 };
	srand((unsigned int)time(NULL));
	for (int i = 0; i < NODE_COUNT; i++) {
		keys[i] = rand() % MAX_VALUE + 1;

		for (int j = i - 1; j >= 0; j--) {
			if (keys[i] == keys[j]) {
				i--;
				break;
			}
		}
	}

	for (int i = 0; i < NODE_COUNT; i++) {
		printf("%d ", keys[i]);
	}

	printf("\n\nInsertNode\n");

	for (int i = 0; i < NODE_COUNT; i++) {
		root = insertNode(root, keys[i]);
	}

	printf("\nPrint Inorder");
	printInorder(root);
	printf("\n");

	printf("\nPrint Levelorder");
	printLevelorder(root);
	printf("\n");

	return 0;
}