#include "stdafx.h"
#include "RedBlackTree.h"
#include "format"
#include <vector>

void SetRed()
{
	::SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 236);
}

void SetBlack()
{
	::SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 224);
}
void SetWhite()
{
	::SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

RedBlackTree::RedBlackTree()
{
	_root = nullptr;
}

RedBlackTree::~RedBlackTree()
{
	Clear();
}

bool RedBlackTree::Insert(int32 data)
{
	Node* newNode = new Node{ nullptr,  &_nil, &_nil, NodeColor::RED, data };

	_size++;
	if (_root == nullptr)
	{
		_root = newNode;
		newNode->parent = _root;
		newNode->color = NodeColor::BLACK;
		//cout << "Insert\n";
		//PrintTree();
		return true;
	}

	Node* parent = _root;
	Node* node = _root;

	while (true)
	{
		if (node->data < data)
		{
			parent = node;
			node = node->rightChild;
			if (node == &_nil)
			{
				parent->rightChild = newNode;
				newNode->parent = parent;
				break;
			}
		}
		else if (node->data > data)
		{
			parent = node;
			node = node->leftChild;
			if (node == &_nil)
			{
				parent->leftChild = newNode;
				newNode->parent = parent;
				break;
			}
		}
		else
		{
			_size--;
			delete newNode;
			return false;
		}
	}
	//cout << "Insert\n";
	//PrintTree();

	if (newNode->parent->color != NodeColor::BLACK)
		BalanceTreeAfterInsert(newNode);


	//cout << "Complete\n";
	//PrintTree();
	return true;
}

bool RedBlackTree::Delete(int32 data)
{


	Node* target = _root;

	while (target != &_nil)
	{
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

	if (target == &_nil)
		return false;

	bool isRoot = false;

	if (target == _root)
	{
		isRoot = true;
	}

	_size--;
	Node* parent = target->parent;
	Node* leftChild = target->leftChild;
	Node* rightChild = target->rightChild;


	Node* balanceNorm = &_nil;

	NodeColor targetColor = NodeColor::BLACK;

	if (leftChild == &_nil && rightChild == &_nil)
	{
		if (parent->data > target->data)
		{
			parent->leftChild = &_nil;
		}
		else if (parent->data < target->data)
		{
			parent->rightChild = &_nil;
		}
		else
		{
			_root = nullptr;
		}

		_nil.parent = parent;

		targetColor = target->color;

		delete target;

		balanceNorm = &_nil;
	}
	else if (leftChild == &_nil)
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
			parent = _root;
		}

		rightChild->parent = parent;
		targetColor = target->color;
		delete target;

		balanceNorm = rightChild;
	}
	else if (rightChild == &_nil)
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
			parent = _root;
		}

		leftChild->parent = parent;
		targetColor = target->color;
		delete target;

		balanceNorm = leftChild;
	}
	else
	{
		Node* minParent = target;
		Node* node = rightChild;

		while (node->leftChild != &_nil)
		{
			minParent = node;
			node = node->leftChild;
		}

		if (node == rightChild)
		{
			minParent->rightChild = node->rightChild;
			balanceNorm = node->rightChild;
			balanceNorm->parent = minParent;
		}
		else if (node->leftChild == &_nil && node->rightChild == &_nil)
		{
			minParent->leftChild = &_nil;
			balanceNorm = &_nil;
			balanceNorm->parent = minParent;
		}
		else if (node->leftChild == &_nil)
		{
			minParent->leftChild = node->rightChild;

			balanceNorm = node->rightChild;
			balanceNorm->parent = minParent;
		}


		node->rightChild = target->rightChild;
		node->leftChild = target->leftChild;
		target->rightChild->parent = node;
		target->leftChild->parent = node;

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
			parent = _root;
		}

		node->parent = parent;
		targetColor = node->color;
		node->color = target->color;
		delete target;
	}

	_root->color = NodeColor::BLACK;
	//cout << "Delete\n";
	//PrintTree();
	if (targetColor == NodeColor::BLACK)
		BalanceTreeAfterDelete(balanceNorm);

	//cout << "Complete\n";
	//PrintTree();

	return true;
}

bool RedBlackTree::Search(int32 data)
{
	int depth = 0;
	Node* target = _root;
	while (target != &_nil)
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

	if (target == &_nil)
		return false;

	return true;
}

bool RedBlackTree::BalanceTreeAfterDelete(Node* node)
{
	/// node�� ������ ����� �ڽ�.	
	Node* now = node;
	Node* sibling;
	while (true)
	{
		if (now == _root)
		{
			return true;
		}

		if (now->parent->leftChild == now)
		{
			sibling = now->parent->rightChild;

			// Case 1 : node�� ���� RED�� ��.
			// node�� ���� BLACK���� ����� ��.
			// BlackNode�� �ϳ� �����Ͽ��� ������ BLACK�� �ϳ� �� �߰����ִ� ����
			if (now->color == NodeColor::RED)
			{
				now->color = NodeColor::BLACK;
				return true;
			}


			// Case 2 : node�� ���� BLACK�ε� ������ ���� RED�� ���.
			// ������ ���� BLACK���� �ٲٰ�, �θ��� ���� RED�� �ٲ������ν�, ������ BLACK�� ���¸� �����
			// �׸��� ���� ��ȸ�� �븰��.
			if (sibling->color == NodeColor::RED)
			{
				Node* parent = now->parent;

				sibling->color = NodeColor::BLACK;
				//cout << "sibling black\n";
				//PrintTree();
				turnLeft(parent);
				//cout << "turn Left\n";
				//PrintTree();
				parent->color = NodeColor::RED;
				//cout << "parent red\n";
				//PrintTree();
			}

			/// Case 3 : ������ ���� BLACK�̰� ������ ���� �ڽĸ�� BLACK�϶�.
			///	������ ���� RED�� ����� ���� BLACK�� -1�� ���°� �ȴ�.
			///	�׸��� �θ� �������� �ٽ� ó���ؾ��Ѵ�.
			else if (sibling->color == NodeColor::BLACK &&
				sibling->rightChild->color == NodeColor::BLACK &&
				sibling->leftChild->color == NodeColor::BLACK)
			{
				sibling->color = NodeColor::RED;
				now = now->parent;
			}

			/// Case 4 : ������ ���� BLACK�̰� ���ڽ��� RED, �����ڽ��� BLACK�ϋ�.
			///	�츮�� �����ڽ��� RED�� ��Ȳ�� ���ϹǷ�, ���ڽ��� BLACK���� �ٲٰ� �θ� RED�� �ٲ۵� ȸ��
			///	�츮�� ���ϴ� ������� �ٲ��.
			else if (sibling->color == NodeColor::BLACK &&
				sibling->rightChild->color == NodeColor::BLACK )
			{
				Node* parent = now->parent;
				sibling->leftChild->color = NodeColor::BLACK;
				sibling->color = NodeColor::RED;
				//cout << "Change Color\n";
				//	PrintTree();
				turnRight(sibling);

				now->parent = parent;
				//cout << "turn Right\n";
				//PrintTree();
			}

			/// Case 5 : ������ ���� BLACK�̰� �����ڽ��� RED�϶�.
			///	������ �θ��� ���� ���󰡰�, �θ�� ������ �����ڽ��� BLACK���� �ٲ۵�, ȸ����Ų��.
			else if (sibling->color == NodeColor::BLACK &&
				sibling->rightChild->color == NodeColor::RED)
			{
				Node* parent = now->parent;
				sibling->color = parent->color;
				parent->color = NodeColor::BLACK;
				sibling->rightChild->color = NodeColor::BLACK;
				turnLeft(parent);
				return true;
			}
		}
		else
		{
			sibling = now->parent->leftChild;
			if (now->color == NodeColor::RED)
			{
				now->color = NodeColor::BLACK;
				return true;
			}

			if (sibling->color == NodeColor::RED)
			{
				Node* parent = now->parent;
				sibling->color = NodeColor::BLACK;
				turnRight(parent);
				parent->color = NodeColor::RED;
			}
			else if (sibling->color == NodeColor::BLACK &&
				sibling->rightChild->color == NodeColor::BLACK &&
				sibling->leftChild->color == NodeColor::BLACK)
			{
				sibling->color = NodeColor::RED;
				now = now->parent;
			}
			else if (sibling->color == NodeColor::BLACK &&
				sibling->leftChild->color == NodeColor::BLACK)
			{
				Node* parent = now->parent;
				sibling->rightChild->color = NodeColor::BLACK;
				sibling->color = NodeColor::RED;
				turnLeft(sibling);
				now->parent = parent;


				//cout << "turn left\n";
				//	PrintTree();
			}
			else if (sibling->color == NodeColor::BLACK &&
				sibling->leftChild->color == NodeColor::RED)
			{
				Node* parent = now->parent;
				sibling->color = parent->color;
				parent->color = NodeColor::BLACK;
				sibling->leftChild->color = NodeColor::BLACK;
				turnRight(parent);
				return true;
			}
		}
	}


	return true;
}

bool RedBlackTree::BalanceTreeAfterInsert(Node* node)
{
	Node* grandParent = node->parent->parent;
	Node* parent = node->parent;

	Node* now = node;

	while (true)
	{
		_root->color = NodeColor::BLACK;
		if (parent->color == NodeColor::BLACK)
			return true;

		if (grandParent->data > parent->data)
		{
			Node* uncle = grandParent->rightChild;

			/// Case 1 : �θ� RED ���̵� RED�� ���
			///	���θ� ����� �ٲٰ�, �θ�� ������ BLACK���� �ٲ۴�.
			///	�̷��ԵǸ� RED, RED������ �� ���� �� �����Ƿ� ���س�带 ���θ�� �ٲٰ� �ٽ� �Ǵ��Ѵ�.
			if (uncle->color == NodeColor::RED)
			{
				grandParent->color = NodeColor::RED;
				parent->color = NodeColor::BLACK;
				uncle->color = NodeColor::BLACK;
				//cout << "ColorChange\n";
				//PrintTree();



				_root->color = NodeColor::BLACK;
				/// �ٲپ��µ� ���θ��� �θ��� ���� �����̸� RED, RED������ �ƴϹǷ� ��.
				if (grandParent->parent->color == NodeColor::BLACK)
				{
					break;
				}

				now = grandParent;
				parent = grandParent->parent;
				grandParent = grandParent->parent->parent;
			}
			/// Case 2 : �θ� RED�̰� ������ BLACK�� ���.
			///	ȸ�� ��, �θ��� ���� BLACK���� ���θ��� ���� RED�� �ٲ۴�.
			else
			{
				if (parent->data < now->data)
				{
					turnLeft(parent);

					//cout << "turnLeft\n";
					//PrintTree();
					parent = now;


				}


				turnRight(grandParent);
				//cout << "turnRight\n";
				//PrintTree();
				parent->color = NodeColor::BLACK;
				grandParent->color = NodeColor::RED;
				//cout << "ColorChange\n";
				//PrintTree();

				break;
			}


		}
		else if (grandParent->data < parent->data)
		{
			Node* uncle = grandParent->leftChild;
			if (uncle->color == NodeColor::RED)
			{


				grandParent->color = NodeColor::RED;
				parent->color = NodeColor::BLACK;
				uncle->color = NodeColor::BLACK;
				//cout << "ColorChange\n";
				//PrintTree();



				_root->color = NodeColor::BLACK;
				if (grandParent->color == NodeColor::BLACK)
				{
					break;
				}

				now = grandParent;
				parent = grandParent->parent;
				grandParent = grandParent->parent->parent;

			}
			else
			{
				if (parent->data > now->data)
				{
					turnRight(parent);
					//cout << "turnRight\n";
					//PrintTree();

					parent = now;
				}


				turnLeft(grandParent);
				//cout << "turnLeft\n";
				//PrintTree();
				parent->color = NodeColor::BLACK;
				grandParent->color = NodeColor::RED;
				//cout << "ColorChange\n";
				//PrintTree();
				break;
			}


		}

	}

	_root->color = NodeColor::BLACK;
}

void RedBlackTree::Print()
{
	print(_root);
	cout << endl;
}

void RedBlackTree::print(Node* node)
{
	if (node == &_nil)
		return;

	print(node->leftChild);

	cout << node->data << " ";

	print(node->rightChild);
}

void RedBlackTree::PrintTree()
{

	int32 depth = getDepth(_root);
	int32 maxWeight = (int32)pow(2, depth) - 1;
	int32 startWidth = 3 * (int32)pow(2, depth - 1);

	vector<Node*> rootText(maxWeight, nullptr);

	rootText[0] = _root;

	makeTreeText(rootText, _root, 0);

	int32 size = startWidth;
	int32 depthCut = 1;

	int cnt = 0;
	for (int i = 0; i < maxWeight; i++)
	{
		if (cnt == depthCut)
		{
			cout << endl;
			size /= 2;
			depthCut *= 2;
			cnt = 1;
		}
		else
		{
			cnt++;
		}

		int mid = size / 2 - 1;
		string str = "   ";
		if (rootText[i] != nullptr)
			str = ::format("{:^3}", rootText[i]->data);

		int j = 0;
		for (; j < mid; j++)
		{
			cout << " ";
		}
		if (rootText[i] != nullptr)
		{
			if (rootText[i]->color == NodeColor::BLACK)
			{
				SetBlack();
				cout << str;
				SetWhite();
			}
			else
			{
				SetRed();
				cout << str;
				SetWhite();
			}
		}
		else
		{
			cout << str;
		}

		j += 3;
		for (; j < size; j++)
		{
			cout << " ";
		}
	}

	cout << endl;
	cout << endl;

}

void RedBlackTree::Clear()
{
	clearNode(_root);
	_root = nullptr;
}

void RedBlackTree::clearNode(Node* node)
{
	if (node == nullptr)
		return;
	if (node == &_nil)
		return;
	clearNode(node->leftChild);
	clearNode(node->rightChild);
	delete node;
}

void RedBlackTree::makeTreeText(vector<Node*>& textArr, Node* node, int32 idx)
{
	if (node == &_nil)
	{
		return;
	}
	int32 left = 2 * idx + 1;
	int32 right = 2 * idx + 2;

	textArr[idx] = node;

	makeTreeText(textArr, node->leftChild, left);
	makeTreeText(textArr, node->rightChild, right);
}

int32 RedBlackTree::getDepth(Node* node)
{
	if (node == &_nil)
	{
		return 0;
	}

	int32 leftDepth = getDepth(node->leftChild) + 1;
	int32 rightDepth = getDepth(node->rightChild) + 1;

	return max(leftDepth, rightDepth);
}

bool RedBlackTree::turnRight(Node* node)
{

	Node* parent = node->parent;
	node->parent = node->leftChild;
	node->leftChild = node->parent->rightChild;
	node->parent->rightChild->parent = node;
	node->parent->rightChild = node;
	if (node == _root)
	{
		_root = _root->parent;
		_root->parent = _root;
		return true;
	}

	node->parent->parent = parent;
	node->leftChild->parent = node;
	if (parent->data > node->parent->data)
	{
		parent->leftChild = node->parent;
	}
	else if (parent->data < node->parent->data)
	{
		parent->rightChild = node->parent;
	}



	return true;
}

bool RedBlackTree::turnLeft(Node* node)
{
	Node* parent = node->parent;
	node->parent = node->rightChild;
	node->rightChild = node->parent->leftChild;
	node->parent->leftChild->parent = node;
	node->parent->leftChild = node;
	if (node == _root)
	{
		_root = _root->parent;
		_root->parent = _root;
		return true;
	}

	node->parent->parent = parent;
	node->rightChild->parent = node;
	if (parent->data > node->parent->data)
	{
		parent->leftChild = node->parent;
	}
	else if (parent->data < node->parent->data)
	{
		parent->rightChild = node->parent;
	}

	return true;
}
