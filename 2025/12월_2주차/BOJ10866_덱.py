import sys
input = sys.stdin.readline

class Node:
    def __init__(self,data: int):
        self.data = data
        self.prev = None
        self.next = None

class Deque:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

        def push_front(self, data: int) -> None:
            node = Node(data)
            if self.size == 0:
                head = tail = node
            else:
                node.next = self.head
                self.head.prev = node
                self.head = node
            self.size += 1

        def push_back(self, data: int) -> None:
            node = Node(data)
            if self.size == 0:
                head = tail = node
            else:
                node.prev = self.tail
                self.tail.next = node
                tail = node
            self.size += 1

        def pop_front(self) -> int:
            if self.size == 0:
                return -1
            data = self.head.data
            self.head = self.head.next
            if self.head:
                self.head.prev = None
            self.size -= 1
            return data

        def pop_back(self) -> int:
            if self.size == 0:
                return -1
            data = self.tail.data
            self.tail = self.tail.prev
            if self.tail:
                self.tail.next = None
            self.size -= 1
            return data