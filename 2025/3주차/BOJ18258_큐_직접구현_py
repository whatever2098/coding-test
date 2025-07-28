import sys
input = sys.stdin.readline

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None  # 다음 노드를 가리키는 참조

class Queue:
    def __init__(self):
        self.front = None  # 맨 앞 노드
        self.rear = None   # 맨 뒤 노드
        self.size = 0

    def push(self, x):
        new_node = Node(x)
        if self.rear:
            self.rear.next = new_node
        self.rear = new_node
        if self.front is None:
            self.front = new_node
        self.size += 1

    def pop(self):
        if self.front is None:
            return -1
        data = self.front.data
        self.front = self.front.next
        if self.front is None:  # 다 꺼낸 경우 rear도 None으로
            self.rear = None
        self.size -= 1
        return data

    def get_size(self):
        return self.size

    def is_empty(self):
        return 1 if self.size == 0 else 0

    def get_front(self):
        return -1 if self.front is None else self.front.data

    def get_back(self):
        return -1 if self.rear is None else self.rear.data

q = Queue()
n = int(input())
for _ in range(n):
    cmd = input().split()
    if cmd[0] == 'push':
        q.push(int(cmd[1]))
    elif cmd[0] == 'pop':
        print(q.pop())
    elif cmd[0] == 'size':
        print(q.get_size())
    elif cmd[0] == 'empty':
        print(q.is_empty())
    elif cmd[0] == 'front':
        print(q.get_front())
    elif cmd[0] == 'back':
        print(q.get_back())
