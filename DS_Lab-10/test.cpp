#include "pch.h"
#include "Header.h"
#include<iostream>
using namespace std;

TEST(TestCaseDelete, T1) {
	Node<string, int> node1("ahmad", 14);
	Node<string, int> node2("nabeel", 11);
	Node<string, int> node3("azam", 13);
	Node<string, int>node4("gohar", 9);
	Node<string, int>node5("Neil", 12);
	Node<string, int>node6("John", 17);
	Node<string, int>node7("Doe", 3);

	Tree<string, int> bst;
	bst.insert(node1);
	bst.insert(node2);
	bst.insert(node3);
	bst.insert(node4);
	bst.insert(node5);
	bst.insert(node6);
	bst.insert(node7);
	bst.remove(3);
	bst.display();


}

TEST(TestCaseDelete, T2) {
	Node<string, int> node1("ahmad", 12);
	Node<string, int> node2("nabeel", 5);
	Node<string, int> node3("azam", 15);
	Node<string, int>node4("gohar", 13);
	Node<string, int>node5("Neil", 14);
	Node<string, int>node6("John", 17);
	Node<string, int>node7("Doe", 20);

	Tree<string, int> bst;
	bst.insert(node1);
	bst.insert(node2);
	bst.insert(node3);
	bst.insert(node4);
	bst.insert(node5);
	bst.insert(node6);
	bst.insert(node7);
	bst.remove(15);
	bst.display();


}

TEST(TestCaseRetrieve, T3) {
	Node<string, int> node1("ahmad", 2);
	Node<string, int> node2("nabeel", 1);
	Node<string, int>node3("gohar", 4);
	Node<string, int>node4("Neil", 3);
	cout << "hello";

	Tree<string, int> bst;
	bst.insert(node1);
	bst.insert(node2);
	bst.insert(node3);
	bst.insert(node4);
	bool flag = bst.retrieve(3);
	EXPECT_EQ(true, flag);

}

TEST(TestCaseRetrieve, T4) {
	Node<string, int> node1("ahmad", 2);
	Node<string, int> node2("nabeel", 1);
	Node<string, int>node3("gohar", 4);
	Node<string, int>node4("Neil", 3);
	Tree<string, int> bst;
	bst.insert(node1);
	bst.insert(node2);
	bst.insert(node3);
	bst.insert(node4);
	bool flag = bst.retrieve(9);
	EXPECT_EQ(false, flag);

}

TEST(TestCaseInOrder, T5) {
	Node<string, int> node1("ahmad", 2);
	Node<string, int> node2("nabeel", 1);
	Node<string, int>node3("gohar", 5);
	Node<string, int>node4("Neil", 3);
	Node<string, int>node5("John", 4);

	Tree<string, int> bst;
	bst.insert(node1);
	bst.insert(node2);
	bst.insert(node3);
	bst.insert(node4);
	bst.insert(node5);
	bst.displayInOrder();

}

TEST(TestCasePreOrder, T6) {
	Node<string, int> node1("ahmad", 2);
	Node<string, int> node2("nabeel", 1);
	Node<string, int>node3("gohar", 5);
	Node<string, int>node4("Neil", 3);
	Node<string, int>node5("John", 4);

	Tree<string, int> bst;
	bst.insert(node1);
	bst.insert(node2);
	bst.insert(node3);
	bst.insert(node4);
	bst.insert(node5);
	bst.displayPreOrder();
}

TEST(TestCasePostOrder, T7) {
	Node<string, int> node1("ahmad", 2);
	Node<string, int> node2("nabeel", 1);
	Node<string, int>node3("gohar", 5);
	Node<string, int>node4("Neil", 3);
	Node<string, int>node5("John", 4);

	Tree<string, int> bst;
	bst.insert(node1);
	bst.insert(node2);
	bst.insert(node3);
	bst.insert(node4);
	bst.insert(node5);
	bst.displayPostOrder();
}


TEST(TestCaseHeight, T8) {
	Node<string, int> node1("ahmad", 14);
	Node<string, int> node2("nabeel", 11);
	Node<string, int>node3("gohar", 9);
	Node<string, int>node4("Neil", 12);
	Node<string, int>node5("John", 17);
	Node<string, int>node6("Doe", 3);

	Tree<string, int> bst;
	bst.insert(node1);
	bst.insert(node2);
	bst.insert(node3);
	bst.insert(node4);
	bst.insert(node5);
	bst.insert(node6);
	EXPECT_EQ(3, bst.height());
}
TEST(TestCaseHeight, T9) {
	Node<string, int> node1("Ahmad", 14);
	Node<string, int> node2("Nabeel", 11);
	Node<string, int>node3("Gohar", 9);
	Node<string, int>node4("Neil", 12);
	Node<string, int>node5("John", 17);
	Node<string, int>node6("Doe", 18);
	Node<string, int>node7("Zee", 21);
	Node<string, int>node8("Kane", 29);

	Tree<string, int> bst;
	bst.insert(node1);
	bst.insert(node2);
	bst.insert(node3);
	bst.insert(node4);
	bst.insert(node5);
	bst.insert(node6);
	bst.insert(node7);
	bst.insert(node8);

	EXPECT_EQ(4, bst.height());
}
TEST(TestCaseBalanced, T10) {
	Node<string, int> node1("Ahmad", 7);
	Node<string, int> node2("Nabeel", 4);
	Node<string, int>node3("Gohar", 10);
	Node<string, int>node4("Neil", 2);
	Node<string, int>node5("John", 6);
	Node<string, int>node6("Doe", 8);
	Node<string, int>node7("Zee", 13);

	Tree<string, int> bst;
	bst.insert(node1);
	bst.insert(node2);
	bst.insert(node3);
	bst.insert(node4);
	bst.insert(node5);
	bst.insert(node6);
	bst.insert(node7);

	EXPECT_EQ(true, bst.Balance());
}
TEST(TestCaseBalanced, T11) {
	Node<string, int> node1("Ahmad", 7);
	Node<string, int> node2("Nabeel", 4);
	Node<string, int>node3("Gohar", 8);
	Node<string, int>node4("Neil", 2);
	Node<string, int>node5("John", 9);
	Node<string, int>node6("Doe", 1);
	Node<string, int>node7("Zee", 10);


	Tree<string, int> bst;
	bst.insert(node1);
	bst.insert(node2);
	bst.insert(node3);
	bst.insert(node4);
	bst.insert(node5);
	bst.insert(node6);
	bst.insert(node7);

	EXPECT_EQ(false, bst.Balance());
}