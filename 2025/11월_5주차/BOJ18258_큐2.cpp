#include <iostream>
#include <stdexcept>
using namespace std;

/*
큐의 일반적인 의미는

push → 뒤에 넣기(tail 쪽)

pop → 앞에서 빼기(head 쪽)
인데, 여기서는 “앞에 넣고(head 쪽)” 있어서 스택처럼 동작함.
*/


struct Node {
	int data;
	Node* next;
	Node* prev;
	Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};
	

class Queue{
private:
	Node* head;
	Node* tail;
	int _size;
public:
	Queue() : head(nullptr), tail(nullptr), _size(0) {}
	~Queue() {
		while (!empty()) {
			pop();
		}
	}


	/*
처음에는 head == tail == nullptr 이니까 true 가 맞는데,

노드가 1개 있을 때는

head == tail 이지만 nullptr 는 아님 → false

즉, “비어 있지 않다”를 잘 표현하긴 해.
	*/
	bool empty() const{
		//return head == tail && tail == nullptr;
		return head == nullptr;
	}

	void push(int val) {
		Node* newNode = new Node(val);

		if (empty()) {
			head = tail = newNode;
		}
		else {
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		_size++;
	}

	void pop() {
		if (empty()) return;

		Node* temp = head;
		head = head->next;

		if (head != nullptr) {
			head->prev = nullptr;
		}
		else {
			// 모두 삭제되어 공백 상태
			tail = nullptr;
		}

		delete temp;
		_size--;
	}

	int front() const{
		if (empty()) {
			throw runtime_error("Queue is empty");
		}
		return head->data;
	}

	int back() const{
		if (empty()) {
			throw runtime_error("Queue is empty");
		}
		return tail->data;
	}

	int size() const{
		return _size;
	}

};