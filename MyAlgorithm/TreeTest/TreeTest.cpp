// TreeTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <set>
#include <map>
#include <string>

using namespace std;

//set, map 자료구조 예제
int main()
{
	//set
	set<int> odds{ 1, 7, 5, 3, 9 };
	set<int, greater<>> evens{ 2, 4, 6, 8 };
	evens.insert(10);
	evens.insert(2);

	for (auto n : odds)
		cout << n << ", ";
	cout << endl;

	for (auto n : evens)
		cout << n << ", ";
	cout << endl;

	if (evens.find(4) != evens.end())
	{
		cout << "4 is found!" << endl;
	}
	else
	{
		cout << "4 is not found!" << endl;
	}

	//map
	map<string, int> fruits;
	fruits.insert({ "apple", 1000 });
	fruits.insert({ "banana", 1500 });
	fruits["orange"] = 3000;
	fruits["grape"] = 4000;
	fruits["lemon"] = 5000;

	fruits["apple"] = 2000;
	fruits.erase("grape");

	for (auto &p : fruits)
		cout << p.first << " is " << p.second << "won" << endl;

}


//이진 탐색 트리 예제
//struct Node
//{
//	int data;
//	Node* left;
//	Node* right;
//
//	//생성자
//	Node(int d) : data(d), left(nullptr), right(nullptr) {}
//};
//
//class BinarySerchTree
//{
//private:
//	Node* root = nullptr;
//
//public:
//	~BinarySerchTree()
//	{
//		//트리 삭제
//		delete_tree(root);
//	}
//
//	//매개변수로 받은 value를 가진 노드 삽입
//	void insert(int value)
//	{
//		if (!root)
//		{
//			root = new Node(value);
//		}
//		else
//		{
//			//root 노드를 가진 트리에 삽입
//			insert_impl(root, value);
//		}
//	}
//
//	//매개변수로 받은 value를 가진 노드를 찾아라
//	Node* find(int value)
//	{
//		//root 아래에 value를 가진 노드 찾기
//		return find_impl(root, value);
//	}
//
//	//중위 순회: 이진탐색 트리에서는 오름차순으로 순회(출력)
//	void inorder()
//	{
//		//root 노드 기준으로 중위순회
//		inorder_impl(root);
//	}
//
//	//매개변수 value를 가진 노드를 삭제
//	void erase(int value)
//	{
//		root = erase_impl(root, value);
//	}
//	
//private:
//	//매개변수 node 아래에 value를 가진 노드 삽입
//	void insert_impl(Node* curr, int value)
//	{
//		//현재노드와 value의 비교
//		if (value < curr->data)
//		{
//			//왼쪽 노드에 삽입
//			if (!curr->left)
//				curr->left = new Node(value);
//			else
//				insert_impl(curr->left, value);
//		}
//		else
//		{
//			//오른쪽 노드에 삽입
//			if (!curr->right)
//				curr->right = new Node(value);
//			else
//				insert_impl(curr->right, value);
//		}
//	}
//
//	//매개변수 node 아래에 value를 가진 노드 찾기
//	Node* find_impl(Node* curr, int value)
//	{
//		if (curr == nullptr)
//			return nullptr;
//
//		if(value == curr->data)
//		{
//			return curr;
//		}
//		else
//		{
//			//현재노드와 value의 비교
//			if (value < curr->data)
//				return find_impl(curr->left, value);
//			else
//				return find_impl(curr->right, value);
//		}
//	}
//
//	//매개 변수 node 노드 기준으로 중위순회
//	void inorder_impl(Node* curr)
//	{
//		if (curr)
//		{
//			inorder_impl(curr->left);
//			cout << curr->data << ", ";
//			inorder_impl(curr->right);
//		}
//	}
//
//	//매개변수 node의 후속 노드 찾기
//	Node* successor(Node* node)
//	{
//		auto curr = node->right;
//		while (curr && curr->left)
//		{
//			curr = curr->left;
//		}
//
//		return curr;
//	}
//
//	//매개변수 node 아래에서 value를 가진 노드를 삭제
//	//노드 삭제후에 부모 노드 포인터가 가리켜야 할 노드 반환
//	Node* erase_impl(Node* node, int value)
//	{
//		//노드 체크
//		if (!node)
//			return nullptr;
//
//		if (value < node->data)
//		{
//			node->left = erase_impl(node->left, value);
//		}
//		else if (value > node->data)
//		{
//			node->right = erase_impl(node->right, value);
//		}
//		else //현재 노드 삭제, 값이 같으면
//		{
//			if (node->left && node->right)
//			{
//				//자식 노드가 둘 다 있는 경우
//				auto succ = successor(node);
//				node->data = succ->data;
//				//후속 노드 삭제
//				node->right = erase_impl(node->right, succ->data);
//			}
//			else
//			{
//				//자식 노드가 둘 다 없거나 (null 반환)
//				//한쪽만 있는 경우 (있는 자식 반환)
//				auto tmp = node->left ? node->left : node->right;
//				delete node;
//				return tmp;
//			}
//		}
//
//		return node;
//	}
//
//	//트리삭제 - 후위 순회로 삭제
//	void delete_tree(Node* node)
//	{
//		if (node)
//		{
//			delete_tree(node->left);
//			delete_tree(node->right);
//			delete node;
//		}
//	}
//};
//
//
//int main()
//{
//	BinarySerchTree bst;
//	bst.insert(10);
//	bst.insert(14);
//	bst.insert(5);
//	bst.insert(7);
//	bst.insert(18);
//	bst.insert(4);
//	bst.insert(6);
//	bst.insert(20);
//	bst.insert(16);
//
//	bst.inorder();
//	cout << endl;
//
//	if (bst.find(7))
//		cout << "7 is found" << endl;
//	else
//		cout << "7 is not found" << endl;
//
//	if (bst.find(15))
//		cout << "15 is found" << endl;
//	else
//		cout << "15 is not found" << endl;
//
//	bst.insert(9);
//	bst.insert(12);
//
//	bst.inorder();
//	cout << endl;
//
//	bst.erase(4);
//	bst.erase(5);
//	bst.erase(14);
//
//	bst.inorder();
//	cout << endl;
//
//	bst.insert(15);
//	bst.erase(10);
//
//	bst.inorder();
//	cout << endl;
//}

////이진트리 - Node : data 변수, 왼쪽자식, 오른쪽 자식
//struct Node
//{
//	char data;
//	Node* left;		//왼쪽 자식
//	Node* right;	//오른쪽 자식
//
//	//생성자 - 저장할 데이터를 매개변수로 받아 온다
//	Node(char d) : data(d), left(nullptr), right(nullptr) {}
//};
//
////전위 순회 - 매개변수로 받은 노드의 서브트리를 전위 순회
////현재->왼쪽->오른쪽
//void preorder(Node* node)
//{	
//	if (node)
//	{	
//		cout << node->data << ", ";	//데이터 출력, 연산
//		preorder(node->left);		//왼쪽 방문
//		preorder(node->right);		//왼쪽 방문
//	}
//}
//
////중위 순회 - 매개변수로 받은 노드의 서브트리를 중위 순회
////왼쪽->현재->오른쪽
//void inorder(Node* node)
//{
//	if (node)
//	{
//		inorder(node->left);
//		cout << node->data << ", "; //데이터 출력, 연산
//		inorder(node->right);
//	}
//}
//
////후위 순회 - 매개변수로 받은 노드의 서브트리를 후위 순회
////왼쪽->오른쪽->현재
//void postorder(Node* node)
//{
//	if (node)
//	{
//		postorder(node->left);
//		postorder(node->right);
//		cout << node->data << ", ";		//출력, 연산...
//	}
//}
//
////레벨 순서 순회
////큐에서 현재 노드를 꺼냄과 동시에 왼쪽과 오른쪽을 큐에 넣는다
//void levelorder(Node* node)
//{
//	std::queue<Node*> q;
//	q.push(node);			//순회할 트리의 가장 상단 노드(Root 노드)
//
//	while (!q.empty())
//	{
//		auto curr = q.front();
//		q.pop();
//
//		cout << curr->data << ", ";
//		if (curr->left) q.push(curr->left);
//		if (curr->right) q.push(curr->right);
//
//	}
//}
//
//// 트리 삭제 (모든 노드 삭제) - 후위 순회로 삭제
//void delete_tree(Node* node)
//{
//	if (node)
//	{
//		delete_tree(node->left);
//		delete_tree(node->right);
//		delete node;
//	}
//}
//
//
//int main()
//{
//
//	Node* root = new Node('A');
//	root->left = new Node('B');
//	root->right = new Node('C');
//	root->left->left = new Node('D');
//	root->left->right = new Node('E');
//	root->right->right = new Node('F');
//
//	/*
//			A
//		B       C
//	  D   E       F
//	*/
//
//	preorder(root);	// A B D E C F
//	cout << endl;
//
//	inorder(root);  // D B E A C F
//	cout << endl;
//
//	postorder(root);	// D E B F C A
//	cout << endl;
//
//	levelorder(root);	// A B C D E F
//	cout << endl;
//
//	//tree delete
//	delete_tree(root);
//}

//int main()
//{
//    std::cout << "Hello Tree!\n";
//}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
