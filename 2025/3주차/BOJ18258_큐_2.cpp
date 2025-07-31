#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class Queue {
private:
    Node* frontNode;
    Node* backNode;
    int count;

public:
    Queue() : frontNode(nullptr), backNode(nullptr), count(0) {}

    ~Queue() {
        Node* current = frontNode;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    void push(int x) {
        Node* newNode = new Node(x);
        if (frontNode == nullptr) {
            frontNode = backNode = newNode;
        } else {
            backNode->next = newNode;
            backNode = newNode;
        }
        count++;
    }

    int pop() {
        if (frontNode == nullptr) return -1;
        int ret = frontNode->data;
        Node* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        count--;
        if (frontNode == nullptr) backNode = nullptr;
        return ret;
    }

    int size() { return count; }
    int empty() { return frontNode == nullptr ? 1 : 0; }
    int front() { return frontNode == nullptr ? -1 : frontNode->data; }
    int back() { return backNode == nullptr ? -1 : backNode->data; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Queue q;

    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int x; cin >> x;
            q.push(x);
        }
        else if (cmd == "pop") {
            cout << q.pop() << "\n";
        }
        else if (cmd == "size") {
            cout << q.size() << "\n";
        }
        else if (cmd == "empty") {
            cout << q.empty() << "\n";
        }
        else if (cmd == "front") {
            cout << q.front() << "\n";
        }
        else if (cmd == "back") {
            cout << q.back() << "\n";
        }
    }

    return 0;
}
