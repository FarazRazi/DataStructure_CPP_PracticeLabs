#include "pch.h"
#include "Header.h"

using namespace std;
TEST(TestCaseName, TestName) {

	string exp = "ab+cde+**";
	ExpressionTree<char> ET;
	ET.CreateTree(exp);
	ET.displayInOrder();
	cout << endl;


  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}