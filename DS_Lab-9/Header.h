#pragma once
#include <iostream>
using namespace std;
template <typename T1,typename T2>
class Node
{
public:
	T1 data;
	T2 id;
	Node<T1,T2>* left=NULL;
	Node<T1,T2>* right=NULL;
	Node(T1 data, T2 id)
	{
		this->data = data;
		this->id = id;
	}
	
};
template <class T1, class T2>
class Tree
{
public:
	Node<T1,T2>* root;
	Tree()
	{
		root = NULL;
	}
	void insert(Node<T1,T2> n)
	{
		Node<T1,T2>* node = new Node<T1,T2>(n.data,n.id);
		if (!root) 
		{
			root = node;
			return;
		}
		Node<T1, T2>* prev = NULL;
		Node<T1, T2>* temp = root;
		while (temp != NULL) {
			if (temp->id > n.id) {
				prev = temp;
				temp = temp->left;
			}
			else if (temp->id < n.id) {
				prev = temp;
				temp = temp->right;
			}
		}
		if (prev->id > n.id)
			prev->left = node;
		else prev->right = node;
	}
	void remove(T2 num)
	{
		remove2(num, root);
	}
	void remove2(T2 num, Node<T1,T2>*& nodePtr)
	{

		if (nodePtr == NULL)//Not Found
			return;
		else if (num < nodePtr->id)//less then; move to left
			remove2(num, nodePtr->left); 
		else if (num > nodePtr->id)//greater then; move to right 
			remove2(num, nodePtr->right); 
		else						//Not greater nor less then equal
			DeleteNode(nodePtr); // delete
	}
	void DeleteNode(Node<T1,T2>*& nodePtr) {
		Node<T1,T2>* tempNodePtr; 

		if (nodePtr->right == NULL) {	//when no right node 
			tempNodePtr = nodePtr;
			nodePtr = nodePtr->left;	//move to left
			delete tempNodePtr;
		}

		else if (nodePtr->left == NULL) { // when no left node
			tempNodePtr = nodePtr;
			nodePtr = nodePtr->right; // move to right
			delete tempNodePtr;
		}

		else {							//when both node are present
			tempNodePtr = nodePtr->right; 
			//move to left 
			while (tempNodePtr->left) {tempNodePtr = tempNodePtr->left;}
			//make deleted node left ;upper node left
			tempNodePtr->left = nodePtr->left; 
			tempNodePtr = nodePtr;
			
			// Reattach the right subtree
			nodePtr = nodePtr->right; 			
			delete tempNodePtr;

		}
	}
	bool retrieve(T1 data)
	{
		Node<T1,T2>* NodePtr = root;
		while (NodePtr)
		{
			if (NodePtr->data == data)		//return true /data found
				return true;
			else if (data < NodePtr->data)//move to left
				NodePtr = NodePtr->left;
			else						//move to right
				NodePtr = NodePtr->right;
		}
		return false; 

	}
	bool isEmpty()
	{
		return root==NULL;
	}
	void display()
	{
		Inorder(root);
	}
	void displayInOrder()
	{
		Inorder(root);
	}
	void displayPreOrder()
	{
		PreOrder(root);
	}
	void displayPostOrder()
	{
		PostOrder(root);
	}

	void PostOrder(Node<T1, T2>* root)
	{
		if (root)
		{
			PostOrder(root->left);
			cout << root->data << " ";
			PostOrder(root->right);
		}
		else
		cout << endl;

	}
	void Inorder(Node<T1,T2>* root)
	{
		if (root) 
		{
			Inorder(root->left);
			cout << root->data << " ";
			Inorder(root->right);
		}
		else
		cout << endl;
	}
	void PreOrder(Node<T1,T2>* root)
	{
		if (root) 
		{
			cout << root->data << " ";
			PreOrder(root->left);
			PreOrder(root->right);
		}
		else
		cout << endl;
	}

	~Tree()
	{
		deleteNodes(root);
	}
	void deleteNodes(Node<T1, T2>* root)
	{
		if (root)
		{
			deleteNodes(root->left);
			deleteNodes(root->right);
			delete root;
		}
	}

}; 