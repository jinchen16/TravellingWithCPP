#include <iostream>
#include <queue>
using namespace std;

struct numeric_tree {
	int value;
	numeric_tree* left;
	numeric_tree* right;
};

void add(int value, numeric_tree** pp) {
	*pp = new numeric_tree;
	(*pp)->value = value;
	(*pp)->left = (*pp)->right = nullptr;
}

void deleteTree(numeric_tree* item) {
	if (item == nullptr) {
		return;
	}

	deleteTree(item->left);
	deleteTree(item->right);
	cout << "deleting " << item->value << endl;
	delete item;
}

numeric_tree** find(int value, numeric_tree** pp) {
	if (*pp == nullptr) {
		return pp;
	}
	else if (value < (*pp)->value) {
		return find(value, &((*pp)->left));
	}
	else {
		return find(value, &((*pp)->right));
	}
}

void print(numeric_tree* item) {
	if (item == nullptr) {
		return;
	}

	print(item->left);
	cout << item->value << " ";
	print(item->right);
}

void printTree(numeric_tree* node) {
	if (node == nullptr) {
		return;
	}

	queue<numeric_tree*> nodeQueue;

	nodeQueue.push(node);

	while (!nodeQueue.empty())
	{
		int quantity = nodeQueue.size();

		while (quantity > 0) {
			numeric_tree* node = nodeQueue.front();
			nodeQueue.pop();

			cout << node->value << " ";

			if (node->left != nullptr) {
				nodeQueue.push(node->left);
			}

			if (node->right != nullptr) {
				nodeQueue.push(node->right);
			}

			quantity--;
		}

		cout << endl;
	}
}

int getTreeHeight(numeric_tree* node, int height = 1) {
	if (node == nullptr) {
		return height;
	}

	if (node->left != nullptr || node->right != nullptr) {
		height++;
	}

	getTreeHeight(node->left, height);
	getTreeHeight(node->right, height);
}

void printTreeUsingLevel(numeric_tree* node, int level) {
	if (node == nullptr) {
		return;
	}

	if (level == 1) {
		cout << node->value;
	}
	else {
		printTreeUsingLevel(node->left, level - 1);
		cout << ", ";
		printTreeUsingLevel(node->right, level - 1);
	}
}

numeric_tree* root = nullptr;

int main()
{
	int insertOrder[]{ 4, 2, 1, 3, 6, 7 };
	int totalElement = sizeof(insertOrder) / sizeof(int);
	for (int i = 0; i < totalElement; i++) {
		int value = insertOrder[i];
		add(value, find(value, &root));
	}

	print(root);
	cout << endl << endl;

	int h = getTreeHeight(root);
	for (int i = 1; i <= h; i++)
	{
		printTreeUsingLevel(root, i);
		cout << endl;
	}
	cout << endl;

	cout << "Tree level with queue" << endl;
	printTree(root);
	cout << endl;

	deleteTree(root);

	return 0;
}