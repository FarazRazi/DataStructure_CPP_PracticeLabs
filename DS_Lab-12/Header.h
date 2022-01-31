#pragma once
#include <iostream>
using namespace std;
template <typename T1>
class Node
{
public:
	T1 data;
	Node<T1>* left = NULL;
	Node<T1>* right = NULL;
	int height;

	
	T1 getData()
	{
		return data;
	}

	void setData(T1 data)
	{
		this->data = data;
	}
	Node<T1>* getleft()
	{
		return this->left;
	}

	void setleft(Node<T1>* left)
	{
		this->left = left;
	}
	Node<T1>* getright()
	{
		return this->right;
	}

	void setright(Node<T1>* right)
	{
		this->right = right;
	}

	int getHeight()
	{
		return this->height;
	}

	void setHeight(int height)
	{
		this->height = height;
	}

	Node()
	{

	}
	Node(T1 data)
	{
		this->data = data;
	}

};
template <class T1>
class AVLTree
{

	Node<T1>* root;

public:

	Node<T1>* getRoot()
	{
		return this.root;
	}
	void setRoot(Node<T1>* root)
	{
		this.root = root;
	}
	AVLTree()
{
	root = NULL;
}
	  void insert(Node<T1> T) {
		  Node<T1>* NewT = new Node<T1>;
		  NewT = root;
		  root = Insert(T, NewT);
	  }
	  Node<T1>* Insert(Node<T1> X, Node<T1>* T) {

		  if (T == NULL) { /* Create and return a one-node AVLTree */
			  T = new Node<T1>;
			  T->setData(X.getData());

			  T->setleft(NULL);
			  T->setright(NULL);

		  }

		  else if (X.data < T->getData()) {

			  T->setleft(Insert(X, T->getleft())) ;

			  if (height(T->left) - height(T->right) == 2)

				  if (X.data < T->left->getData())

					  T = SingleRotateWithleft(T); // RR rotation

				  else

					  T = DoubleRotateWithleft(T); // RL rotation

		  }

		  else if (X.data > T->getData()) {

			  T->setright(Insert(X, T->getright()));
			  if (height(T->right) - height(T->left) == 2)

				  if (X.data > T->right->getData())

					  T = SingleRotateWithright(T); // LL rotation

				  else

					  T = DoubleRotateWithright(T); // LR rotation
		  } /* Else X is in the AVLTree already; we'll do nothing */

		  T->height = Max(height(T->left), height(T->right)) + 1;

		  return T;
	  }

	  Node<T1>* SingleRotateWithright(Node<T1>* K1) {

		  Node<T1>* K2;

		  K2 = K1->right; // K1: node whose balance factor is violated

		  K1->right = K2->left;

		  K2->left = K1;

		  K1->height = Max(height(K1->left), height(K1->right)) + 1;

		  K2->height = Max(height(K2->right), K1->height) + 1;

		  return K2; /* New root */

	  }
	  Node<T1>* SingleRotateWithleft(Node<T1>* K1) {

		  Node<T1>* K2;

		  K2 = K1->left; // K1: node whose balance factor is violated

		  K1->left = K2->right;

		  K2->right = K1;

		  K1->height = Max(height(K1->left), height(K1->right)) + 1;

		  K2->height = Max(height(K2->left), K1->height) + 1;

		  return K2; /* New root */

	  }
	  Node<T1>* DoubleRotateWithright(Node<T1>* K1)
	  {
		  /* RR rotation between K3 and K2 */

		  K1->right = SingleRotateWithleft(K1->right);

		  /* LL rotation between K1 and K2 */

		  return SingleRotateWithright(K1);
	  }
	  Node<T1>* DoubleRotateWithleft(Node<T1>* K3)
	  {
		  /* LL rotation between K1 and K2 */
		  K3->left = SingleRotateWithright(K3->left);
		  /* RR rotation between K3 and K2 */
		  return SingleRotateWithleft(K3);
	  }
	  int height(Node<T1>* P)
	  {

		  if (P == NULL)
			  return -1;
		  else
			  return P->height;
	  }
	  int Max(int a, int b)
	  {
		  if (a > b)
			  return a;
		  else
			  return b;
	  }
	 
	  int height()
	  {
		  return getheight(root);
	  }
	  int getheight(Node<T1>* node)
	  {
		  if (node == NULL)
			  return -1;
		  else
		  {
			  int leftheight = getheight(node->left);
			  int rightheight = getheight(node->right);
			  if (leftheight > rightheight)
			  {
				  return leftheight + 1;
			  }
			  else
			  {
				  return rightheight + 1;
			  }
		  }

	  }

	  bool isBalanced()
	  {
		  if (getBalance(root) >= -1 || getBalance(root) <= 1)
			  return true;
		  else false;

	  }
	  int getBalance(Node<T1>* T)
	  {
		  if (T == NULL)
			  return 0;
		  return getheight(T->left) - getheight(T->right);
	  }

	  bool isEmpty()
	  {
		  return root == NULL;
	  }
	  void display()
	  {
		  Inorder(root);
	  }
	  void displayInOrder()
	  {
		  Inorder(root);
	  }
	  
	  
	  void Inorder(Node<T1>* root)
	  {
		  if (root)
		  {
			  Inorder(root->getleft());
			  cout << root->getData() << " ";
			  Inorder(root->getright());
		  }
		  else
			  cout << endl;
	  }
	  Node<T1>* minValueNode(Node<T1>* node)
	  {
		  Node<T1>* current = node;
		  while (current->left != NULL)
			  current = current->left;
		  return current;
	  }
	  void delNode(T1 data)
	  {
		  deleteNode(root, data);
	  }
	  Node<T1>* deleteNode(Node<T1>* root, T1 data)
	  {
		  if (root == NULL)
			  return root;
		  if (data < root->data)
			  root->left = deleteNode(root->left, data);
		  else if (data > root->data)
			  root->right = deleteNode(root->right, data);
		  else
		  {
			  if ((root->left == NULL) ||
				  (root->right == NULL))
			  {
				  Node<T1>* temp = root->left ?
					  root->left :
					  root->right;
				  if (temp == NULL)
				  {
					  temp = root;
					  root = NULL;
				  }
				  else
					  *root = *temp;
				  free(temp);
			  }
			  else
			  {
				  Node<T1>* temp = minValueNode(root->right);
				  root->data = temp->data;
				  root->right = deleteNode(root->right,
					  temp->data);
			  }
		  }
		  if (root == NULL)
			  return root;
		  root->height = 1 + max(height(root->left),height(root->right));
		  int balance = getBalance(root);
		  if (balance > 1 &&
			  getBalance(root->left) >= 0)
			  return SingleRotateWithright(root);
		  if (balance > 1 && getBalance(root->left) < 0)
		  {
			  root->left = SingleRotateWithleft(root->left);
			  return SingleRotateWithright(root);
		  }
		  if (balance < -1 && getBalance(root->right) <= 0)
			  return SingleRotateWithleft(root);
		  if (balance < -1 && getBalance(root->right) > 0)
		  {
			  root->right = SingleRotateWithright(root->right);
			  return SingleRotateWithleft(root);
		  }
		  return root;
	  }


	  ~AVLTree()
	  {
		  deleteNodes(root);
	  }
	  void deleteNodes(Node<T1>* root)
	  {
		  if (root)
		  {
			  deleteNodes(root->getleft());
			  deleteNodes(root->getright());
			  delete root;
		  }
	  }

};