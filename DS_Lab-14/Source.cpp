
#include <iostream>
using namespace std;

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
class adjacencyList
{
public:
	Node<T>* head;
	adjacencyList()
	{
		head = NULL;
	}
	void insert(T data)
	{
		Node<T>* newNode = new Node<T>;
		newNode->data = data;

		newNode->next = NULL;

		if (!isEmpty())
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
	void display()
	{
		Node<T>* curr = new Node<T>;
		curr = head;
		while (curr)
		{
			cout << curr->data << "-->";
			curr = curr->next;
		}
		delete curr;
	}
	bool isEmpty()
	{
		if (head == NULL)
			return false;
		else
			return true;
	}
};
template <typename T>
class Graph
{

public:
	adjacencyList<T>* adjList;
	int maxVertices;
	int matrix[5][5];
	Graph()
	{
		adjList = NULL;
		maxVertices = 0;
	}
	Graph(int v)
	{
		maxVertices = v;
		adjList = new adjacencyList<T>[maxVertices];
	}
	void addVertex(Node<T>* newVertex)
	{
		adjacencyList<T>* temp = new adjacencyList<T>;
		temp->head = newVertex;
		temp->head->next = NULL;

		for (int i = 0; i < maxVertices; i++)
		{
			if (adjList[i].head == NULL)
			{
				adjList[i].head = temp->head;
				break;
			}
		}
	}
	void addedge(int source, T target, int wieght)
	{
		adjList[source - 1].insert(target);
		matrix[source - 1][target - 1] = wieght;
	}
	void showGraph()
	{
		for (int i = 0; i < maxVertices; i++)
		{
			if (adjList[i].head != NULL)
			{
				adjList[i].display();

				cout << "NULL\n";
			}
		}
	}
	void showMatrix()
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}


};

int main()
{
	Graph<int> G(5);
	
	Node<int> N1;
	N1.data = 1;
	Node<int> N2;
	N2.data = 2;
	Node<int> N3;
	N3.data = 3;
	Node<int> N4;
	N4.data = 4;
	Node<int> N5;
	N5.data = 5;
	
	G.addVertex(&N1);
	G.addVertex(&N2);
	G.addVertex(&N3);
	G.addVertex(&N4);
	G.addVertex(&N5);
	
	G.addedge(1, 3,6);
	G.addedge(1, 4,3);
	G.addedge(3, 4,2);
	G.addedge(4, 3,1);
	G.addedge(4, 2,1);
	G.addedge(2, 1,3);
	G.addedge(5, 2,4);
	G.addedge(5, 4,2);

	cout << "Graph\n";
	G.showGraph();
	cout << "Matrix\n";

	G.showMatrix();
}