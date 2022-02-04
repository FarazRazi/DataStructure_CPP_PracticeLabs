#pragma once
//
// Name: Faraz Razi 
// Roll: i20-1866
// DS-Lab 
// Lab#: 07
//

#include <iostream>
using namespace std;

template <typename T>
class Node
{
	T data;
	Node<T>* next;
public:
	void setData(T data)
	{
		this->data = data;
	}
	void setNext(Node* next )
	{
		this->next = next;
	}
	T getData()
	{
		return this->data;
	}
	Node* getNext()
	{
		return this->next;
	}
	
};

class Task
{
	int id;
	int time;
public:
	Task()
	{
		id = 0;
		time = 0;
	}
	Task (int id, int time)
	{
		this->id = id;
		this->time = time;
	}
	Task(Task& N)
	{
		this->id = N.getID();
		this->time = N.getTime();
	}
	void setID(int data)
	{
		this->id = data;
	}
	int getID()
	{
		return this->id;
	}
	void setTime(int data)
	{
		this->time = data;
	}
	int getTime()
	{
		return this->time;
	}
};
template <typename T>
class Queue
{
public:
	Queue()
	{
		front = NULL;
		rear = NULL;
	}
	void enqueue(T data)
	{
		Node<T>* newNode = new Node<T>;
		newNode->setData(data);
		newNode->setNext(NULL);
		//new queue
		if (isEmpty()) {
			front = newNode;
			rear = newNode;
		}
		//next node in queue
		else {
			rear->setNext(newNode);
			rear = newNode;
		}
	}
	void dequeue()
	{
		Node<T>* temp;
		if (isEmpty())
			return ;
		else {
			temp = front->getNext();
			delete front;
			front = temp;
			if (front == NULL)
				rear = NULL;

		}
		

	}
	T Front()
	{
		return front->getData();
	}
	bool isEmpty(void)
	{
			if (front == NULL && rear == NULL)
				return true;
			else
				return false;
	}


		Node<T>* getRear()
		{
			return rear;
		}
		Node<T>* getFront()
		{
			return front;
		}
	private:

		Node<T>* front;
		Node<T>* rear;

};
////////////////////// Q2 ////////////////////////

void roundRobin(Queue<Task> q1,int Time) {

	int remain_time;
	int execution_time;
	while (!q1.isEmpty())
	{
		Task t1 (q1.Front());
		q1.dequeue();
		execution_time = t1.getTime();
		remain_time=execution_time- Time;
		t1.setTime(remain_time);
		if (remain_time > 0)
		//rescheduled
		{
			cout << "Execution Time: " << execution_time << endl;
			cout << "Remaining Time: " << remain_time << endl;
			cout << "Task is not completed, it is being re-scheduled" << endl;
			q1.enqueue(t1);
		}
		else
		//remove
		{
			cout << "Execution Time: " << execution_time << endl;
			cout << "Remaining Time: " << remain_time << endl;
			cout << "Task is completed, it is removed from the queue" << endl;
		}
	}
}
////////////////////// Q3 ////////////////////////
Queue<char> queueConcat(string str)
{
	Queue<char> obj ;
	int i = 0;
	while (str[i] != 0)
	{
		if (str[i] != ' ')
			obj.enqueue(str[i++]);
		else
			i++;
	}
	return obj;
}
