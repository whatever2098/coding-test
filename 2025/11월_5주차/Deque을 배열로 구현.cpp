/*Deque — Circular Array

📌핵심 구조
배열 크기 : MAX
front, rear 인덱스를 원형으로 관리
비어있는 상태 : front == rear

뒤에서
push_back:
rear = (rear + 1) % MAX
앞에서
push_front:
front = (front - 1 + MAX) % MAX
*/

#include <iostream>
#include <stdexcept>
using namespace std;
class Deque
{
private:
    static const int MAX = 10000 + 1; // 가득 찬 상태 구분을 위해 +1
    int arr[MAX];
    int front; // 가장 앞 요소 "바로 앞" 위치
    int back;  // 가장 뒤 요소 위치

public:
    Deque() : front(0), back(0) {}
    bool empty() const
    {
        return front == back;
    }
    bool full() const
    {
        return (back + 1) % MAX == front;
    }
    int size() const
    {
        return (back - front + MAX) % MAX;
    }

    // -------- push_front(x) ----=---
    void push_front(int val)
    {
        if (full())
            throw runtime_error("Deque is full");
        front = (front - 1 + MAX) % MAX;
        arr[front] = val;
    }

    // -------- push_back(x) -------
    void push_back(int val)
    {
        if (full())
            throw runtime_error("Deque is full");
        arr[back] = val;
        back = (back + 1) % MAX;
    }

    // -------- pop_front() -------
    int pop_front()
    {
        if (empty())
            throw runtime_error("Deque is empty");
        int val = arr[front];
        front = (front + 1) % MAX;
        return val;
    }

    // -------- pop_back() -------
    int pop_back()
    {
        if (empty())
            throw runtime_error("Deque is empty");
        back = (back - 1 + MAX) % MAX;
        return arr[back];
    }

    // -------- front value -------
    int get_front() const
    {
        if (empty())
            throw runtime_error("Deque is empty");
        return arr[front];
    }

    // -------- back value -------
    int get_back() const
    {
        if (empty())
            throw runtime_error("Deque is empty");
        return arr[(back - 1 + MAX) % MAX];
    }
};