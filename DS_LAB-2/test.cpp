#include "pch.h"


#include "Header.h"

#include <gtest/gtest.h>
using namespace std;
TEST(duplicate, T1) {
    int* arr1 = new int[5];
    int arr[5];
    for (int i = 0; i < 5; i++) arr1[i] = i * 3;
    int* ptr = arr1;
    duplicate(ptr, arr, 5);

    for (int i = 0; i < 5; i++)
    {
        EXPECT_EQ(arr[i], arr1[i]);
    }

}

TEST(duplicate, T2) {
    int* arr1 = new int[10];
    int arr[10];
    for (int i = 0; i < 10; i++) arr1[i] = i * 2 + 11;
    int* ptr = arr1;
    duplicate(ptr, arr, 10);

    for (int i = 0; i < 10; i++)
    {
        EXPECT_EQ(arr[i], arr1[i]);
    }

}
 TEST(diagonal, T1){
     int matrix[3][3]={{1,2,3},{0,3,4},{0,0,10}};
    EXPECT_EQ("upper", isUpperOrLowerD(matrix, 3, 3));
 }

 TEST(diagonal, T2){
     int matrix[3][3]={{1,0,0},{1,2,0},{10,4,10}};
    EXPECT_EQ("lower", isUpperOrLowerD(matrix, 3, 3));
 }
TEST(countPrime, T1) {
    int arr[] = { 9,23,22,7,9,11 };
    int size = 6, count = 0;
    //countPrime(arr, size, count);
    //EXPECT_EQ(3, count);

}

TEST(palindrome, T1) {
    char str[8] = "1223221";
    char* p = str;
    EXPECT_EQ(1, isPalindrom(p));
}
TEST(palindrome, T2) {
    char str[5] = "BABA";
    char* p = str;
    EXPECT_EQ(0, isPalindrom(p));
}

TEST(capital, T1) {
    char str[7] = "tOqEeR";
    char* p = str;
    char* expec = toCapital(p);
    char res[7] = "TOQEER";
    for (size_t i = 0; i < 6; i++)
    {
        EXPECT_EQ(expec[i], res[i]);
    }

}

TEST(capital, T2) {
    char str[12] = "ENVIRONMENT";
    char* p = str;
    char* expec = toCapital(p);// expect a return
    char res[12] = "ENVIRONMENT";
    for (size_t i = 0; i < 12; i++)
    {
        EXPECT_EQ(expec[i], res[i]);
    }

}

TEST(removeDuplicate, T1) {
    int arr[] = { 1,2,3,1,4,5,2 };
    int res[] = { 1,2,3,0,0,0,0 };
    int size = 7;
    //removeDuplicate(arr, size);
    for (size_t i = 0; i < 7; i++)
    {
      //  EXPECT_EQ(arr[i], res[i]);
    }

}
TEST(removeDuplicate, T2) {
    int arr[] = { 1,2,1,1,4,5,2 };
    int res[] = { 1,2,0,0,0,0,0 };
    int size = 7;
    //removeDuplicate(arr, size);
    for (size_t i = 0; i < size; i++)
    {
        //EXPECT_EQ(arr[i], res[i]);
        //EXPECT_EQ(2, size);
    }

}
TEST(sumRow, T1) {
    int matrix[5][5] = { {9,8,1,2,3}
    ,{6,5,0,3,4},
    {1,0,0,10,11}
    ,{2,5,1,7,8},
    {1,6,3,7,0} };
    int arr[] = { 23,18,22,23,17 };
    //int* res = calculateSum(matrix, 5, 5);
    for (size_t i = 0; i < 5; i++)
    {
      //  EXPECT_EQ(arr[i], res[i]);

    }
}
TEST(sortCol, T1) {
    int matrix[5][5] = { {9,8,1,2,3}
   ,{6,5,0,3,4},
   {1,0,0,10,11}
   ,{2,5,1,7,8},
   {1,6,3,7,0} };
    int res[5][5] = { {1,0,0,2,0},
                      {1,5,0,3,3},
                      {2,5,1,7,4},
                      {6,6,1,7,8},
                      {9,8,3,10,11} };

    //sortCols(matrix, 5, 5);
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t i = 0; i < 5; i++)
        {
      //      EXPECT_EQ(matrix[i][j], res[i][j]);
        }

    }
}

TEST(swapRows, T1) {
    int matrix[5][5] = { {9,8,1,2,3}
    ,{6,5,0,3,4},
    {1,0,0,10,11}
    ,{2,5,1,7,8},
    {1,6,3,7,0} };
    int res[5][5] = { {9,8,1,2,3}
   ,{2,5,1,7,8},
   {1,0,0,10,11}
   ,{6,5,0,3,4},
   {1,6,3,7,0} };
    //swapRow(matrix, 5, 5);
    for (size_t i = 0; i < 5; i++)
    {
        for (size_t i = 0; i < 5; i++)
        {
        //    EXPECT_EQ(matrix[i][j], res[i][j]);
        }

    }
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}