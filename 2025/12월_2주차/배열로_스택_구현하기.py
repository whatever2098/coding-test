import sys
input = sys.stdin.readline

class Stack:
    def __init__(self):
        self.frontIndex = 0
        self.backIndex = 0
        
        self.stack = []
    
    def push(self, data: int) -> None:
        self.stack.append(data)
        self.backIndex += 1

    def pop(self) ->int:
        if self.isEmpty():
            return -1
        data = self.stack.pop()
        self.backIndex -= 1
        return data

    def size(self) -> int:
        return self.backIndex - self.frontIndex
        
    def isEmpty(self) -> bool:
        return self.size() == 0

    def top(self) -> int:
        if self.isEmpty():
            return -1
        return self.stack[-1]



