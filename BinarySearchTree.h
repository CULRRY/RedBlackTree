#pragma once
#include <vector>

class BinarySearchTree
{
	struct TreeNode
	{
		int32 data;

		TreeNode* leftChild;
		TreeNode* rightChild;
	};

public:
	BinarySearchTree();
	~BinarySearchTree();
	bool Insert(int32 data);
	bool Delete(int32 data);
	bool Search(int32 data);
	void Print(TreeNode* node);
	void Clear();

	void MakeVector(vector<int32>& v)
	{
		MakeVector(v, _root);
	}
	void MakeVector(vector<int32>& v, TreeNode* node)
	{
		if (node == nullptr)
			return;

		MakeVector(v, node->leftChild);

		v.push_back(node->data);

		MakeVector(v, node->rightChild);
	}

	int32 Depth()
	{
		return getDepth(_root);
	}

	int32 SearchDepth() { return _searchDepth; }

private:
	void clearNode(TreeNode* node);
	int32 getDepth(TreeNode* node);

public:
	int32 _size;
	TreeNode* _root;
	int32 _searchDepth = 0;
};

