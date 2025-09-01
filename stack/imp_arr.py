class Stack:
    def __init__(self, size):
        self.size = size
        self.arr = [None] * size
        self.top = -1

    def isEmpty(self):
        return self.top == -1

    def isFull(self):
        return self.top == self.size - 1

    def push(self, x):
        if self.isFull():
            print("Stack Overflow")
        else:
            self.top += 1
            self.arr[self.top] = x

    def pop(self):
        if self.isEmpty():
            print("Stack Underflow")
        else:
            val = self.arr[self.top]
            self.top -= 1
            return val

    def peek(self):
        if self.isEmpty():
            print("Stack is Empty")
        else:
            return self.arr[self.top]

    def display(self):
        if self.isEmpty():
            print("Stack is Empty")
        else:
            for i in range(self.top, -1, -1):
                print(self.arr[i], end=" ")
            print()
s = Stack(5)
s.push(10)
s.push(20)
s.push(30)
s.display()      
print(s.pop())   
print(s.peek())  
s.display()      
