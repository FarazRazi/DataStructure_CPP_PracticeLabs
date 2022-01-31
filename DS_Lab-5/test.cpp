#include "pch.h"
#include "Header.h"

#include <iostream>
using namespace std;

TEST(Insert, T1) {
    LinkedList<int> obj;
    int arr[] = { 0,1,2,3,4,5,6,7 };
    for (int i = 0; i < 8; i++)
    {

        obj.insert(arr[i]);
    }
    Node<int>* temp = obj.getHead();
    int i = 0;
    while (temp->getNext() != NULL) {
        EXPECT_EQ(arr[i], temp->getData());
        temp = temp->getNext();
        i++;
    }

}

TEST(InsertatHead, T2) {
    LinkedList<int> obj;
    int arr[] = { 0,1,2,3,4 };
    for (int i = 0; i < 5; i++)
    {
        obj.insert(arr[i]);
    }

    Node<int>* temp = obj.getHead();
    int i = 0;
    while (temp->getNext() != NULL) {
        EXPECT_EQ(temp->getData(), arr[i]);
        temp = temp->getNext();
        i++;
    }
    temp = obj.getHead();
    obj.insertAtHead(66);
    EXPECT_EQ(66, obj.getHead()->getData());
    temp = obj.getHead()->getNext();
    int j = 0;
    while (temp->getNext() != NULL) {
        EXPECT_EQ(temp->getData(), arr[j]);
        temp = temp->getNext();
        j++;
    }
}

TEST(InsertAtIndex, T3) {
    int arr[] = { 0,1,2,3 };
    int expec[] = { 0,1,2,3,5 };
    LinkedList<int> obj1;
    for (int i = 0; i < 4; i++)
    {
        obj1.insert(arr[i]);
    }

    obj1.insertAtIndex(5, 4); // InsertAtIndex(5 is the value to be inserted, 4 is the Index.no);
    Node<int>* temp = obj1.getHead();
    int j = 0;
    while (temp->getNext() != NULL) {
        EXPECT_EQ(temp->getData(), expec[j]);
        temp = temp->getNext();
        j++;
    }
    obj1.print();
}
 
TEST(InsertAtIndex, T4) {
    int arr[] = { 0,1,2,4 };
    int expec[] = { 0,1,2,3,4 };
    LinkedList<int> obj1;
    for (int i = 0; i < 4; i++)
    {
        obj1.insert(arr[i]);
    }

    obj1.insertAtIndex(3, 3); // InsertAtIndex(5 is the value to be inserted, 4 is the Index.no);
    Node<int>* temp = obj1.getHead();
    int j = 0;
    while (temp->getNext() != NULL) {
        EXPECT_EQ(temp->getData(), expec[j]);
        temp = temp->getNext();
        j++;
    }
    obj1.print();
}

TEST(Search, T5) {

    LinkedList<int> obj1;
    for (int i = 0; i < 3; i++)
    {
        obj1.insert(i);
    }
    EXPECT_EQ(2, obj1.search(2));
    ASSERT_NE(3, obj1.search(2));
}

TEST(Update, T6) {
    LinkedList<int> obj;
    for (int i = 0; i < 5; i++)
    {

        obj.insert(i);
    }
    obj.update(3, 67);//replace 3 with 67
    Node<int>* temp = obj.getHead();
    int i = 0;
    int arr[] = { 0,1,2,67,4 };
    while (temp->getNext() != NULL) {
        EXPECT_EQ(arr[i], temp->getData());
        temp = temp->getNext();
        i++;
    }
    obj.print();

}

TEST(Delete, T7) {
    LinkedList<int> obj;

    for (int i = 0; i < 5; i++)
    {
        obj.insert(i);
    }
    obj.remove(0);
    int arr[] = { 0,1,2,4 };
    obj.print();
    Node<int>* temp = obj.getHead();
    int i = 0;
    while (temp->getNext() != NULL) {
        EXPECT_EQ(temp->getData(), arr[i]);
        temp = temp->getNext();
        i++;
    }
}

//////////////////////q2/////////////////////

TEST(mergeList, T8) {
    LinkedList<int> obj1, obj2;
    int arr1[] = { 1,3,5,7 };
    for (int i = 0; i < 4; i++)
    {
        obj1.insert(arr1[i]);
    }

    int arr2[] = { 2,4,6,8 };
    for (int i = 0; i < 4; i++)
    {
        obj2.insert(arr2[i]);
    }

    obj1.mergeLists(obj2);
    int arr3[] = { 1,2,3,4,5,6,7,8 };

    Node<int>* temp = obj1.getHead();
    int i = 0;
    while (temp->getNext() != NULL) {
        EXPECT_EQ(temp->getData(), arr3[i]);
        temp = temp->getNext();
        i++;
    }

    obj1.print();
}

////////////////////// q3 ///////////////////
TEST(Palindrome, T9) {
    LinkedList<char> P;
    char pal[] = "madam";
    for (size_t i = 0; i < 5; i++)
    {
        P.insert(pal[i]);
    }
    EXPECT_TRUE(true, P.isPalindrome());
}