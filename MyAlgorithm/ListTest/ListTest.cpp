// ListTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

//int data를 가진 node list 구현
struct Node
{
	int data;
	Node* next;
};

class LinkedList
{
private:
	Node* head;

public:
	//생성자
	LinkedList() : head(NULL) {};

	//소멸자
	~LinkedList()
	{

	}

	//리스트 맨 앞에 데이터(value) 삽입하기
	void push_pront(int value)
	{
		//삽입할 노드 생성 (data:value, next:NULL 초기화)
		Node* new_node = new Node{ value , NULL };

		//데이터 있으면
		if (head != NULL)
		{
			new_node->next = head;
		}

		head = new_node;
	}

	//리스트 맨 앞에 있는 데이터 삭제
	void pop_front()
	{
		//데이터 없으면
		if (head == NULL)
		{
			return;
		}

		Node* first = head;
		head = first->next;
		delete first;
	}

	//리스트의 모든 노드 데이터 출력하기
	void print_all()
	{
		Node* curr = head;

		//반복문
		while (curr != NULL)
		{
			cout << curr->data << ", ";
			//노드 자신의 next로 다음 노드의 주소를 가져온다
			curr = curr->next;
		}
		cout << endl;
	}

	//데이터 유무 체크
	bool empty()
	{
		return head == NULL;
	}
};



int main()
{

}

//int main()
//{
//    std::cout << "Hello List!\n";
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
