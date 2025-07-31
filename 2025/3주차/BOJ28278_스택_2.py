'''🧩 전체 설계 흐름 요약
연결 리스트로 스택의 구조 구현

객체지향적으로 동작을 Stack 클래스에 분리

문제 입출력 로직은 main()에서 관리

직접 실행과 import 구분을 위해 __name__ == "__main__" 사용'''

import sys
input = sys.stdin.readline

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None  # 다음 노드를 가리킴

class Stack:
    def __init__(self):
        self.top = None  
        self.count = 0

    def push(self, x):
        new_node = Node(x)
        new_node.next = self.top  # 새 노드가 현재 top을 가리킴
        self.top = new_node       # top을 새 노드로 갱신
        self.count += 1

    def pop(self):
        if self.empty():
            return -1
        popped_data = self.top.data
        self.top = self.top.next  # top을 다음 노드로 이동
        self.count -= 1
        return popped_data

    def size(self):
        return self.count

    def empty(self):
        return 1 if self.top is None else 0

    def top_value(self):
        if self.empty():
            return -1
        return self.top.data


'''
| 함수            | 설명                           |
| ------------- | ---------------------------- |
| `push(x)`     | 새 `Node(x)` 생성 후 top 앞에 붙임   |
| `pop()`       | `top` 노드를 제거하고 다음 노드로 top 이동 |
| `empty()`     | `top`이 `None`인지 확인           |
| `top_value()` | 현재 top의 data를 반환 (없으면 -1)    |
'''
def main():
    n = int(input())
    s = Stack()

    for _ in range(n):
        cmd = input().split()
        if cmd[0] == '1':
            s.push(int(cmd[1]))
        elif cmd[0] == '2':
            print(s.pop())
        elif cmd[0] == '3':
            print(s.size())
        elif cmd[0] == '4':
            print(s.empty())
        elif cmd[0] == '5':
            print(s.top_value())

'''이 파일이 직접 실행될 때만 main() 함수를 실행하라'''

if __name__ == "__main__":
    main()
    
