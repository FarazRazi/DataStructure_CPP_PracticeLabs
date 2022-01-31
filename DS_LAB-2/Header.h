#pragma once
#include<string>
using namespace std;
void duplicate(int* ptr, int* arr, int s)
{
	for (int i = 0; i < s; i++)
	{
		*(ptr + i) = *(arr+i);
	}
}
string isUpperOrLowerD(int M[][3], int row , int col)
{
	int count_u = 0, count_l = 0;
	for (int i = 1; i < row ; i++)
	{
		for (int  j = 0; j < i ; j++)
		{
			if(* (*(M + i) + j) == 0)
				count_u++;

			for (int i = 1; i < row; i++)
			{
				for (int j = i+1 ; j < row; j++)
				{
					if (*(*(M + i) + j) == 0)
					count_l++;

				}
			}
		}
	}
	if(count_u == 3)
	return "upper"; 
	if (count_l == 3)
	return "lower";
}
bool isPalindrom(char* p) 
{
	int up = sizeof(p) - 1 , low = 0;
	if(*(p+low)!=*(p+up))
		return false;
	low++;
	up++;
}

char* toCapital(char* name)
{
	int i = 0;
	while (*(name + i) != '\0')
	{
		if (*(name + i) >= 97 && *(name + i) <= 122)
		{
			*(name + i) = *(name + i) - 32;
		}
		i++;
	}
	return name;

	
}

