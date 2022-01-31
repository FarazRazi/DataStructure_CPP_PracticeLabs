#pragma once
///Name : Faraz Razi
//Roll# : i201866
//Lab # : 3 _ DS



                                            //Task # 1
int arraySum(int arr[][5], int m, int n)
{
	int Sum = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Sum += arr[i][j];
        }
    }
	return Sum;
}

int* rowSum(int arr[][4], int m, int n)
{
    int* Sum = new int[m];
    for (int i = 0; i < m; i++)
    {
        Sum[i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Sum[i] += arr[i][j];
        }
    }

    return Sum;

}

int* colSum(int arr[][4], int m, int n)
{
    int* Sum = new int[m];
    for (int i = 0; i < m; i++)
    {
        Sum[i] = 0;
    }

    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            Sum[j] += arr[i][j];
        }
    }

    return Sum;

}
int** transposeMatrix(int arr[][2], int m, int n)
{
    int** ReturnArr = new int* [m] ;
   
    for (int i = 0; i < m; i++)
    {
        ReturnArr[i] = new int [n];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ReturnArr[i][j]= arr[j][i];
        }
    }

    return ReturnArr;
}

                                                    //Task # 2
int** matrixSum(int arr[][3], int arr1[][3], int m, int n)
{
    int** ReturnArr = new int* [m];

    for (int i = 0; i < m; i++)
    {
        ReturnArr[i] = new int[n];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ReturnArr[i][j] = arr[i][j]+ arr1[i][j];
        }
    }
    return ReturnArr;
}

int multiplyMatrix(int arr[][4], int arr1[][4], int m1, int n1,int m2,int n2)
{
    int multSum = 0;
    for (int i = 0; i < m1; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            for (int k = 0; k < m2; k++)
            {
                multSum += arr[i][k] * arr1[k][j];
            }
        }
    }
    return multSum;
}

                                                                    //Task # 3
int leftDiagonalSum(int arr[][4], int m, int n)
{
    int Sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i==j)
            Sum += arr[i][j];
        }
    }
    return Sum;
}
    
int rightDiagonalSum(int arr[][4], int m, int n)
{
    int Sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j==n-i-1)
                Sum += arr[i][j];
        }
    }
    return Sum;
}
                                    //Task #4
int* displayMiddleRow(int arr[][5], int m)
{
    int* Row = new int [m] {0};
    for (int i = 0; i < m; i++)
    {
        if (i == (m / 2))
        for (int j = 0; j < m; j++)
        {
            
            Row[j] += arr[i][j];
        }
    }
    return Row;
}
int* displayMiddleCol(int arr[][5], int m)
{
    int* Col = new int [m] {0};
    for (int j = 0; j < m; j++)
    {
        if (j == (m / 2))
            for (int i = 0; i < m; i++)
            {

                Col[i] += arr[i][j];
            }
    }
    return Col;
}