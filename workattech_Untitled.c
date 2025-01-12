// Online C Compiler
// Use this online editor to compile and run C code online
#include <stdio.h>

int main() {
	// your code goes here
	printf("Hello World");
	return 0;
}class Stack:
    def __init__(self):
        self.items = []
    
    def is_empty(self):
        return len(self.items) == 0
    
    def push(self, item):
        self.items.append(item)
    
    def pop(self):
        if not self.is_empty():
            return self.items.pop()
        return None
    
    def peek(self):
        if not self.is_empty():
            return self.items[-1]
        return None

# Function to check precedence of operators
def precedence(op):
    if op in ('+', '-'):
        return 1
    if op in ('*', '/'):
        return 2
    return 0

# Function to perform arithmetic operations
def apply_operator(op, a, b):
    if op == '+': return a + b
    if op == '-': return a - b
    if op == '*': return a * b
    if op == '/': return a // b  # Integer division
    return 0

# Function to evaluate a postfix expression
def evaluate_postfix(expression):
    stack = Stack()
    for char in expression:
        if char.isdigit():
            stack.push(int(char))
        else:
            b = stack.pop()
            a = stack.pop()
            result = apply_operator(char, a, b)
            stack.push(result)
    return stack.pop()

# Function to convert infix to postfix
def infix_to_postfix(expression):
    stack = Stack()
    postfix = []
    for char in expression:
        if char.isdigit():
            postfix.append(char)
        elif char in ('+', '-', '*', '/'):
            while (not stack.is_empty() and
                   precedence(stack.peek()) >= precedence(char)):
                postfix.append(stack.pop())
            stack.push(char)
        elif char == '(':
            stack.push(char)
        elif char == ')':
            while not stack.is_empty() and stack.peek() != '(':
                postfix.append(stack.pop())
            stack.pop()  # Remove '('
    while not stack.is_empty():
        postfix.append(stack.pop())
    return ''.join(postfix)

# Main function to evaluate infix expression
def evaluate_infix(expression):
    postfix = infix_to_postfix(expression)
    print(f"Postfix Expression: {postfix}")
    return evaluate_postfix(postfix)

# Example Usage
if __name__ == "__main__":
    expression = "3+(5*2)-9"  # You can input any valid infix expression
    result = evaluate_infix(expression)
    print(f"Result: {result}")
