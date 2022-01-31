//			 Faraz Uddin Razi
//				Data structure Lab
//						i20-1866


#pragma once
#include <algorithm>    // std::copy


//PART 1
template <typename T1 >
T1 smaller(T1 x, T1 y)
{
	return (x < y) ? x : y;
}
template <typename T1>
T1 smaller(T1 x, T1 y,T1 z)
{
	return std::min(std::min(x, y), z);
}

template <typename T1, typename T2 >
T2 smallest(T1 x, T2 y)
{
	return (x < y) ? x : y;
}

/////////////////////////////////////////////////////////////////////
//Part 2
//PART 2 not working 
//ERROR
/////////////////////////////////////////////////////////////////////
template <typename T1,typename T2 >
T2 sameElement(T1 arr1[], T1 arr2[], int size1, int size2)
{
	T2 arr[10];
	int k = 0;
	cout << "Same Elements are : ";
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (arr1[i] == arr2[j])
				arr[k++] = arr1[i];
		}
	}
	cout << endl;
	return arr;
}
template <typename T1, typename T2 >
T1 concatenateArrays(T1 arr1[], T1 arr2[], int m, int n)
{
	int k = 0;
	int i = 0, j = 0;
	while (i < m && j < n) {
		if (arr1[i] < arr2[j])
			 arr1[k++]=arr1[i++] ;

		else if (arr2[j] < arr1[i])
			arr1[k++]=arr2[j++] ;

		else {
			arr1[k++]=arr2[j++] ;
			i++;
		}
	}

	while (i < m)
		arr1[k++]=arr1[i++] ;

	while (j < n)
		arr1[k++]=arr2[j++] ;
	return arr1;
}
//////////////////////////////////////////////////////////////////////

//PART 3
template <typename T>
class container
{
private:
	T* values;
	int capacity;
	int counter;
public:
	container(int C)
	{
		capacity = C;
		counter = 0;
		values = new T[C];
		for (int i = 0; i < C; i++)
		{
			values[i] = 0;
		}
		
	}
	bool isFull()
	{
		if (counter >= capacity)
			return true;
		else
			return false;

	}
	int insert(T V)
	{
		if (counter < capacity)
		{
			values[counter] = V;
			counter++;
		}
		return 1;
	}
	bool search(T V)
	{
		for (int i = 0; i < counter; i++)
		{
			if (V = values[i])
				return true;
		}
		return false;
	}
	bool remove(T x)
	{
		for (int i = 0; i < counter; i++)
		{
			if (values[i] == x)
			{
				int* newArray = new int[counter - 1];
				std::copy(values,values + i, newArray);
				std::copy(values + i + 1, values + counter, newArray + i);
				delete[] values;
				values = newArray;
				--counter;
				return true;
			}
		}
		return false;
	}
	void print()
	{
		cout << "Printing..." << endl;
		for (int i = 0; i < counter; i++)
		{
			cout << values[i] << " ";
		}
		cout << endl;
	}
	/*~container()
	{
		delete[] values;
	}*/
};
