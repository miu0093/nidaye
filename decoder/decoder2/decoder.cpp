#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct node {
	int value;
	node * left;
	node * right;
};

class trellis {
public:
	trellis();
	~trellis();

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
	node * n1;node * n2;node * n3;node * n4;
	node * n5;node * n6;node * n7;node * n8;
};
trellis::trellis() {
	n1 = NULL;
}

trellis::~trellis() {
	delete n1;
}

node* trellis::getnewnode(int value) {
	node* newNode = new node();
	newNode->value = value;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void trellis::insert(int value) {
	insert(&n1, value);
}
void trellis::insert(node** n1, int value) {
	if (*n1 == NULL) {
		*n1 = getnewnode(value);
	}
	else if (value <= (*n1)->value) {
		insert(&(*n1)->left, value);
	}
	else {
		insert(&(*n1)->right, value);
	}
}
void trellis::print(node* n1) {
	if (n1->left != NULL) {
		print(&(*n1->left));
	}

	cout << n1->value << " " << endl;
	if (n1->right != NULL) {
		print(&(*n1->right));
	}

}
void trellis::print() {
	print(n1);
}
void trellis::terminate_tree(node** n1) {
	if ((*n1)->left != NULL) {
		terminate_tree(&(*n1)->left);
	}
	if ((*n1)->right != NULL) {
		terminate_tree(&(*n1)->right);
	}

	delete *n1;
	n1 = NULL;
}
void trellis::terminate_tree() {
	terminate_tree(&n1);
}

bool trellis::search(node** root, int value) {
	if (*root == NULL) return false;
	else if ((*root)->value == value) return true;
	else if (value < (*root)->value) return search(&(*root)->left, value);
	else return search(&(*root)->right, value);
}
bool trellis::search(int value) {
	return search(&n1, value);
}
int main(void) {

	trellis e1;
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
