#pragma once
#pragma once
#include <iostream>
using namespace std;

bool check_Op(char c);
bool check_Num(char c);

template <typename T>
class Node
{
public:
	T data;
	Node<T>* next;
};
template <typename T>
class stack
{
private:
	Node<T>* head;
public:
	static int size;
	stack(T ignored = 0)
	{
		head = NULL;
	}
	void push(T data)
	{
		Node<T>* newNode = new Node<T>;

		newNode->data = data;

		newNode->next = head;
		head = newNode;
		size++;

	}
	void pop()
	{
		if (isEmpty())
			return ;
		Node<T>* newNode = head;
		head = head->next;
		delete newNode;
		size--;
		
	}

	T peek()
	{
		if(!isEmpty())
		{
			return head->data;
		}
		else
		{
			return 0;
		}
	}
	void clear()
	{
		while (!isEmpty())
		{
			pop();
		}
	}
	int sizeofstack()
	{
		return size;
	}
	bool isEmpty()
	{
		return head == NULL;
	}
};
template <typename T>
int stack<T>::size = 0;
template <typename T>
class TreeNode
{
public:
	T data;
	TreeNode* left;
	TreeNode* right;

	
};
template <typename T>
class ExpressionTree
{
	TreeNode<T>* root;
public:
	ExpressionTree()
	{
		root = NULL;
	}
	

	TreeNode<T>* CreateTree(string expression)
	{
		stack<TreeNode<T>*> st;
		int i = 0;
		while (expression[i])
		{
			if (check_Num(expression[i]))
			{
				root = new TreeNode<T>;
				root->data = expression[i];
				root->left = NULL;
				root->right= NULL;
				st.push(root);
			}
			if (check_Op(expression[i]))
			{
				root = new TreeNode<T>;
				root->data = expression[i];
				TreeNode<T>* right = st.peek();
				st.pop();
				TreeNode<T>* left = st.peek();
				st.pop();

				root->left=left;
				root->right=right;
				
				st.push(root);

			}
			i++;
		}
		root = st.peek();
		return root;
	}
	void displayInOrder()
	{
		Inorder(root);
	}
	void Inorder(TreeNode<T>* root)
	{
		if (root)
		{
			Inorder(root->left);
			cout << root->data << " ";
			Inorder(root->right);
		}
	}

private:

};
//Check for OPeration
bool check_Op(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '%' || c == '/' || c == '(')
		return true;
	else
		return false;
}
//Check for Number or operand
bool check_Num(char c)
{
	if (c >= 65 && c <= 90 || c >= 97 && c <= 122)
		return true;
	else
		return false;
}