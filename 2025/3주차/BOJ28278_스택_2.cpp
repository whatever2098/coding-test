#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

class Stack {
private:
    Node* topNode;
    int count;

public:
    Stack() : topNode(nullptr), count(0) {}

    ~Stack() {
        while(topNode != nullptr){
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp; 
        }
    }


    /*
    설명: 새 노드를 생성하고,
    push : 새 노드의 next가 기존의 topNode(맨 위)를 가리키게 한 뒤,
    topNode를 새 노드로 바꿉니다.
    count를 1 증가시킵니다.
    정상 동작: 스택의 LIFO(후입선출) 구조를 잘 구현하고 있습니다.
    */

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = topNode; // 항상 맨 앞에 추가
        topNode = newNode;
        count++;
    }

    int pop() {
        if (topNode == nullptr) return -1;
        int ret = topNode->data;
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        count--;
        return ret;
    }

    int size() { return count; }

    int empty() { return count == 0 ? 1 : 0; }

    int top() {
        if (topNode  == nullptr) return -1;
        return topNode->data;
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    Stack* stack = new Stack();

    int N;
    cin >> N;

    while(N--){
        int cmd;
        cin >> cmd;
        switch(cmd) {
            case 1: {
                int x; cin >> x;
                stack->push(x);
                break;
            }
            case 2: {
                if (stack->empty()){ 
                    cout << -1 << "\n"; break; }
                int res = stack->top();
                stack->pop();
                cout << res << "\n";
                break;
            }
            case 3: {
                cout << stack->size() << "\n";
                break;
            }
            case 4: {
                cout << ((stack->empty())? 1 : 0) << "\n"; break;
            }
            case 5: {
                if(stack->empty()){ cout << -1 << "\n"; break;}
                cout << stack->top() << "\n";
                break;
            }
        }

    }
}