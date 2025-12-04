// 배열 기반 Stack(Static Array Version)
/*
* 📌핵심 개념
top은 “현재 스택의 가장 위 인덱스ˮ
초기 top = -1

push:
arr[++top] = x

 pop:
return arr[top--]
*/

#include <iostream>
#include <stdexcept>
using namespace std;
class Stack
{
private:
    static const int MAX = 10000; // 배열 최대 크기
    int arr[MAX];
    int topIndex; // 스택의 top을 가리키는 인덱스

public:
    Stack() : topIndex(-1) {}
    bool empty() const
    {
        return topIndex == -1;
    }
    bool full() const
    {
        return topIndex == MAX - 1;
    }
    int size() const
    {
        return topIndex + 1;
    }
    void push(int val)
    {
        if (full())
        {
            throw runtime_error("Stack Overflow");
        }
        arr[++topIndex] = val; // top 이동 후 값 삽입
    }
    int pop()
    {
        if (empty())
        {
            throw runtime_error("Stack Underflow");
        }
        return arr[topIndex--]; // 값 반환 후 top 감소
    }
    int top() const
    {
        if (empty())
        {
            throw runtime_error("Stack is empty");
        }
        return arr[topIndex];
    }
};