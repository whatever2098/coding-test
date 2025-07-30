#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class Stack {
private:
    Node* frontNode;
    int count;

public:
    Stack() : frontNode(nullptr), count(0) {}

    ~Stack() {
        while (!empty()) {
            pop();
        }
    }


설명: 새 노드를 생성하고,
새 노드의 next가 기존의 frontNode(맨 위)를 가리키게 한 뒤,
frontNode를 새 노드로 바꿉니다.
count를 1 증가시킵니다.
정상 동작: 스택의 LIFO(후입선출) 구조를 잘 구현하고 있습니다.
새 노드를 생성하고,
새 노드의 next가 기존의 frontNode(맨 위)를 가리키게 한 뒤,
frontNode를 새 노드로 바꿉니다.
count를 1 증가시킵니다.
정상 동작: 스택의 LIFO(후입선출) 구조를 잘 구현하고 있습니다.

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = frontNode; // 항상 맨 앞에 추가
        frontNode = newNode;
        count++;
    }

    int pop() {
        if (empty()) return -1;
        int ret = frontNode->data;
        Node* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        count--;
        return ret;
    }

    int size() { return count; }

    int empty() { return count == 0 ? 1 : 0; }

    int top() { // 문제에서 front() 요구시 이름만 바꾸세요
        if (empty()) return -1;
        return frontNode->data;
    }
};