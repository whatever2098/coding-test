#include <iostream>
#include <string>
using namespace std;

struct Node {
	int val;
	Node* prev;
	Node* next;
	Node(int v) :val(v), prev(nullptr), next(nullptr) {}
};

class Deque {
private:
	Node* head;
	Node* tail;
	int cnt{ 0 };
public:
	Deque(): head(nullptr), tail(nullptr), cnt(0) {}
	~Deque() {
		while (!empty()) pop_front();
	}

	bool empty() const {
		return cnt == 0;
	}
	int size() const { return cnt; }

	int front() const {
		if (empty()) return -1; 
		return head->val;
	}
	int back() const { 
		if (empty()) return -1;
		return tail->val; }

	int pop_front() {
		//덱 내부에 값이 존재하면,
		if (empty()) { return -1; }
		//변수에 임시로 head를 복사함.
		Node* t = head;
		//역시 임시로 head의 value를 복사함.
		int v = t->val;
		//다음 노드가 헤드가 됨.
		head = head->next;
		//연결 업데이트
		if (head) { head->prev = nullptr; }
		else { tail = nullptr; }
		//임시 tail을 지운다.
		delete t;
		--cnt;
		return v;
	}

	int pop_back() {
		if (empty()) { return -1; }
		Node* t = tail;
		int v = t->val;
		tail = tail->prev;
		if (tail) { tail->next = nullptr; }
		else { head = nullptr; }
		delete t;
		--cnt;
		return v;
	}

	void push_front(int x) {
		Node* node = new Node(x);
		if (empty()) { head = tail = node; }
		else {
			node->next = head;
			head->prev = node;
			head = node;
		}
		++cnt;
	}

	void push_back(int x) {
		Node* node = new Node(x);
		if (empty()) { head = tail = node; }
		else {
			tail->next = node;
			node->prev = tail;
			tail = node;
		}
		++cnt;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	Deque D;

	int N;
	cin >> N;

	while (N--) {
		string cmd;
		int num;
		cin >> cmd;
		if (cmd == "push_front") {
			cin >> num;
			D.push_front(num);
		}
		else if (cmd == "push_back") {
			cin >> num;
			D.push_back(num);
		}
		else if (cmd == "pop_front") {
			cout << D.pop_front() << "\n";
		}
		else if (cmd == "pop_back") {
			cout << D.pop_back() << "\n";
		}
		else if (cmd == "size") {
			cout << D.size() << "\n";
		}
		else if (cmd == "empty") {
			cout << D.empty() << "\n";
		}
		else if (cmd == "front") {
			cout << D.front() << "\n";
		}
		else if (cmd == "back") {
			cout << D.back() << "\n";
		}
	}
}