#include <iostream>
using namespace std;

template <typename T1, typename T2>
class node
{
private:
	T1 EmpID;
	T1 CNIC;
	T1 Join_Date;
	T2 Salary;
	T2 Bonus;
	node* next;
	node* prev;
public:
	node()
	{

	}
	node(T1 ID, T1 CNIC, T1 J_Date, T2 Sal, T2 B)
	{
		this->EmpID = ID;
		this->CNIC = CNIC;
		this->Join_Date = J_Date;
		this->Salary = Sal;
		this->Bonus = B;
	}
	node* getnext()
	{
		return next;
	}
	node* getprev()
	{
		return prev;
	}
	void setnext(node* next)
	{
		this->next = next;
	}
	void setprev(node* prev)
	{
		this->prev = prev;
	}
	T1 getId()
	{
		return EmpID;
	}
	T1 getCNIC()
	{
		return CNIC;
	}
	T1 getJoinDate()
	{
		return Join_Date;
	}
	T2 getSal()
	{
		return Salary;
	}
	void setSal(T2 Sal)
	{
		Salary = Sal;
	}
	T2 getBonus()
	{
		return Bonus;
	}
};
template <typename T1, typename T2>
class linkList
{
public:
	linkList()
	{
		head = NULL;
	}
	bool isEmpty()
	{
		return head == NULL;
	}
	void insert(T1 ID, T1 CNIC, T1 J_Date, T2 Sal, T2 B)
	{
		node<T1, T2>* newEMP = new node<T1, T2>(ID, CNIC, J_Date, Sal, B);


		newEMP->setnext(NULL);


		if (isEmpty())
		{
			head = newEMP;
			tail = newEMP;
		}
		else
		{
			tail->setnext(newEMP);
			newEMP->setprev(tail);
			tail = newEMP;
		}
	}
	bool search(T1 ID_check)
	{
		node<T1, T2>* current = head;
		while (current)
		{
			if (current->getId() == ID_check)
			{
				return true;//Return true
			}
			current = current->getnext();
		}
		return false;//Return False
	}
	void remove(T1 ID)
	{
		node<T1, T2>* current = head;
		while (current && current->getId() != ID)
		{
			current = current->getnext();
		}
		if (current)
		{
			if (current == tail)//LAST
			{
				tail = current->getprev();
				current->getprev()->setnext(NULL);
				delete current;
			}
			else if (current->getprev())//MID
			{
				current->getprev()->setnext(current->getnext());
				current->getnext()->setprev(current->getprev());
				delete current;
			}

			else //remove head //First
			{
				head = current->getnext();
				delete current;
			}
		}
	}
	void print()
	{
		node<T1, T2>* current = head;

		while (current != NULL)
		{
			cout << "-------------DISPLAY EMPloyee-------- - " << endl;

			cout << "ID : " << current->getId() << "\n";
			cout << "CNIC : " << current->getId() << "\n";
			cout << "Joining Date : " << current->getJoinDate() << "\n";
			cout << "Salary : " << current->getSal() << "\n";
			cout << "Bonus : " << current->getBonus() << "\n\n";

			current = current->getnext();
		}
		cout << endl;
	}
	void UpdateSalary(T1 ID, T2 newSal)
	{
		node <T1, T2>* current = head;
		while (current != NULL)
		{
			if (current->getId() == ID)
			{
				current->setSal(newSal);
			}
			current = current->getnext();
		}
	}
	void MaximumSalary()
	{
		node <T1, T2>* current = head;
		T2 max = 0;
		T1 max_id;
		while (current != NULL)
		{
			if (current->getSal() > max)
			{
				max = current->getSal();
				max_id = current->getId();
			}
			current = current->getnext();
		}
		cout << "\n Maximum Salary is : " << max;
		cout << "\n Maximum Salary Employee is : " << max_id << endl;

	}
	node<T1, T2>* gethead()
	{
		return head;
	}
	node<T1, T2>* gettail()
	{
		return tail;
	}
private:
	node<T1, T2>* head;
	node<T1, T2>* tail;
};
int main()
{
	linkList<string, int> obj;
	string id = "01";
	string c = "45678-4535676-0";
	string j = "18/10/2021";
	int k = 50000;
	int b = 5000;
	string id2 = "02";
	string c2 = "45778-4535676-0";
	string j2 = "18/10/2020";
	int k2 = 10000;
	int b2 = 5000;
	string id3 = "03";
	string c3 = "45878-4535676-0";
	string j3 = "18/10/2019";
	int k3 = 20000;
	int b3 = 5000;

	obj.insert(id, c, j, k, b);
	obj.insert(id2, c2, j2, k2, b2);
	obj.insert(id3, c3, j3, k3, b3);

	obj.print();

	obj.remove("02");

	cout << " / / / / / / // / / / / / / // / / / / / // / REMOVE (\"02\")/ / / / / / / // / / / / / / / / / // / / /\n" << endl;

	obj.print();

	obj.UpdateSalary("01", 60000);

	cout << " / / / / / / // / / / / / / // / / / / / // / Update (\"01,60000\")/ / / / / / / // / / / / / / / / / // / / /\n" << endl;

	obj.print();

	cout << " / / / / / / // / / / / / / // / / / / / // / Search (\"01\")/ / / / / / / // / / / / / / / / / // / / /\n" << endl;

	if (obj.search("01"))
		cout << "Found" << endl;
	else
		cout << "Not Found" << endl;
}

/////////////////////////////////Q2/////////////////////////////////////////////
//#include <iostream>
//using namespace std;
//class people
//{
//public:
//	static int num;
//	int value;
//	people* next;
//	people()
//	{
//		value = num;
//		num++;
//	}
//};
//
//class Jose_Prob
//{
//public:
//	Jose_Prob()
//	{
//		head = NULL;
//	}
//	bool isEmpty()
//	{
//		return head == NULL;
//	}
//	void insert()
//	{
//		people* P = new people;
//		if (isEmpty())
//		{
//			head = P;
//			tail = P;
//			tail->next = NULL;
//		}
//		else
//		{
//			tail->next = P;
//			P->next = head;
//			tail = P;
//		}
//
//	}
//	//void remove(int data)
//	//{		
//	//	if (head == NULL)
//	//			return;
//
//	//	if (head->value == data && head->next == head)
//	//	{
//	//		free(head);
//	//		head = NULL;
//	//		return;
//	//	}
//
//	//	people* last = head,  *d;
//
//	//	if (head->value == data)
//	//	{
//
//	//		while (last->next != head)
//	//			last = last->next;
//
//	//		last->next = head->next;
//	//		free(head);
//	//		head = last->next;
//	//	}
//
//	//	// Either the node to be deleted is not found
//	//	// or the end of list is not reached
//	//	while (last->next != head && last->next->value!= data)
//	//	{
//	//		last = last->next;
//	//	}
//
//	//	// If node to be deleted was found
//	//	if (last->next->value == data)
//	//	{
//	//		d = last->next;
//	//		last->next = d->next;
//	//		free(d);
//	//	}
//	//	else
//	//		cout << "no such keyfound";
//	//
//
//	//}
//	void print()
//	{
//		people* current = head;
//
//		do
//		{
//			cout << "number : " << current->value << endl;
//			current = current->next;
//		} while ((current != head));
//		cout << endl;
//	}
//
//private:
//	people* head;
//	people* tail;
//};
//int people::num = 0;
/////////////////////////////////////////////////////////////Q2//////////////////////////////////////////////////////////////