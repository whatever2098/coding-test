import sys
input = sys.stdin.readline

class Node:
    def __init__(self, data: int):
        self.data = data
        self.prev = None
        self.next = None

class Deque:
    def __init__(self):
        self.frontNode = None
        self.backNode = None
        self.count = 0

    # 상태
    def empty(self) -> bool:
        return self.count == 0

    def size(self) -> int:
        return self.count

    # 조회
    def front(self) -> int:
        return -1 if self.empty() else self.frontNode.data

    def back(self) -> int:
        return -1 if self.empty() else self.backNode.data

    # 삽입
    def push_front(self, x: int) -> None:
        new_node = Node(x)
        if self.empty():
            self.frontNode = self.backNode = new_node
        else:
            new_node.next = self.frontNode
            self.frontNode.prev = new_node
            self.frontNode = new_node
        self.count += 1

    def push_back(self, x: int) -> None:
        new_node = Node(x)
        if self.empty():
            self.frontNode = self.backNode = new_node
        else:
            new_node.prev = self.backNode
            self.backNode.next = new_node
            self.backNode = new_node
        self.count += 1

    # 삭제
    def pop_front(self) -> int:
        if self.empty():
            return -1
        t = self.frontNode
        val = t.data
        self.frontNode = t.next
        if self.frontNode is not None:
            self.frontNode.prev = None
        else:
            self.backNode = None
        self.count -= 1
        t.prev = t.next = None  # (디버깅용, 필수는 아님)
        return val

    def pop_back(self) -> int:
        if self.empty():
            return -1
        t = self.backNode
        val = t.data
        self.backNode = t.prev
        if self.backNode is not None:
            self.backNode.next = None
        else:
            self.frontNode = None
        self.count -= 1
        t.prev = t.next = None
        return val

def main():
    n = int(input())
    dq = Deque()
    out = []

    for _ in range(n):
        cmd = input().split()
        op = int(cmd[0])

        if op == 1:       # push_front X
            dq.push_front(int(cmd[1]))
        elif op == 2:     # push_back X
            dq.push_back(int(cmd[1]))
        elif op == 3:     # pop_front
            out.append(str(dq.pop_front()))
        elif op == 4:     # pop_back
            out.append(str(dq.pop_back()))
        elif op == 5:     # size
            out.append(str(dq.size()))
        elif op == 6:     # empty
            out.append("1" if dq.empty() else "0")
        elif op == 7:     # front
            out.append(str(dq.front()))
        elif op == 8:     # back
            out.append(str(dq.back()))

    sys.stdout.write("\n".join(out))

if __name__ == "__main__":
    main()

