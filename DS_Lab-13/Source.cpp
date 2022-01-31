#include <iostream>
#include <ctime>

using namespace std;
int delay(int milliseconds) {
	clock_t goal = milliseconds + clock();
	while (goal > clock());
	return 1;
}
#pragma once
//
// Name: Faraz Razi 
// Roll: i20-1866
// DS-Lab 
// Lab#: 13
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
	void setNext(Node* next)
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
			return;
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
class Person
{
public:
	int ID;
	string Rank;
	Person()
	{

	}
	Person(int id, string R)
	{
		this->ID = id;
		this->Rank = R;
	}
};
class Message
{
public:
	string Code;
	Person TO;
	Person From;
	string Direction;
	Message()
	{

	}
	Message(string Code, Person To, Person From, string Direction)
	{
		this->Code = Code;
		this->TO = To;
		this->From = From;
		this->Direction = Direction;
		//Display();
	}
	void Display()
	{
		cout << "( " << Code << " ) " << TO.Rank << " To " << From.Rank << " -- " << Direction << endl;

	}

};


class Troops
{
public:
	Person General;
	Person Captain1;
	Person Captain2;
	Person Captain3;
	Queue<Message> Incomming;
	Queue<Message> Outcomming;
	Troops()
	{

	}
	Troops(Person G, Person C1, Person C2, Person C3)
	{
		this->General = G;
		this->Captain1 = C1;
		this->Captain2 = C2;
		this->Captain3 = C3;
	}
	bool SendMessage(Message M)
	{
		cout << "Sending..." << endl;
		Outcomming.enqueue(M);
		M.Display();
		return true;
	}
	bool RecieveMessage(Message M)
	{
		cout << "Recieve..." << endl;
		Incomming.enqueue(M);
		M.Display();
		return true;
	}
	void RecievingMessage()
	{
		if (Incomming.getFront()->getData().Code == "Attack")
		{
			cout << "Defending...." << endl;
		}
		Incomming.dequeue();
	}
	void SendingMessage()
	{
		if (Outcomming.getFront()->getData().Code == "Attack")
		{
			cout << "Attacking...." << endl;
		}
		else
		{
			cout << "Defending...." << endl;
		}

		Outcomming.dequeue();
	}

};
int main()
{

	cout << "Creating Troops West ..." << endl;
	Person wG(1,"General");
	Person wC1(2, "Captain");
	Person wC2(3, "Captain");
	Person wC3(4, "Captain");
	Troops West(wG, wC1, wC2, wC3);

	cout << "Creating Troops East ..." << endl;
	Person eG(5, "General");
	Person eC1(6, "Captain");
	Person eC2(7, "Captain");
	Person eC3(8, "Captain");
	Troops East(eG, eC1, eC2, eC3);

	cout << "Creating Message ..." << endl;
	Message M1("Attack", wG, eG, "West to East");
	
	West.SendMessage(M1);
	delay(2 * 1000);
	West.SendingMessage();
	delay(2 * 1000);
	East.RecieveMessage(M1);
	delay(2 * 1000);
	East.RecievingMessage();
	delay(2 * 1000);

	cout << "\n\n";
	Message M2("Attack", eG, wG, "East to West");
	delay(2 * 1000);
	East.SendMessage(M2);
	delay(2 * 1000);
	East.SendingMessage();
	delay(2 * 1000);
	West.RecieveMessage(M2);
	delay(2 * 1000);
	West.RecievingMessage();
	delay(2 * 1000);

		


}
