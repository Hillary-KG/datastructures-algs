"""
A stack is a linear data structure that allows items to be added (pushed) and removed (popped) only from one end, called the top. 
This last-in, first-out (LIFO) structure is useful for certain types of problems, such as undo/redo and balancing symbols in code.
Here is an example of how a stack can be implemented in Python using a list:

"""


class Stack:
    def __init__(self):
        # initialize an empty list to store the stack elements
        self.items = []

    def is_empty(self):
        # return True if the stack is empty, False otherwise
        return not self.items

    def push(self, item):
        # add an item to the top of the stack
        self.items.append(item)

    def pop(self):
        # remove and return the top item from the stack, or None if the stack is empty
        return self.items.pop() if not self.is_empty() else None

    def peek(self):
        # return the top item from the stack, or None if the stack is empty
        return self.items[-1] if not self.is_empty() else None

# test
stack = Stack()
stack.push(1)
stack.push(2)
stack.push(3)
print(stack.peek())  # 3
print(stack.pop())   # 3
print(stack.pop())   # 2
print(stack.pop())   # 1
print(stack.pop())   # None
