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
		else if (element > parent->info) // if the value in the data field of the new node is greater than that
		{
			parent->rightchild = newNode; //make the right child of the parent point to the new node
		}
	}
	void search(string element, Node*& parent, Node*& currentNode)
	{
		//this function searches the currentNode of the specified Node as well as the current Node of its parent
		currentNode = root;
		parent = nullptr;
		while ((currentNode != nullptr) && (currentNode->info != element))
		{
			parent = currentNode;
			if (element < currentNode->info)
				currentNode = currentNode->leftchild;
			else
				currentNode = currentNode->rightchild;
		}
	}
	void inorder(Node* ptr)
	{
		if (root == nullptr)
		{
			cout << "tree is empty" << endl;
			return;
		}
		if (ptr != nullptr)
		{
			inorder(ptr->leftchild);
			cout << ptr->info << " ";
			inorder(ptr->rightchild);

		}
	}
	void preorder(Node* ptr)
	{
		if (root == nullptr)
		{
			cout << "tree is empty" << endl;
			return;
		}
		if (ptr != nullptr)
		{
			cout << ptr->info << " ";
			preorder(ptr->leftchild);
			preorder(ptr->rightchild);

		}
	}
	void postorder(Node* ptr)
	{
		//performs the postorder traversal of the tree
		if (root == nullptr)
		{
			cout << "tree is empty" << endl;
			return;
		}
		if (ptr != nullptr)
		{

			postorder(ptr->leftchild);
			postorder(ptr->rightchild);
			cout << ptr->info << " ";
		}
	}
};

int main()
{
	binnarytree x;
	while (true)
	{
		cout << "\nMenu" << endl;
		cout << "1. Implement insert operation" << endl;
		cout << "2. Perform inorder traversal" << endl;
		cout << "3. perform preorder traversal" << endl;
		cout << "4. perform postorder traversal" << endl;
		cout << "5. exit" << endl;
		cout << "\nEnter your choice (1-5) : ";

		char ch;
		cin >> ch;
		cout << endl;

		switch (ch)
		{
		case '1':
		{
			cout << "Enter a word: ";
			string word;
			cin >> word;
			x.insert(word);
			break;
		}
		case '2':
		{
			x.inorder(x.root);
			break;
		}
		case '3':
		{
			x.preorder(x.root);
			break;
		}
		case '4':
		{
			x.postorder(x.root);
			break;
		}
		case '5':
		{
			return 0;
		}
		default:
		{
			cout << "invalid option " << endl;

			break;
		}
		}
	}
}