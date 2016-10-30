// BST CLASS.cpp : Defines the entry point for the console application.
//
#include <iostream>

using namespace std;

struct node {
	int value;
	node *left;
	node *right;
};

class bst {
public:
	bst();
	~bst();

	void insert(int value);
	void print();
	bool search(int value);
	node* getnewnode(int value);
	void terminate_tree();
private:
	void terminate_tree(node** root);
	bool search(node** root, int value);
	void print(node* root);
	void insert(node** root, int value);
	node* root;
	node* tree;
	
};

bst::bst() {
	root = NULL;
}

bst::~bst() {
	delete root;
}

node* bst::getnewnode(int value) {
	node* newNode = new node();
	newNode->value = value;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void bst::insert(int value) {
	insert (&root,value);
}

void bst::insert(node** root, int value) {
	if (*root == NULL) {
		*root = getnewnode(value);
	}
	else if (value <= (*root)->value) {
		insert(&(*root)->left, value);
	}
	else {
		insert(&(*root)->right, value);
	}
}

void bst::print(node* root) {
	if (root->left != NULL) {
		print(&(*root->left));
	}

	cout << root->value << " "<<endl;

	if (root->right != NULL) {
		print(&(*root->right));
	}

}

void bst::print() {
	print (root);
}

void bst::terminate_tree(node** root) {
	if ((*root)->left != NULL) {
		terminate_tree(&(*root)->left);
	}
	if ((*root)->right != NULL) {
		terminate_tree(&(*root)->right);
	}

	delete *root;
	root = NULL;
}

void bst::terminate_tree() {
	terminate_tree(&root);
}

bool bst::search(node** root, int value) {
	if (*root == NULL) return false;
	else if ((*root)->value == value) return true;
	else if (value < (*root)->value) return search(&(*root)->left, value);
	else return search(&(*root)->right, value);
}

bool bst::search(int value) {
	return search(&root, value);
}

int main(void) {

	bst e1; 
	e1.insert(5);
	e1.insert(15);
	e1.insert(10);
	e1.insert(25);
	e1.insert(50);
	e1.insert(35);
	e1.insert(40);

	e1.print();

	int xfactor = 0;
	while (xfactor != 99) {
		cout << "Enter a number to be searched" << endl;
		cin >> xfactor;
		if (e1.search(xfactor) == true)
			cout << "Found" << endl;
		else
			cout << "Not Found" << endl;
	}

	e1.terminate_tree();

	cin.ignore();
	cin.get();

	return 0;
}
