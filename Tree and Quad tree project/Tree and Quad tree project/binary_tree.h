
#ifndef __binary_tree_H__
#define __binary_tree_H__

#include "p2List.h"
#include "p2Stack.h"

// Tree node -------------------------------------------------------
template<class type>
class TreeNode
{

public:

	type data;
	TreeNode* parent;
	p2List<TreeNode*> childs;

public:

	TreeNode(const type& _data)
	{
		data = _data;
		parent = NULL;
	}

	void AddLeaf(TreeNode* node)
	{
		if (node != NULL)
		{
			childs.add(node);
			node->parent = this;
		}
	}

	bool RemoveLeaf(TreeNode* node)
	{
		bool ret = false;
		if (node != NULL){
			
			p2List_item<TreeNode*>* item = childs.start;
			for (; item != NULL; item = item->next)
			{
				TreeNode* child = item->data;

				if (node == child)
				{
					childs.del(item);
					node->parent = NULL;
					ret = true;
					break;
				}
			}
		}
		return ret;
	}

	void PreOrderRecursive(p2List<TreeNode<type>*>* list)
	{
		list->add(this);

		p2List_item<TreeNode*>* item = childs.start;

		for (; item != NULL; item = item->next)
			item->data->PreOrderRecursive(list);
	}

	void InOrderRecursive(p2List<TreeNode<type>*>* list)
	{
		p2List_item<TreeNode*>* item = childs.start;
		unsigned int mid = childs.count() / 2;

		for (unsigned int i = 0; i < mid; ++i, item = item->next)
			item->data->InOrderRecursive(list);

		list->add(this);

		for (; item != NULL; item = item->next)
			item->data->InOrderRecursive(list);
	}

	void PostOrderRecursive(p2List<TreeNode<type>*>* list)
	{
		p2List_item<TreeNode*>* item = childs.start;

		for (; item != NULL; item = item->next)
			item->data->PostOrderRecursive(list);

		list->add(this);
	}

	TreeNode<type>* FindRecursive(const type& node)
	{
		if (node == data)
			return this;

		TreeNode<type>* result = NULL;
		p2List_item<TreeNode*>* item = childs.start;
		for (; item != NULL; item = item->next)
		{
			TreeNode* child = item->data;
			result = child->FindRecursive(node);

			if (result != NULL)
				break;
		}

		return result;
	}

	void GatherAll(p2List<TreeNode*>* list)
	{
		if (list != NULL){
			list->add(this);

			p2List_item<TreeNode*>* item = childs.start;

			for (; item != NULL; item = item->next)
			{
				TreeNode* child = item->data;
				child->GatherAll(list);
			}
		}
	}

	void GatherAllData(p2List<type>* list)
	{
		if (list != NULL){
			list->add(data);

			p2List_item<TreeNode*>* item = childs.start;

			for (; item != NULL; item = item->next)
			{
				TreeNode* child = item->data;
				child->GatherAllData(list);
			}
		}
	}

};

// Tree class -------------------------------------------------------
template<class type>
class Tree
{
public:

	// Constructor
	Tree(const type& _data) : root(_data)
	{}

	// Destructor
	virtual ~Tree()
	{}

	void PreOrderRecursive(p2List<TreeNode<type>*>* list)
	{
		root.PreOrderRecursive(list);
	}

	void PostOrderRecursive(p2List<TreeNode<type>*>* list)
	{
		root.PostOrderRecursive(list);
	}

	void InOrderRecursive(p2List<TreeNode<type>*>* list)
	{
		root.InOrderRecursive(list);
	}

	void PreOrderIterative(p2List<TreeNode<type>*>* list)
	{
		p2Stack<TreeNode<type>*> stack;
		TreeNode<type>* node = &root;

		while (node != NULL || stack.Pop(node))
		{
			list->add(node);

			p2List_item<TreeNode<type>*>* item = node->childs.end;
			for (; item != node->childs.start; item = item->prev)
				stack.Push(item->data);

			node = (item != NULL) ? item->data : NULL;
		}
	}

	void PostOrderIterative(p2List<TreeNode<type>*>* list)
	{
		p2Stack<TreeNode<type>*> stack;
		TreeNode<type>* node = &root;

		while (node != NULL || stack.Pop(node))
		{
			p2List_item<TreeNode<type>*>* item = node->childs.end;

			if (item != NULL && list->find(item->data) == -1)
			{
				stack.Push(node);
				for (; item != node->childs.start; item = item->prev)
					stack.Push(item->data);

				node = item->data;
			}
			else
			{
				list->add(node);
				node = NULL;
			}
		}
	}

	void InOrderIterative(p2List<TreeNode<type>*>* list)
	{
		p2Stack<TreeNode<type>*> stack;
		TreeNode<type>* node = &root;

		while (node != NULL || stack.Pop(node))
		{
			list->add(node);

			p2List_item<TreeNode<type>*>* item = node->childs.end;
			for (; item != node->childs.start; item = item->prev)
				stack.Push(item->data);

			node = (item != NULL) ? item->data : NULL;
		}
	}

	void Add(const type& data, const type& parent)
	{
		TreeNode<type>* p = root.FindRecursive(parent);
		TreeNode<type>* node = new TreeNode<type>(data);
		p->AddLeaf(node);
	}

	void Add(const type& data)
	{
		TreeNode<type>* node = new TreeNode<type>(data);
		trunk.AddLeaf(node);
	}

	bool Relocate(const type& data, const type& parent)
	{
		bool ret = false;

		TreeNode<type>* dad = root.FindRecursive(parent);
		TreeNode<type>* child = root.FindRecursive(data);

		if (dad && child && child->parent != dad)
		{
			child->parent->RemoveLeaf(child);
			dad->AddLeaf(child);
			ret = true;
		}

		return ret;
	}

	bool DelRecursive(const type& data)
	{
		bool ret = false;

		TreeNode<type>* node = root.FindRecursive(data);

		if (node != NULL)
		{
			p2List<TreeNode<type>*> results;
			node->GatherAll(&results);

			p2List_item<TreeNode<type>*>* item = results.start;

			for (; item != NULL; item = item->next)
			{
				TreeNode<type>* child = item->data;

				if (child->parent)
					child->parent->RemoveLeaf(child);
			}

			ret = true;
		}

		return ret;
	}

	void Clear()
	{
		p2List<TreeNode<type>*> results;
		root.GatherAll(&results);

		p2List_item<TreeNode<type>*>* item = results.start;
		for (; item != NULL; item = item->next)
		{
			TreeNode<type>* child = item->data;
			if (child->parent)
				child->parent->RemoveChild(child);
		}
	}

public:

	TreeNode<type>	root;

};



#endif // __binary_tree_H__