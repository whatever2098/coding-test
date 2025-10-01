import sys
input = sys.stdin.readline

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Queue:
    def __init__(self):
        self.head = None
        self.tail = None
        self.count = 0
    
    def push(self, data):
        new_node = new Node(data)
        if self.empty():
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node
        self.count += 1

    def pop(self):
        if self.empty():
            return -1
        popped_node = self.head.data
        self.head = self.head.next
        self.count -= 1
        if self.head is None:
            self.tail = None
        return popped_node

    def size(self):
        return self.count

    def empty(self):
        return self.count == 0
    
    def front(self):
        if self.empty():
            return -1
        return self.head.data

    def back(self):
        if self.empty():
            return -1
        return self.tail.data

def main():
    queue = Queue()
    N = (int(input()))
    for _ in range(N):
        cmd = input().strip().split()
        if cmd[0] == "push":
            queue.push(int(cmd[1]))
        elif cmd[0] == "pop":
            print(queue.pop())
        elif cmd[0] == "size":
            print(queue.size())
        elif cmd[0] == "empty":
            print(1 if queue.empty() else 0)
        elif cmd[0] == "front":
            print(queue.front())
        elif cmd[0] == "back":
            print (queue.back())


if __name__ == "__main__":
    main()
        