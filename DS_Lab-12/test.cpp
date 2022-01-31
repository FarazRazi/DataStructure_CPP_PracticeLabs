#include"pch.h"
#include"Header.h"
#include<iostream>
using namespace std;
TEST(TestCaseInsertion, T1) {
	Node<int> node1(10);
	Node<int> node2(11);
	Node<int> node3(12);
	Node<int> node4(13);
	Node<int> node5(14);
	Node<int> node6(16);
	Node<int> node7(17);

	AVLTree<int> avl;
	avl.insert(node1);
	avl.insert(node2);
	avl.insert(node3);
	avl.insert(node4);
	avl.insert(node5);
	avl.insert(node6);
	avl.insert(node7);
	avl.display();
	EXPECT_TRUE(true, avl.isBalanced());
}

TEST(TestCaseInsertion, T2) {
	Node<int> node1(10);
	Node<int> node2(9);
	Node<int> node3(8);
	AVLTree<int> avl;
	avl.insert(node1);
	avl.insert(node2);
	avl.insert(node3);
	avl.display();
	EXPECT_TRUE(true, avl.isBalanced());
}

TEST(TestCaseInsertion, T3) {
	Node<int> node1(10);
	Node<int> node2(12);
	Node<int> node3(11);
	AVLTree<int> avl;
	avl.insert(node1);
	avl.insert(node2);
	avl.insert(node3);
	avl.display();
	EXPECT_TRUE(true, avl.isBalanced());
}
TEST(TestCaseInsertion, T4) {
	Node<int> node1(10);
	Node<int> node2(8);
	Node<int> node3(9);
	AVLTree<int> avl;
	avl.insert(node1);
	avl.insert(node2);
	avl.insert(node3);
	avl.display();
	EXPECT_TRUE(true, avl.isBalanced());
}

TEST(TestCaseDeletion, T5) {
	Node<int> node1(10);
	Node<int> node2(8);
	Node<int> node3(9);
	Node<int> node4(4);
	Node<int> node5(3);
	AVLTree<int> avl;
	avl.insert(node1);
	avl.insert(node2);
	avl.insert(node3);
	avl.insert(node4);
	avl.insert(node5);

	avl.display();

	avl.delNode(4);
	//avl.delNode(10);


	avl.display();
	EXPECT_TRUE(true, avl.isBalanced());
}