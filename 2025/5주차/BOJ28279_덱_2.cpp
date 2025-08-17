#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node(int v) : val(v), prev(nullptr), next(nullptr) {}
};

class Deque {
private:
    Node* head;  // front
    Node* tail;  // back
    int cnt;
public:
    Deque(): head(nullptr), tail(nullptr), cnt(0) {}
    ~Deque() {
        while (!empty()) pop_front();
    }

    bool empty() const { return cnt == 0; }
    int size()  const { return cnt; }

    void push_front(int x) {
        Node* n = new Node(x);
        if (empty()) {
            head = tail = n;
        } else {
            n->next = head;
            head->prev = n;
            head = n;
        }
        ++cnt;
    }
    void push_back(int x) {
        Node* n = new Node(x);
        if (empty()) {
            head = tail = n;
        } else {
            n->prev = tail;
            tail->next = n;
            tail = n;
        }
        ++cnt;
    }
    int pop_front() {
        if (empty()) return -1;
        Node* t = head;
        int v = t->val;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete t;
        --cnt;
        return v;
    }
    int pop_back() {
        if (empty()) return -1;
        Node* t = tail;
        int v = t->val;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete t;
        --cnt;
        return v;
    }
    int front() const { return empty() ? -1 : head->val; }
    int back()  const { return empty() ? -1 : tail->val; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    if (!(cin >> N)) return 0;

    Deque dq;

    while (N--) {
        int op; 
        cin >> op;
        if (op == 1) {
            int x; cin >> x; dq.push_front(x);
        } else if (op == 2) {
            int x; cin >> x; dq.push_back(x);
        } else if (op == 3) {
            cout << dq.pop_front() << '\n';
        } else if (op == 4) {
            cout << dq.pop_back() << '\n';
        } else if (op == 5) {
            cout << dq.size() << '\n';
        } else if (op == 6) {
            cout << (dq.empty() ? 1 : 0) << '\n';
        } else if (op == 7) {
            cout << dq.front() << '\n';
        } else if (op == 8) {
            cout << dq.back() << '\n';
        }
    }
    return 0;
}
