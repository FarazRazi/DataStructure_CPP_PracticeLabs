//Name Faraz Razi
// Roll# i201866
// DS LAB # 5
// 
//
#include <iostream>
using namespace std;
template <typename T>
class Node
{
public:
	T data;
	Node<T>* next;
	Node<T>* getNext()
	{
		return next;
	}
	T getData()
	{
		return data;
	}

};
template <class T>
class LinkedList
{
public:
	LinkedList()
	{
		head = NULL;
	}
	LinkedList(Node<T>* head)
	{
		this->head = head;
	}
	bool isEmpty()
	{
		return head == NULL;
	}
	void insert(T Value)
	{
		Node<T>* newNode = new Node<T>();

		newNode->data = Value;

		newNode->next = NULL;

		if (isEmpty())
			head = newNode;
		else
		{
			Node<T>* temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}
	void insertAtHead(T Value)
	{
		Node<T>* newNode = new Node<T>();

		newNode->data = Value;
		newNode->next = head;
		head = newNode;
	}
	void insertAtIndex(int index, T Value)
	{
		if (index < 0)
			return;
		int currIndex = 1;
		Node<T>* current = head;
		while (current && index > currIndex)
		{
			current = current->next;
			currIndex++;
		}
		if (index > 0 && current == NULL)
			return;

		Node<T>* newNode = new Node<T>;
		newNode->data = Value;
		if (index == 0)//For first header
		{
			newNode->next = head;
			head = newNode;
		}
		else		//for any index
		{
			newNode->next = current->next;
			current->next = newNode;
		}
	}
	int search(T Value)
	{
		Node<T>* current = head;
		int index = 0;
		while (current != NULL)
		{
			if (current->data == Value)
				return index;
			current = current->next;
			index++;
		}
	}
	void print()
	{
		Node<T>* current = head;
		while (current != NULL)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
	void update(T org, T rep)
	{
		Node<T>* current = head;
		while (current != NULL)
		{
			if (current->data == org)
			{
				current->data = rep;
				return;
			}
			current = current->next;
		}
	}
	void remove(T Value)
	{
		Node<T>* previous = NULL;
		Node<T>* current = head;
		while (current && current->data != Value)
		{
			current = current->next;
		}
		if (current)
		{
			if (previous)
			{
				previous->next= current->next;
				delete current;
			}
			else //remove head
			{
				head = current->next;
				delete current;
			}
		}
	}
	void mergeLists(const LinkedList<T>& LL2)
	{
		Node<T>* current = head;
		while (current != NULL)
		{
			current = current->next;
		}
		Node<T>* current_2 = LL2.head;

		while (current_2 != NULL)
		{
			insert(current_2->data);
			current_2 = current_2->next;
		}
		bubbleSort(head);


	}
	void bubbleSort(Node<T>* start)
	{
		int swapped, i;
		Node<T>* current;
		Node<T>* end = NULL;
		/* Checking for empty list */
		if (start == NULL)
			return;

		do
		{
			swapped = 0;
			current = start;

			while (current->next != end)
			{
				if (current->data > current->next->data)
				{
					swap(current, current->next);
					swapped = 1;
				}
				current = current->next;
			}
			end = current;
		} while (swapped);
	}
	void swap(Node<T>* a, Node<T>* b)
	{
		int temp = a->data;
		a->data = b->data;
		b->data = temp;
	}
	bool isPalindrome()
	{
		T* s1, s2;
		recursiveFunc(head,s1, s2);

		return s1 == s2;
		
	}
	void recursiveFunc(Node<T> temp,T &s1, T& s2)
	{
		if (temp == NULL)
		{
			return;
		}
		s1 += temp->data;
		recursiveFunc(temp->next, s1, s2);
		s2 += temp->data;
	}
	//Getter Setter
	Node<T>* getHead()
	{
		return head;
	}


private:
	Node<T>* head;
};
