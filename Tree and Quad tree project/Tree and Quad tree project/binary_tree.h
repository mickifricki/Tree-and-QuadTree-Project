#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <iostream>
#include <cstdlib>

using namespace std;

template<class type>
class binary_tree
{
private:
	struct tree_node
	{

		type key;
		tree_node* left;
		tree_node* right;
	};

	tree_node* root;

	tree_node* CreateLeaf(type key)
	{
		tree_node* new_node = new tree_node;
		new_node->key = key;
		new_node->left = NULL;
		new_node->right = NULL;

		return new_node;
	}


	void AddLeafPrivate(type key, tree_node* Ptr)
	{
		if (root == NULL)
		{
			root = CreateLeaf(key);
		}
		else if (key < Ptr->key)
		{
			if (Ptr->left != NULL)
			{
				AddLeafPrivate(key, Ptr->left);
			}
			else
			{
				Ptr->left = CreateLeaf(key);
			}
		}
		else if (key > Ptr->key)
		{
			if (Ptr->right != NULL)
			{
				AddLeafPrivate(key, Ptr->right);
			}
			else
			{
				Ptr->right = CreateLeaf(key);
			}
		}
		else
		{
			printf("The key %d has already been added to the tree", key);
		}

	}


	void PrintInOrderPrivate(tree_node* Ptr)
	{
		if (root != NULL)
		{
			if (Ptr->left != NULL)
			{
				PrintInOrderPrivate(Ptr->left);
			}
			cout << Ptr->key << " ";
			if (Ptr->right != NULL)
			{
				PrintInOrderPrivate(Ptr->right);
			}
		}
		else
		{
			printf("The tree is empty \n");
		}
	}

	tree_node* ReturnNode(type key)
	{
		return ReturnNodePrivate(key, root);
	}

	tree_node* ReturnNodePrivate(type key, tree_node* Ptr)
	{
		if (Ptr != NULL)
		{
			if (Ptr->key == key)
			{
				return Ptr;
			}
			else
			{
				if (key < Ptr->key)
				{
					return ReturnNodePrivate(key, Ptr->left);
				}
				else
				{
					return ReturnNodePrivate(key, Ptr->right);
				}
			}
		}
	}

	type FindSmallestPrivate(tree_node* Ptr)
	{
		if (root == NULL)
		{
			cout << "The tree is empty\n";
			return NULL;
		}
		else
		{
			if (Ptr->left != NULL)
			{
				return FindSmallestPrivate(Ptr->left);
			}
			else
			{
				return Ptr->key;
			}
		}
	}

	void RemoveNodePrivate(type key, tree_node* parent)
	{
		if (root != NULL)
		{
			if(root->key == key)
			{
				RemoveRootMatch();
			}
			else
			{
				if (key < parent->key && parent->left != NULL)
				{
					parent->left->key == key ?
						RemoveMatch(parent, parent->left, true) :
						RemoveNodePrivate(key, parent->left);
				}
				else if (key > parent->key && parent->right != NULL)
				{
					parent->right->key == key ?
						RemoveMatch(parent, parent->right, false) :
						RemoveNodePrivate(key, parent->right);
				}
				else
				{
					cout << "The key " << key << " was not found in the tree.\n";
				}
			}
		}
		else
		{
			cout << "The tree is empty\n";
		}
	}

	void RemoveRootMatch()
	{
		if (root != NULL)
		{
			tree_node* delPtr = root;
			type rootkey = root->key;
			type smallestInRightSubtree;

			//Case 0 - 0 children
			if (root->left == NULL && root->right == NULL)
			{
				root = NULL;
				delete delPtr;
			}

			//Case 1 - 1 child
			else if (root->left == NULL && root->right != NULL)
			{
				root = root->right;
				delPtr->right = NULL;
				delete delPtr;
				cout << "The root node with key " << rootkey << " was deleted.\n" <<
						"The new root contains key " << root->key << endl;

			}
			else if (root->left != NULL && root->right == NULL)
			{
				root = root->left;
				delPtr->left = NULL;
				delete delPtr;
				cout << "The root node with key " << rootkey << " was deleted.\n" <<
					"The new root contains key " << root->key << endl;

			}

			//Case 2 - 2 children
			else
			{
				smallestInRightSubtree = FindSmallestPrivate(root->right);
				RemoveNodePrivate(smallestInRightSubtree, root);
				root->key = smallestInRightSubtree;
				cout << "The root key containing key " << rootkey <<
						" was overwriten with key " << root->key << endl;
			}
				
		}
		else
		{
			cout << "Can not remove root. The tree is empty\n";
		}

	}

	void RemoveMatch(tree_node* parent, tree_node* match, bool left)
	{
		if (root != NULL)
		{
			tree_node* delPtr;
			type matchkey = match->key;
			type smallestInRightSubtree;

			//Case 0 - 0 Children
			if (match->left == NULL && match->right == NULL)
			{
				delPtr = match;
				left == true ? parent->left = NULL : parent->right = NULL;
				delete delPtr;
				cout << "The node containing key " << matchkey << " was removed \n";
			}

			//Case 1 - 1 Children 
			else if (match->left == NULL && match->right != NULL)
			{
				left == true ? parent->left = match->right : parent->right = match->right;
				match->right = NULL;
				delPtr = match;
				delete delPtr;
				cout << "The node containing key " << matchkey << " was removed \n";
			}
			else if (match->left != NULL && match->right == NULL)
			{
				left == true ? parent->left = match->left : parent->right = match->left;
				match->left = NULL;
				delPtr = match;
				delete delPtr;
				cout << "The node containing key " << matchkey << " was removed \n";
			}

			//case 2 - 2 Children
			else
			{
				smallestInRightSubtree = FindSmallestPrivate(match->right);
				RemoveNodePrivate(smallestInRightSubtree, match);
				match->key = smallestInRightSubtree;
			}
		}
		else
		{
			cout << "Can not remove match. The tree is empty\n";
		}
	}

	void RemoveSubtree(tree_node* Ptr)
	{
		if(Ptr != NULL)
		{
			if (Ptr->left != NULL)
			{
				RemoveSubtree(Ptr->left);
			}
			if (Ptr->right != NULL)
			{
				RemoveSubtree(Ptr->right);
			}
			cout << "Deleting the node containing key " << Ptr->key << endl;
			delete Ptr;

		}
	}


public:

	binary_tree()
	{
		root = NULL;
	}

	~binary_tree()
	{
		RemoveSubtree(root);
	}

	void AddLeaf(type key)
	{
		AddLeafPrivate(key, root);
	}

	void PrintInOrder()
	{
		PrintInOrderPrivate(root);
	}
	type ReturnRootKey()
	{
		if (root != NULL)
		{
			return root->key;
		}
		else
		{
			return NULL;
		}
	}
	void PrintChidren(type key)
	{
		tree_node* Ptr = ReturnNode(key);

		if (Ptr != NULL)
		{
			cout << "Parent Node = " << Ptr->key << endl;

				Ptr->left == NULL ?
				cout << "Left Child = NULL\n" :
				cout << "Left Child = " << Ptr->left->key << endl;

				Ptr->right == NULL ?
				cout << "Left Child = NULL\n" :
				cout << "Left Child = " << Ptr->right->key << endl;
		}
		else
		{
			cout << "Key " << key << " is not in the tree\n";
		}

	}

	type FindSmallest()
	{
		return FindSmallestPrivate(root);
	}

	void RemoveNode(type key)
	{
		return RemoveNodePrivate(key, root);
	}





};
































#endif //__BINARY_TREE_H__