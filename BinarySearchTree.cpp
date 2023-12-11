#include "stdafx.h"
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
	_root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
	Clear();
}

bool BinarySearchTree::Insert(int32 data)
{
	TreeNode* newNode = new TreeNode{ data, nullptr, nullptr };

	_size++;
	if (_root == nullptr)
	{
		_root = newNode;
		return true;
	}

	TreeNode* parent = _root;
	TreeNode* node = _root;

	while (true)
	{
		if (node->data < data)
		{
			parent = node;
			node = node->rightChild;
			if (node == nullptr)
			{
				parent->rightChild = newNode;
				return true;
			}
		}
		else if (node->data > data)
		{
			parent = node;
			node = node->leftChild;
			if (node == nullptr)
			{
				parent->leftChild = newNode;
				return true;
			}
		}
		else
		{
			_size--;
			delete newNode;
			return false;
		}
	}

}

bool BinarySearchTree::Delete(int32 data)
{
	TreeNode* parent = _root;
	TreeNode* target = _root;

	while (target != nullptr)
	{
		if (data < target->data)
		{
			parent = target;
			target = target->leftChild;
		}
		else if (data > target->data)
		{
			parent = target;
			target = target->rightChild;
		}
		else
		{
			break;
		}
	}

	if (target == nullptr)
		return false;


	_size--;
	TreeNode* leftChild = target->leftChild;
	TreeNode* rightChild = target->rightChild;


	if (leftChild == nullptr && rightChild == nullptr)
	{
		if (parent->data > target->data)
		{
			parent->leftChild = nullptr;
		}
		else if (parent->data < target->data)
		{
			parent->rightChild = nullptr;
		}
		else
		{
			_root = nullptr;
		}

		delete target;
		return true;
	}


	if (leftChild == nullptr)
	{
		if (parent->data > target->data)
		{
			parent->leftChild = rightChild;
		}
		else if (parent->data < target->data)
		{
			parent->rightChild = rightChild;
		}
		else
		{
			_root = rightChild;
		}
		delete target;
		return true;
	}

	if (rightChild == nullptr)
	{
		if (parent->data > target->data)
		{
			parent->leftChild = leftChild;
		}
		else if (parent->data < target->data)
		{
			parent->rightChild = leftChild;
		}
		else
		{
			_root = leftChild;
		}
		delete target;
		return true;
	}

	TreeNode* minParent = target;
	TreeNode* node = rightChild;

	while (node->leftChild != nullptr)
	{
		minParent = node;
		node = node->leftChild;
	}

	if (node == rightChild)
	{
		minParent->rightChild = node->rightChild;
	}
	else if (node->leftChild == nullptr && node->rightChild == nullptr)
	{
		minParent->leftChild = nullptr;
	}
	else if (node->leftChild == nullptr)
	{
		minParent->leftChild = node->rightChild;
	}


	node->rightChild = target->rightChild;
	node->leftChild = target->leftChild;

	if (parent->data > target->data)
	{
		parent->leftChild = node;
	}
	else if (parent->data < target->data)
	{
		parent->rightChild = node;
	}
	else
	{
		_root = node;
	}

	delete target;

	return true;
}

bool BinarySearchTree::Search(int32 data)
{
	int depth = 0;
	TreeNode* target = _root;
	while (target != nullptr)
	{
		depth++;
		if (data < target->data)
		{
			target = target->leftChild;
		}
		else if (data > target->data)
		{
			target = target->rightChild;
		}
		else
		{
			break;
		}
	}

	_searchDepth += depth;

	if (target == nullptr)
		return false;

	return true;
}

void BinarySearchTree::Print(TreeNode* node)
{
	if (node == nullptr)
		return;
	Print(node->leftChild);

	cout << node->data << " ";

	Print(node->rightChild);
}

void BinarySearchTree::Clear()
{
	clearNode(_root);
	_root = nullptr;
}

void BinarySearchTree::clearNode(TreeNode* node)
{
	if (node == nullptr)
		return;

	clearNode(node->leftChild);
	clearNode(node->rightChild);
	delete node;
}

int32 BinarySearchTree::getDepth(TreeNode* node)
{
	if (node == nullptr)
	{
		return 0;
	}

	int32 leftDepth = getDepth(node->leftChild) + 1;
	int32 rightDepth = getDepth(node->rightChild) + 1;

	return max(leftDepth, rightDepth);
}
