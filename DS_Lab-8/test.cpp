#include "pch.h"
//include header file
#include "Header.h"
using namespace std;

stack <int> s1; // create object of stack class

TEST(task1, T1) {
    s1.push(1);
    s1.push(2);
    s1.push(3);
    EXPECT_EQ(3, s1.Peek());
}

TEST(task1, T2) {
    s1.pop();
    EXPECT_EQ(2, s1.Peek());
    s1.pop();
    EXPECT_EQ(1, s1.Peek());

}
TEST(task1, T3) {
    s1.push(3);
    s1.push(4);
    EXPECT_EQ(3, s1.sizeofstack());// if size is key word change it it sizeOfQueue.
}

TEST(task2, T4) {
    char str[] = "M A%! DAm#";
    EXPECT_TRUE(checkPal(str));
}

TEST(task2, T5) {
    char str[] = "% Universi ty % ";
    EXPECT_FALSE(checkPal(str));
}