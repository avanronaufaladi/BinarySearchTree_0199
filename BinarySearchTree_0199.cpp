#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
	string info;
	Node* leftchild;
	Node* rightchild;

	//construktor for the node class
	Node(string i, Node* l, Node* r)
	{
		info = i;
		leftchild = l;
		rightchild = r;
	}

};

class binnarytree
{
public:
	Node* root;
	binnarytree()
	{
		root = nullptr; //initializing root to null
	}
	void insert(string element) //insert a node in the binary search tree
	{
		Node* newNode = new Node(element, nullptr, nullptr); //allocate memory for the new node
		newNode->info = element; //assign value to the data field of the new node
		newNode->leftchild = nullptr; //make the left child of the new node point to null
		newNode->rightchild = nullptr; //make the right child of the new node point to null

		Node* parent = nullptr;
		Node* currentnode = nullptr;
		search(element, parent, currentnode); //locate the node which will be the parent of the node to be insert

		if (parent == nullptr) // if the parent is null(tree is empty)
		{
			root = newNode; // mark the new node as root
			return; //exit
		}
		if (element < parent->info) // if the value in the data field of the new node is less than of the
		{
			parent->leftchild = newNode; // make the left child of the parents point to the new node
		}
		