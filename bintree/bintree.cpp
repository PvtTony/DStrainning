#include<iostream>
using namespace std;
#define ElementType int

struct TreeNode
{
	ElementType val;
	struct TreeNode *left;
	struct TreeNode *right;
};

TreeNode *PreOrderCreateTree();
void PreOrderPrintTree(TreeNode *tree);
void InOrderPrintTree(TreeNode *tree);
void PostOrderPrintTree(TreeNode *tree);
void FreeTree(TreeNode *tree);
int GetNodeNum(TreeNode *tree);
int GetLeafNodeNum(TreeNode *tree);

TreeNode *CreateTreeNode(ElementType val)
{
	TreeNode *rtn = new TreeNode;
	rtn->val = val;
	rtn->left = NULL;
	rtn->right = NULL;
	return rtn;
}

TreeNode *PreOrderCreateTree()
{
	TreeNode *rtn = NULL;
	ElementType val;
	cin >> val;
	if (val == 0)
	{
		return rtn;
	}
	else
	{
		rtn = CreateTreeNode(val);
		rtn->left = PreOrderCreateTree();
		rtn->right = PreOrderCreateTree();
	}
	return rtn;
}

void FreeTreeNode(TreeNode *tree)
{
	if (tree != NULL) delete tree;
}


void PreOrderPrintTree(TreeNode *tree)
{
	if (tree != NULL)
	{
		cout << tree->val << " ";
		PreOrderPrintTree(tree->left);
		PreOrderPrintTree(tree->right);
	}
}

void ReverseTree(TreeNode *tree)
{
	if (tree != NULL)
	{
		TreeNode *temp = tree->right;
		tree->right = tree->left;
		tree->left = temp;
		ReverseTree(tree->left);
		ReverseTree(tree->right);
	}
		
}

void InOrderPrintTree(TreeNode *tree)
{
	if (tree != NULL)
	{
		PreOrderPrintTree(tree->left);
		cout << tree->val << " ";
		PreOrderPrintTree(tree->right);
	}
}

void PostOrderPrintTree(TreeNode *tree)
{
	if (tree != NULL)
	{
		PreOrderPrintTree(tree->left);
		PreOrderPrintTree(tree->right);
		cout << tree->val << " ";
	}
}

void FreeTree(TreeNode *tree)
{
	if (tree != NULL)
	{
		FreeTree(tree->left);
		FreeTree(tree->right);
		FreeTreeNode(tree);
		tree = NULL;
	}
}

int GetNodeNum(TreeNode *tree)
{
	if (tree == NULL) return 0;
	return GetNodeNum(tree->left) + GetNodeNum(tree->right) + 1;
}

int GetTreeDepth(TreeNode *tree)
{
	if (tree == NULL) return 0;
	int depthLeft = GetTreeDepth(tree->left);
	int depthRight = GetTreeDepth(tree->right);
	return ((depthLeft > depthRight ? depthLeft : depthRight) + 1);
}

int GetLeafNodeNum(TreeNode *tree)
{
	if (tree == NULL) return 0;
	if (tree != NULL && tree->left == NULL && tree->right == NULL) return 1;
	int numLeftLeaf = GetLeafNodeNum(tree->left);
	int numRightLeaf = GetLeafNodeNum(tree->right);
	return numLeftLeaf + numRightLeaf;
}

int main(void)
{
	TreeNode *test = PreOrderCreateTree();
	cout << "Pre Order: " << endl;
	PreOrderPrintTree(test);
	cout << endl << "In Order: " << endl;
	InOrderPrintTree(test);
	cout << endl << "Post Order: " << endl;
	PostOrderPrintTree(test);
	ReverseTree(test);
	cout << endl << "After Reversed: " << endl;
	PreOrderPrintTree(test);
	cout << endl << "Node Num: " << GetNodeNum(test) << endl;
	cout << "Tree Depth: " << GetTreeDepth(test) << endl;
	cout << "Tree Leaf Node Num: " << GetLeafNodeNum(test) << endl;
	FreeTree(test);
	return 0;
}