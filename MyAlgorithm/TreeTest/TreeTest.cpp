// TreeTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

//이진트리 - Node : data 변수, 왼쪽자식, 오른쪽 자식
struct Node
{
	char data;
	Node* left;		//왼쪽 자식
	Node* right;	//오른쪽 자식

	//생성자 - 저장할 데이터를 매개변수로 받아 온다
	Node(char d) : data(d), left(nullptr), right(nullptr) {}
};

//전위 순회 - 매개변수로 받은 노드의 서브트리를 전위 순회
//현재->왼쪽->오른쪽
void preorder(Node* node)
{	
	if (node)
	{	
		cout << node->data << ", ";	//데이터 출력, 연산
		preorder(node->left);		//왼쪽 방문
		preorder(node->right);		//왼쪽 방문
	}
}

//중위 순회 - 매개변수로 받은 노드의 서브트리를 중위 순회
//왼쪽->현재->오른쪽
void inorder(Node* node)
{
	if (node)
	{
		inorder(node->left);
		cout << node->data << ", "; //데이터 출력, 연산
		inorder(node->right);
	}
}

//후위 순회 - 매개변수로 받은 노드의 서브트리를 후위 순회
//왼쪽->오른쪽->현재
void postorder(Node* node)
{
	if (node)
	{
		postorder(node->left);
		postorder(node->right);
		cout << node->data << ", ";		//출력, 연산...
	}
}

int main()
{

	Node* root = new Node('A');
	root->left = new Node('B');
	root->right = new Node('C');
	root->left->left = new Node('D');
	root->left->right = new Node('E');
	root->right->right = new Node('F');

	/*
			A
		B       C
	  D   E       F
	*/

	preorder(root);	// A B D E C F
	cout << endl;

	inorder(root);  // D B E A C F
	cout << endl;

	postorder(root);	// D E B F C A
	cout << endl;

	//tree delete
}

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
