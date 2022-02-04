#pragma once
#include <iostream>
using namespace std;
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
			return;
		Node<T>* newNode = head;
		head = head->next;
		delete newNode;
		size--;
	}
	T Peek()
	{
		return head->data;
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
		return head==NULL;
	}
};
template <typename T>
int stack<T>::size = 0;

char* clean(char* arr,int size)
{
	int i = 0;
	stack <char>tempStack;
	char* newchar= new char[size];
	while (arr[i] != '\0')
	{
		if (arr[i] >= 'A' && arr[i] <= 'Z' || arr[i] >= 'a' && arr[i] <= 'z')
		{
			if (arr[i] >= 'a' && arr[i] <= 'z')
			{
				arr[i] -= 32;
			}
			tempStack.push(arr[i]);
		}
		i++;
	}
	i = 0;
	while (!tempStack.isEmpty())
	{
	
			newchar[i] = tempStack.Peek();
			tempStack.pop();
			i++;
	}
	newchar[i] = '\0';

	return newchar;
}
bool checkPal(string str)
{
	int i = 0;
	int size=str.length();
	char* arr = new char[str.length()];
	while (str[i]!='\0')
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
	char* newchar = clean(arr, size);
	size = 0;

	stack <char>tempStack;

	while (newchar[size] != '\0')
	{
		tempStack.push(newchar[size++]);
	}
	i = 0;
	while (!tempStack.isEmpty())
	{
		if (newchar[i++] !=tempStack.Peek())
			return false;
		tempStack.pop();
	}

	return true;
}