typedef int element;

typedef struct {
	element data;
	struct TreeNode* leftChild;
	struct TreeNode* rightChild;

}TreeNode;

TreeNode* insertNode(TreeNode* node, element key);
TreeNode* makeNode(element key);
void printInorder(TreeNode* node);
void printPreorder(TreeNode* node);
void printPostorder(TreeNode* node);
void printLevelorder(TreeNode* node);