//Name:    Faraz Razi
//Roll#:   i201866
//DS_Lab#: 4
#pragma once
#include "iostream"
using namespace std;

////////////////////////////// Q1///////////////////////////
template <class T>
class List
{
public:
	List()
	{
		ptr = new T[];
		count = 0;
	}
	List(int S)
	{
		cap = S;
		ptr = new T[cap];
		count = 0;
	}
	bool insert(T V)
	{

		if (isFull())
			return false;

		ptr[count++] = V;
		return true;

	}
	bool insertAt(T V, int P)
	{
		if (isFull())
			return false;
		
		
		T* temp = new T[count++];
		for (int i = 0; i < count; i++)
		{
			if (i == P)	//index matches
			{			//Replace
				temp[P] = V;

			}
			else if (i < P)
			{
				temp[i] = ptr[i];
			}
			else
			{
				temp[i] = ptr[i - 1];
			}
			
		}
		delete[] ptr;
		ptr = temp;
		temp = NULL;
		return true; 
	}
	void insertAfter(T Value, T Replace)
	{
		int P = search(Replace);
		insertAt(Value, P + 1);
	}
	void insertBefore(T Value, int Replace)
	{
		int P = search(Replace);
		insertAt(Value, P);
	}
	void remove(T V)
	{
		if (isEmpty())
			return;

		int P = search(V);

		T* temp = new T[count];
		for (int i = 0; i < count; i++)
		{
			if (i == P)	//index matches
			{			//Replace
				temp[P] = ptr[i+1];

			}
			else if (i < P)
			{
				temp[i] = ptr[i];
			}
			else//i>p
			{
				temp[i-1] = ptr[i];
			}

		}
		count--;
		delete[] ptr;
		ptr = temp;
		temp = NULL;
		//return true;

	}
	void removeBefore(T V)
	{
		//-1 for before
		int P = search(V)-1;
		//p-- for decrement as it is index
		remove(ptr[P--]);
	}
	void removeAfter(T V)
	{
		// for after
		int P = search(V) + 1 ;
		//p-- for decrement as it is index
		remove(ptr[P--]);
	}
	void reverse()
	{
		T* temp = new T[count];
		for (int i = 0; i < count; i++)
		{
			temp[i] = ptr[count - i - 1];
		}
		delete[] ptr;
		ptr = temp;
		temp = NULL;
	}
	
	bool isFull()
	{
		if (count >= cap)
			return true;
		else
			return false;
	}
	bool isEmpty()
	{
		if (count <= 0)
			return true;
		else
			return false;
	}
	int search(T V)
	{
		for (int i = 0; i < count; i++)
		{
			if (ptr[i] == V)
			{
				return i;
			}
		}
	}
	void print()
	{
		for (int i = 0; i < count; i++)
		{
			cout << ptr[i] << " ";

		}
		cout << "\n";
	}
	T* getValues()
	{
		return ptr;
	}

	bool operator == (List& L)
	{
		if (count != L.count)
			return false;
		for (int i = 0; i < count; i++)
		{
			if (ptr[i] != L.ptr[i])
				return false;
		}
		return true;
	}
	~List()
	{
		ptr = NULL;
	}
private:
	T* ptr;
	int cap;
	int count;

};

////////////////////////////// Q2///////////////////////////

bool EmailValidation(string str)
{
	/*int str_lenght = sizeof(str);
	bool pre = false,dom=false,c=false;

	string prefix, domain, com;
	if (str[0] < 'A' && str[0] > 'Z')
		return false;
	int i = 0;
	int j = 0;
	while (str[i] != '\0')
	{
		if(str[i]!='@'&& pre !=true)
			prefix[i] = str[i];
		else if(str[i] != '.' && dom != true)
			domain[i] = str[i];
		else if (c != true)
			domain[i] = str[i];
		i++;
	}
	i = 0;
	int countS = 0;
	bool consective=false;
	bool last = false;
	while (prefix[i] != '\0')
	{
		if (prefix[i] == ',' || prefix[i] == '.' || prefix[i] == '_')
			countS++;
		if ((prefix[i] == ',' || prefix[i] == '.' || prefix[i] == '_') == (prefix[i + 1] == ',' || prefix[i + 1] == '.' || prefix[i + 1] == '_'))
			consective = true;
		if (prefix[sizeof(prefix)] != ',' || prefix[sizeof(prefix)] != '.' || prefix[sizeof(prefix)] != '_')
			last = true;
	}

	if (countS == 3 && consective == false && last == false)
		return true;
	else*/
		return false;
		

}

bool PasswordValidation(string str)
{
	int str_lenght = sizeof(str);
	bool up = false, digit = false, Special = false;

	if (str_lenght < 5 && str_lenght >11)
		return false;
	int i = 0;
	while (str[i]!='\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			up = true;
		if (str[i] >= '0' && str[i] <= '9')
			digit = true;
		if (str[i] == '@' && str[i] >= '!' && str[i] <= '/')
			Special = true;
		i++;
	}

	if (up && digit && Special)
		return true;
	else
		return false;

}