#pragma once
#include <vector>

enum class NodeColor
{
	BLACK = 0,
	RED,
};


class RedBlackTree
{
	struct Node
	{
		Node* parent;
		Node* leftChild;
		Node* rightChild;

		NodeColor color;
		int32 data;
	};


public:
	RedBlackTree();
	~RedBlackTree();

	bool Insert(int32 data);
	bool Delete(int32 data);

	bool Search(int32 data);
	bool BalanceTreeAfterInsert(Node* node);
	bool BalanceTreeAfterDelete(Node* node);
	void Print();

	void MakeVector(vector<int32>& v)
	{
		MakeVector(v, _root);
	}
	void MakeVector(vector<int32>& v, Node* node)
	{
		if (node == &_nil)
			return;

		MakeVector(v, node->leftChild);

		v.push_back(node->data);

		MakeVector(v, node->rightChild);
	}

	int32 Size()
	{
		return _size;
	}

	int32 Depth()
	{
		return getDepth(_root);
	}

	void PrintTree();

	void Clear();
	int32 SearchDepth() { return _searchDepth; }

private:
	void makeTreeText(vector<Node*>& textArr, Node* node, int32 idx);
	int32 getDepth(Node* node);
	bool turnRight(Node* node);
	bool turnLeft(Node* node);
	void print(Node* node);
	void clearNode(Node* node);

private:
	Node _nil;
	Node* _root;
	int32 _size;
	int32 _searchDepth = 0;

};

