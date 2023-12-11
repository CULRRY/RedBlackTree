#include "stdafx.h"
#include "BinarySearchTree.h"
#include <conio.h>
#include <vector>
#include <set>
#include <vector>
#define PROFILE
#include "Profiler.h"
#include "RedBlackTree.h"
#define MAX_VALUE 1000;

#include <random>

// ������ ����
// 1. 1���� �����ؼ� ���������� ������ �ϴ� ����
// 2. ������ ������ ������� �����Ͽ�, �¿찡 �յ��ϰ� ���� ����
// 3. ������ ���� ����.


void CollapseCache()
{
	for (int k = 0; k < 100; k++)
	{
		int32* arr = (int32*)malloc(sizeof(int32) * 10000);

		for (int i = 0; i < 10000; i++)
		{
			arr[i] = i;
		}

		free(arr);

		for (int i = 0; i < 100; i++)
		{
			int64* a = new int64;
			delete a;
		}
	}
	
}

int main()
{
	srand(10);

	BinarySearchTree	bsTree;
	RedBlackTree		rbTree;

	///// Data Pattern 1
	/////	1. 1���� 1�� �����ϴ� ���� {0, 1, 2, ..., 100000}�� Insert�� Search ����
	/////	10000ȸ�� 4ȸ ����


	//for (int i = 0; i < 100; i++)
	//{
	//	rbTree.Clear();
	//	bsTree.Clear();

	//	PROFILE_BEGIN(L"RBTREE - Linear");
	//	for (int i = 0; i < 10000; i++)
	//	{
	//		rbTree.Insert(i);
	//	}
	//	PROFILE_END(L"RBTREE - Linear");

	//	PROFILE_BEGIN(L"BSTREE - Linear");
	//	for (int i = 0; i < 10000; i++)
	//	{
	//		bsTree.Insert(i);
	//	}
	//	PROFILE_END(L"BSTREE - Linear");


	//}
	//
	//for (int i = 0; i < 100; i++)
	//{
	//	rbTree.Clear();
	//	bsTree.Clear();

	//	PROFILE_BEGIN(L"BSTREE - Linear");
	//	for (int i = 0; i < 10000; i++)
	//	{
	//		bsTree.Insert(i);
	//	}
	//	PROFILE_END(L"BSTREE - Linear");

	//	PROFILE_BEGIN(L"RBTREE - Linear");
	//	for (int i = 0; i < 10000; i++)
	//	{
	//		rbTree.Insert(i);
	//	}
	//	PROFILE_END(L"RBTREE - Linear");


	//}

	//for (int i = 0; i < 100; i++)
	//{
	//	PROFILE_BEGIN(L"RBTREE Search - Linear");
	//	for (int i = 0; i < 10000; i++)
	//	{
	//		rbTree.Search(i);
	//	}
	//	PROFILE_END(L"RBTREE Search - Linear");

	//	PROFILE_BEGIN(L"BSTREE Search - Linear");
	//	for (int i = 0; i < 10000; i++)
	//	{
	//		bsTree.Search(i);
	//	}
	//	PROFILE_END(L"BSTREE Search - Linear");
	//}
	//
	//for (int i = 0; i < 100; i++)
	//{
	//	PROFILE_BEGIN(L"BSTREE Search - Linear");
	//	for (int i = 0; i < 10000; i++)
	//	{
	//		bsTree.Search(i);
	//	}
	//	PROFILE_END(L"BSTREE Search - Linear");

	//	PROFILE_BEGIN(L"RBTREE Search - Linear");
	//	for (int i = 0; i < 10000; i++)
	//	{
	//		rbTree.Search(i);
	//	}
	//	PROFILE_END(L"RBTREE Search - Linear");
	//}


	//rbTree.Clear();
	//bsTree.Clear();

	//// Date Pattern 2 - �����Ͱ� �¿�� �����ְ� ������ ���.
	//// 5000���� �����Ͽ�, {5000, 7500, 2500, .... } �̷������� ���ݾ� ���� �����ϸ�
	//// ���Ե� ������ ������� ������ �µ��� ���� �� �� �ִ�.

	//vector<int32> balancedArr;

	//balancedArr.push_back(5000);
	//int size = 5000;
	//while (size > 0)
	//{
	//	for (int i = 5000; i <= 10000; i += size)
	//	{
	//		balancedArr.push_back(i);
	//	}

	//	for (int i = 5000; i >= 0; i -= size)
	//	{
	//		balancedArr.push_back(i);
	//	}

	//	size /= 2;
	//}


	//for (int i = 0; i < 100; i++)
	//{
	//	rbTree.Clear();
	//	bsTree.Clear();

	//	PROFILE_BEGIN(L"RBTREE - Balanced");
	//	for (int i = 0; i < 10000; i++)
	//	{
	//		rbTree.Insert(balancedArr[i]);
	//	}
	//	PROFILE_END(L"RBTREE - Balanced");

	//	PROFILE_BEGIN(L"BSTREE - Balanced");
	//	for (int i = 0; i < 10000; i++)
	//	{
	//		bsTree.Insert(balancedArr[i]);
	//	}
	//	PROFILE_END(L"BSTREE - Balanced");
	//}

	//for (int i = 0; i < 100; i++)
	//{
	//	rbTree.Clear();
	//	bsTree.Clear();

	//	PROFILE_BEGIN(L"BSTREE - Balanced");
	//	for (int i = 0; i < 10000; i++)
	//	{
	//		bsTree.Insert(balancedArr[i]);
	//	}
	//	PROFILE_END(L"BSTREE - Balanced");

	//	PROFILE_BEGIN(L"RBTREE - Balanced");
	//	for (int i = 0; i < 10000; i++)
	//	{
	//		rbTree.Insert(balancedArr[i]);
	//	}
	//	PROFILE_END(L"RBTREE - Balanced");
	//}

	//for (int i = 0; i < 100; i++)
	//{
	//	PROFILE_BEGIN(L"RBTREE Search - Balanced");
	//	for (int i = 0; i < 10000; i++)
	//	{
	//		rbTree.Search(i);
	//	}
	//	PROFILE_END(L"RBTREE Search - Balanced");

	//	PROFILE_BEGIN(L"BSTREE Search - Balanced");
	//	for (int i = 0; i < 10000; i++)
	//	{
	//		bsTree.Search(i);
	//	}
	//	PROFILE_END(L"BSTREE Search - Balanced");
	//}

	//for (int i = 0; i < 100; i++)
	//{
	//	PROFILE_BEGIN(L"BSTREE Search - Balanced");
	//	for (int i = 0; i < 10000; i++)
	//	{
	//		bsTree.Search(i);
	//	}
	//	PROFILE_END(L"BSTREE Search - Balanced");

	//	PROFILE_BEGIN(L"RBTREE Search - Balanced");
	//	for (int i = 0; i < 10000; i++)
	//	{
	//		rbTree.Search(i);
	//	}
	//	PROFILE_END(L"RBTREE Search - Balanced");
	//}

	//rbTree.Clear();
	//bsTree.Clear();

	/// Data Pattern 3 - ������ ���� ����
	///	0 ~ 10000������ �������� ������ ����. ������� ������ ����

	vector<int32> insertArr;
	vector<int32> deleteArr;
	vector<int32> findArr;

	int32 averageDepthBST = 0;
	int32 averageDepthRBT = 0;

	for (int i = 0; i < 10000; i ++)
	{
		insertArr.push_back(i);
	}
	set<int32> s;
	for (int i = 0; i < 1000; i++)
	{
		rbTree.Clear();
		bsTree.Clear();
		s.clear();

		shuffle(insertArr.begin(), insertArr.end(), std::default_random_engine(10));

		PROFILE_BEGIN(L"RBTREE - Random");
		for (int i = 0; i < 10000; i++)
		{
			rbTree.Insert(insertArr[i]);
		}
		PROFILE_END(L"RBTREE - Random");

		//cout << rbTree.Depth() << endl;
		CollapseCache();

		PROFILE_BEGIN(L"BSTREE - Random");
		for (int i = 0; i < 10000; i++)
		{
			bsTree.Insert(insertArr[i]);
		}
		PROFILE_END(L"BSTREE - Random");


		CollapseCache();

		PROFILE_BEGIN(L"SET - Random");
		for (int i = 0; i < 10000; i++)
		{
			s.insert(insertArr[i]);
		}
		PROFILE_END(L"SET - Random");

		//cout << rbTree.Depth() << endl;
		CollapseCache();


		PROFILE_BEGIN(L"RBTREE Search - Random");
		for (int i = 0; i < 10000; i++)
		{
			rbTree.Search(i);
		}
		PROFILE_END(L"RBTREE Search - Random");

		CollapseCache();

		PROFILE_BEGIN(L"BSTREE Search - Random");
		for (int i = 0; i < 10000; i++)
		{
			bsTree.Search(i);
		}
		PROFILE_END(L"BSTREE Search - Random");



		CollapseCache();


		PROFILE_BEGIN(L"SET Search - Random");
		for (int i = 0; i < 10000; i++)
		{
			s.contains(i);
		}
		PROFILE_END(L"SET Search - Random");
		CollapseCache();
		averageDepthRBT += rbTree.Depth();
		averageDepthBST += bsTree.Depth();
	}

	for (int i = 0; i < 1000; i++)
	{
		rbTree.Clear();
		bsTree.Clear();
		s.clear();
		shuffle(insertArr.begin(), insertArr.end(), std::default_random_engine(10));


		PROFILE_BEGIN(L"BSTREE - Random");
		for (int i = 0; i < 10000; i++)
		{
			bsTree.Insert(insertArr[i]);
		}
		PROFILE_END(L"BSTREE - Random");
		//cout << rbTree.Depth() << endl;
		CollapseCache();

		PROFILE_BEGIN(L"RBTREE - Random");
		for (int i = 0; i < 10000; i++)
		{
			rbTree.Insert(insertArr[i]);
		}
		PROFILE_END(L"RBTREE - Random");


		CollapseCache();


		PROFILE_BEGIN(L"SET - Random");
		for (int i = 0; i < 10000; i++)
		{
			s.insert(insertArr[i]);
		}
		PROFILE_END(L"SET - Random");

		//cout << rbTree.Depth() << endl;
		CollapseCache();

		PROFILE_BEGIN(L"BSTREE Search - Random");
		for (int i = 0; i < 10000; i++)
		{
			bsTree.Search(i);
		}
		PROFILE_END(L"BSTREE Search - Random");

		CollapseCache();

		PROFILE_BEGIN(L"RBTREE Search - Random");
		for (int i = 0; i < 10000; i++)
		{
			rbTree.Search(i);
		}
		PROFILE_END(L"RBTREE Search - Random");

		CollapseCache();

		PROFILE_BEGIN(L"SET Search - Random");
		for (int i = 0; i < 10000; i++)
		{
			s.contains(i);
		}
		PROFILE_END(L"SET Search - Random");



		CollapseCache();
		averageDepthRBT += rbTree.Depth();
		averageDepthBST += bsTree.Depth();
	}

	//for (int i = 0; i < 100; i++)
	//{
	//	rbTree.Clear();
	//	bsTree.Clear();
	//	insertArr.clear();
	//	deleteArr.clear();
	//	findArr.clear();

	//	for (int i = 0; i < 100000; i++)
	//	{
	//		int32 insertValue = rand() % 100001;
	//		int32 deleteValue = rand() % 100001;
	//		int32 findValue	= rand() % 100001;
	//		insertArr.push_back(insertValue);
	//		deleteArr.push_back(deleteValue);
	//		findArr.push_back(findValue);
	//	}

	//	PROFILE_BEGIN(L"BSTREE - Random");
	//	for (int i = 0; i < 100000; i++)
	//	{
	//		bsTree.Insert(insertArr[i]);
	//	}
	//	PROFILE_END(L"BSTREE - Random");
	//	averageDepthBST += bsTree.Depth();

	//	PROFILE_BEGIN(L"RBTREE - Random");
	//	for (int i = 0; i < 100000; i++)
	//	{
	//		rbTree.Insert(insertArr[i]);
	//	}
	//	PROFILE_END(L"RBTREE - Random");
	//	averageDepthRBT += rbTree.Depth();

	//	PROFILE_BEGIN(L"BSTREE Search - Random");
	//	for (int i = 0; i < 100000; i++)
	//	{
	//		bsTree.Search(i);
	//	}
	//	PROFILE_END(L"BSTREE Search - Random");

	//	PROFILE_BEGIN(L"RBTREE Search - Random");
	//	for (int i = 0; i < 100000; i++)
	//	{
	//		rbTree.Search(i);
	//	}
	//	PROFILE_END(L"RBTREE Search - Random");
	//}

	//rbTree.Clear();
	//bsTree.Clear();

	//insertArr.clear();
	//deleteArr.clear();
	//findArr.clear();

	PROFILE_CSV_OUT();
	PROFILE_DATA_OUT();

	cout <<"BST Average Depth : "  << (double)bsTree.SearchDepth() / 200000000 << endl;
	cout <<"RBT Average Depth : "  << (double)rbTree.SearchDepth() / 200000000 << endl;


	set<int32> source;
	//while (true)
	//{
	//	int32 insertValue = rand() % MAX_VALUE;
	//	int32 deleteValue = rand() % MAX_VALUE;

	//	if (rbTree.Insert(insertValue) == true)
	//	{
	//	//tree.PrintTree();
	//		cout << "Insert " << insertValue << endl;
	//		source.insert(insertValue);
	//	}

	//	if (rbTree.Delete(deleteValue) == true)
	//	{
	//	//tree.PrintTree();
	//		cout << "Delete " << deleteValue << endl;
	//		source.erase(deleteValue);
	//	}

	//	vector<int32> dest;
	//	rbTree.MakeVector(dest);

	//	if (source.size() != dest.size())
	//		__debugbreak();

	//	int32 idx = 0;
	//	for (int32 i : source)
	//	{
	//		if (i != dest[idx])
	//			__debugbreak();
	//		idx++;
	//	}


	//	if (dest.size() == 1000)
	//		cout << "Test Complete\n";
	//	//_getch();
	//}


	return 0;
}