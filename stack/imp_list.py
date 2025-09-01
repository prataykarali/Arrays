class N:
    def __init__(self, d):
        self.d = d
        self.n = None

class S:
    def __init__(self):
        self.t = None

    def push(self, d):
        node = N(d)
        node.n = self.t
        self.t = node

    def pop(self):
        if not self.t:
            return None
        x = self.t.d
        self.t = self.t.n
        return x

    def peek(self):
        return self.t.d if self.t else None

    def empty(self):
        return self.t is None

    def disp(self):
        c = self.t
        while c:
            print(c.d, end=' ')
            c = c.n
        print()
stk = S()
stk.push(10)
stk.push(20)
stk.push(30)
stk.disp()        
print(stk.pop())  
print(stk.peek()) 
stk.disp()        
