#include <iostream>
#include "Header.h"

using namespace std;
int main()
{
	string exp = "(a+b)*(c*(d+e))";
	ExpressionTree<char> ET;
	ET.CreateTree(exp);
	ET.displayInOrder();
	return 0;
}