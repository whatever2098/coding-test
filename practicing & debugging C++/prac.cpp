#include <iostream>
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
	int cnt;
public:
	Deque(): head(nullptr), tail(nullptr), cnt(0) {}
	~Deque() {
		while (!empty()) pop_front();
	}

	bool empty() const {
		return cnt == 0;
	}
	int size() const { return cnt; }
};