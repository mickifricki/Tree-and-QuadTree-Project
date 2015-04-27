#include <iostream>
#include <cstdlib>
#include "binary_tree.h"

using namespace std;

int main(int argc, char argv)
{
	//int TreeKeys[16] = { 50, 76, 21, 4, 32, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80 };
	binary_tree<char> myTree;
	myTree.AddLeaf('B');
	int input = 0;

	cout << "Printing the tree in order\nBefore adding numbers\n";

	myTree.PrintInOrder();
	/*for (int i = 0; i < 16; i++)
	{
		myTree.AddLeaf(TreeKeys[i]);
	}*/

	cout << "Printing ther tree in order\nAfter adding numbers\n";

	myTree.PrintInOrder();

	cout << endl;

	/*for (int i = 0; i < 16; i++)
	{
		myTree.PrintChidren(TreeKeys[i]);
		cout << endl;
	}*/

	cout << "The smallest value is " << myTree.FindSmallest() << endl;

	cout << "Enter a key value to delete. Enter -1 to stop the process\n";
	while (input != -1)
	{
		cout << "Delete Node: ";
		cin >> input;
		{
			if (input != -1)
			{
				cout << endl;
				myTree.RemoveNode(input);
				myTree.PrintInOrder();
				cout << endl;
			}
		}
	}

	getchar();

	return 0;
}
