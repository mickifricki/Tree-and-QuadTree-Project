#include "stdafx.h"
#include "CppUnitTest.h"
#include "F:\Uni\Tree-and-QuadTree-Project\Tree and Quad tree project\Tree and Quad tree project\binary_tree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		// p2Tree --------------------------------------------
		TEST_METHOD(TreeAdd)
		{
			Tree<int> tree(0);

			tree.Add(100, 0);
			tree.Add(200, 0);
			tree.Add(300, 0);

			tree.Add(101, 100);
			tree.Add(102, 100);
			tree.Add(103, 100);

			tree.Add(210, 200);
			tree.Add(220, 200);

			tree.Add(221, 220);

			// Just do not test that we run forever because of the recursion
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(TreePreOrderIterative)
		{
			Tree<char> tree('F');

			tree.Add('B', 'F');
			tree.Add('G', 'F');
			tree.Add('A', 'B');
			tree.Add('D', 'B');
			tree.Add('X', 'B');
			tree.Add('C', 'D');
			tree.Add('E', 'D');
			tree.Add('I', 'G');
			tree.Add('H', 'I');

			p2List<TreeNode<char>*> list;
			tree.PreOrderIterative(&list);

			Assert::AreEqual((int)list.count(), 10);

			Assert::AreEqual((char)list[0]->data, 'F');
			Assert::AreEqual((char)list[1]->data, 'B');
			Assert::AreEqual((char)list[2]->data, 'A');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'C');
			Assert::AreEqual((char)list[5]->data, 'E');
			Assert::AreEqual((char)list[6]->data, 'X');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'I');
			Assert::AreEqual((char)list[9]->data, 'H');
		}

		TEST_METHOD(TreePostOrderIterative)
		{
			Tree<char> tree('F');

			tree.Add('B', 'F');
			tree.Add('G', 'F');
			tree.Add('A', 'B');
			tree.Add('D', 'B');
			tree.Add('C', 'D');
			tree.Add('E', 'D');
			tree.Add('I', 'G');
			tree.Add('H', 'I');

			p2List<TreeNode<char>*> list;
			tree.PostOrderIterative(&list);

			Assert::AreEqual((int)list.count(), 9);

			Assert::AreEqual((char)list[0]->data, 'A');
			Assert::AreEqual((char)list[1]->data, 'C');
			Assert::AreEqual((char)list[2]->data, 'E');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'B');
			Assert::AreEqual((char)list[5]->data, 'H');
			Assert::AreEqual((char)list[6]->data, 'I');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'F');
		}

		TEST_METHOD(TreeInOrderIterative)
		{
			Tree<char> tree('F');

			tree.Add('B', 'F');
			tree.Add('G', 'F');
			tree.Add('A', 'B');
			tree.Add('D', 'B');
			tree.Add('C', 'D');
			tree.Add('E', 'D');
			tree.Add('I', 'G');
			tree.Add('H', 'I');

			p2List<TreeNode<char>*> list;
			tree.InOrderIterative(&list);

			Assert::AreEqual((int)list.count(), 9);

			Assert::AreEqual((char)list[0]->data, 'A');
			Assert::AreEqual((char)list[1]->data, 'B');
			Assert::AreEqual((char)list[2]->data, 'C');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'E');
			Assert::AreEqual((char)list[5]->data, 'F');
			Assert::AreEqual((char)list[6]->data, 'G');
			Assert::AreEqual((char)list[7]->data, 'I');
			Assert::AreEqual((char)list[8]->data, 'H');
		}

		TEST_METHOD(TreePreOrder)
		{
			Tree<char> tree('F');

			tree.Add('B', 'F');
			tree.Add('G', 'F');
			tree.Add('A', 'B');
			tree.Add('D', 'B');
			tree.Add('X', 'B');
			tree.Add('C', 'D');
			tree.Add('E', 'D');
			tree.Add('I', 'G');
			tree.Add('H', 'I');

			p2List<TreeNode<char>*> list;
			tree.PreOrderRecursive(&list);

			Assert::AreEqual((int)list.count(), 10);

			Assert::AreEqual((char)list[0]->data, 'F');
			Assert::AreEqual((char)list[1]->data, 'B');
			Assert::AreEqual((char)list[2]->data, 'A');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'C');
			Assert::AreEqual((char)list[5]->data, 'E');
			Assert::AreEqual((char)list[6]->data, 'X');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'I');
			Assert::AreEqual((char)list[9]->data, 'H');
		}

		TEST_METHOD(TreePostOrder)
		{
			Tree<char> tree('F');

			tree.Add('B', 'F');
			tree.Add('G', 'F');
			tree.Add('A', 'B');
			tree.Add('D', 'B');
			tree.Add('C', 'D');
			tree.Add('E', 'D');
			tree.Add('I', 'G');
			tree.Add('H', 'I');

			p2List<TreeNode<char>*> list;
			tree.PostOrderRecursive(&list);

			Assert::AreEqual((int)list.count(), 9);

			Assert::AreEqual((char)list[0]->data, 'A');
			Assert::AreEqual((char)list[1]->data, 'C');
			Assert::AreEqual((char)list[2]->data, 'E');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'B');
			Assert::AreEqual((char)list[5]->data, 'H');
			Assert::AreEqual((char)list[6]->data, 'I');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'F');
		}

		TEST_METHOD(TreeInOrder)
		{
			Tree<char> tree('F');

			tree.Add('B', 'F');
			tree.Add('G', 'F');
			tree.Add('A', 'B');
			tree.Add('D', 'B');
			tree.Add('C', 'D');
			tree.Add('E', 'D');
			tree.Add('I', 'G');
			tree.Add('H', 'I');

			p2List<TreeNode<char>*> list;
			tree.InOrderRecursive(&list);

			Assert::AreEqual((int)list.count(), 9);

			Assert::AreEqual((char)list[0]->data, 'A');
			Assert::AreEqual((char)list[1]->data, 'B');
			Assert::AreEqual((char)list[2]->data, 'C');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'E');
			Assert::AreEqual((char)list[5]->data, 'F');
			Assert::AreEqual((char)list[6]->data, 'G');
			Assert::AreEqual((char)list[7]->data, 'I');
			Assert::AreEqual((char)list[8]->data, 'H');
		}

		TEST_METHOD(TreeGather)
		{
			Tree<int> tree(0);

			tree.Add(100, 0);
			tree.Add(200, 0);
			tree.Add(300, 0);
			tree.Add(101, 100);
			tree.Add(102, 100);
			tree.Add(103, 100);
			tree.Add(210, 200);
			tree.Add(220, 200);
			tree.Add(221, 220);

			p2List<TreeNode<int>*> list;
			tree.root.GatherAll(&list);

			Assert::AreEqual((int)list.count(), 10);

			Assert::AreEqual((int)list[0]->data, 0);
			Assert::AreEqual((int)list[1]->data, 100);
			Assert::AreEqual((int)list[2]->data, 101);
			Assert::AreEqual((int)list[3]->data, 102);
			Assert::AreEqual((int)list[4]->data, 103);
			Assert::AreEqual((int)list[5]->data, 200);
			Assert::AreEqual((int)list[6]->data, 210);
			Assert::AreEqual((int)list[7]->data, 220);
			Assert::AreEqual((int)list[8]->data, 221);
			Assert::AreEqual((int)list[9]->data, 300);

		}

		TEST_METHOD(TreeGatherData)
		{
			Tree<int> tree(0);

			tree.Add(100, 0);
			tree.Add(200, 0);
			tree.Add(300, 0);
			tree.Add(101, 100);
			tree.Add(102, 100);
			tree.Add(103, 100);
			tree.Add(210, 200);
			tree.Add(220, 200);
			tree.Add(221, 220);

			p2List<int> list;
			tree.root.GatherAllData(&list);

			Assert::AreEqual((int)list.count(), 10);

			Assert::AreEqual((int)list[0], 0);
			Assert::AreEqual((int)list[1], 100);
			Assert::AreEqual((int)list[2], 101);
			Assert::AreEqual((int)list[3], 102);
			Assert::AreEqual((int)list[4], 103);
			Assert::AreEqual((int)list[5], 200);
			Assert::AreEqual((int)list[6], 210);
			Assert::AreEqual((int)list[7], 220);
			Assert::AreEqual((int)list[8], 221);
			Assert::AreEqual((int)list[9], 300);

		}

		TEST_METHOD(TreeDelRecursive)
		{
			Tree<int> tree(0);

			tree.Add(100, 0);
			tree.Add(200, 0);
			tree.Add(300, 0);
			tree.Add(101, 100);
			tree.Add(102, 100);
			tree.Add(103, 100);
			tree.Add(210, 200);
			tree.Add(220, 200);
			tree.Add(221, 220);

			tree.DelRecursive(200);

			p2List<TreeNode<int>*> list;
			tree.root.GatherAll(&list);

			Assert::AreEqual((int)list.count(), 6);

			Assert::AreEqual((int)list[0]->data, 0);
			Assert::AreEqual((int)list[1]->data, 100);
			Assert::AreEqual((int)list[2]->data, 101);
			Assert::AreEqual((int)list[3]->data, 102);
			Assert::AreEqual((int)list[4]->data, 103);
			Assert::AreEqual((int)list[5]->data, 300);

			for (p2List_item<TreeNode<int>*>* item = list.start; item != NULL; item = item->next)
			{
				TreeNode<int>* child = item->data;
				//TLOG("node: %d parent: %d", child->data, (child->parent) ? child->parent->data : -1);
			}

		}

		TEST_METHOD(TreeClear)
		{
			Tree<int> tree(0);

			tree.Add(100, 0);
			tree.Add(200, 0);
			tree.Add(300, 0);
			tree.Add(101, 100);
			tree.Add(102, 100);
			tree.Add(103, 100);
			tree.Add(210, 200);
			tree.Add(220, 200);
			tree.Add(221, 220);

			tree.Clear();

			p2List<TreeNode<int>*> list;
			tree.root.GatherAll(&list);

			Assert::AreEqual((int)list.count(), 1);
		}


		TEST_METHOD(TreeFind)
		{
			Tree<int> tree(0);

			tree.Add(100, 0);
			tree.Add(200, 0);
			tree.Add(300, 0);
			tree.Add(101, 100);
			tree.Add(102, 100);
			tree.Add(103, 100);
			tree.Add(210, 200);
			tree.Add(220, 200);
			tree.Add(221, 220);

			TreeNode<int>* p = tree.root.FindRecursive(210);
			TreeNode<int>* p2 = tree.root.FindRecursive(999);

			Assert::AreEqual((int)p->data, 210);
			Assert::IsNull(p2);
		}

		TEST_METHOD(TreeRelocate)
		{
			Tree<int> tree(0);

			tree.Add(100, 0);
			tree.Add(200, 0);
			tree.Add(300, 0);
			tree.Add(101, 100);
			tree.Add(102, 100);
			tree.Add(103, 100);
			tree.Add(210, 200);
			tree.Add(220, 200);
			tree.Add(221, 220);

			TreeNode<int>* p = tree.root.FindRecursive(200);
			Assert::AreEqual((int)p->parent->data, 0);

			Assert::IsTrue(tree.Relocate(200, 103));

			p = tree.root.FindRecursive(200);
			Assert::AreEqual((int)p->parent->data, 103);

			p2List<TreeNode<int>*> list;
			tree.root.GatherAll(&list);
			for (p2List_item<TreeNode<int>*>* item = list.start; item != NULL; item = item->next)
			{
				TreeNode<int>* child = item->data;
				//TLOG("node: %d parent: %d", child->data, (child->parent) ? child->parent->data : -1);
			}

		}

	};
}