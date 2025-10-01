#include <iostream>
#include <string>
using namespace std;

	struct Node {
		int data;
		Node* next;
	};

	class Stack {
	private:
		Node* top;
		int count;
	public:
		Stack() : top(nullptr), count(0) {}

		~Stack() { // 메모리 정리(권장)
			while (top) {
				Node* tmp = top;
				top = top->next;
				delete tmp;
			}
		}

		void push(int X) {
			Node* new_node = new Node();
			new_node->data = X;

			new_node->next = top;
			top = new_node;
			count++;
		}

		int pop() {
			if (top == nullptr) {
				return -1;
			}
			int popped = top->data;
			Node* temp = top;
			top = top->next;
			count--;
			delete temp;
			return popped;
		}

		int size() const{
			return count;
		}

		bool empty() const{
			return top == nullptr;
		}
		int Top() const{
		if (top == nullptr) {
			return -1;
		}
		return top->data;
	}
	};
	

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	Stack stack;
	int N; cin >> N;
	while (N--) {
		string cmd[2];
		cin >> cmd[0];
		if (cmd[0] == "push") {
			cin >> cmd[1];
			stack.push(stoi(cmd[1]));
		}
		else if (cmd[0] == "pop") {
			cout << stack.pop() << "\n";
		}
		else if (cmd[0] == "size") {
			cout << stack.size() << "\n";
		}
		else if (cmd[0] == "empty") {
			cout << ((stack.empty()) ? 1 : 0) << "\n";
		}
		else if (cmd[0] == "top") {
			cout << stack.Top() << "\n";
		}
	}
	return 0;
}