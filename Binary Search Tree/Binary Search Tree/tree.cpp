#include <iostream>
#include <memory>
#include <list>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct node {
	int value;
	struct node* left;
	struct node* right;
};

 node* GetNewNode(int value) {
	node* newNode = new node();
	newNode->value = value;
	newNode->left = newNode->right = NULL;
	return newNode; 
}

void insert_interger(node** root, int value) {
	if (*root == NULL) {
		*root = GetNewNode(value);
	}
	else if (value <= (*root)->value) {
		/*(*root)->left = */insert_interger(&(*root)->left, value);
	}
	else {
		/*(*root)->right = */insert_interger(&(*root)->right, value);
	}
}

void print_tree(node* root) {
	if (root->left != NULL) {
		print_tree(&(*root->left));
	}

	cout << root->value << " ";

	if (root->right != NULL) {
		print_tree(&(*root->right));
	}

}

void terminate_tree(node** root) {
	if ((*root)->left != NULL) {
		terminate_tree(&(*root)->left);
	}
	if ((*root)->right != NULL) {
		terminate_tree(&(*root) -> right);
	}

		delete *root;
		//*root = NULL;
	}

//nullptr

bool Search(node** root, int value) {
	if (*root == NULL) return false;
	else if ((*root)->value == value) return true;
	else if (value < (*root)->value) return Search(&(*root)->left, value);
	else return Search(&(*root)->right, value);
}

//int a[7] = { 1,5,9,3,7,4,8 };
	node* tree = NULL;
//
int main() {
	/*for (int i = 0;i < 7;i++)*/
	//terminate_tree(&tree);
	insert_interger(&tree, 5);
	insert_interger(&tree, 10);
	insert_interger(&tree, 25);
	
	print_tree(tree);

	int xfactor = 0;
	while (xfactor != 99) {
		cout << "Enter a number to be searched" << endl;
		cin >> xfactor;
		if (Search(&tree, xfactor) == true)
			cout << "Found" << endl;
		else
			cout << "Not Found" << endl;
	}

	terminate_tree(&tree);

	delete tree;
	tree = NULL;
	
	cin.ignore();
	cin.get();

	return 0;

}


