#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
    
    // Constructor
    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Stack using Linked List
class Stack {
private:
    Node* top;  // Pointer to the top of the stack
    
public:
    // Constructor
    Stack() {
        top = NULL;
    }
    
    // Push operation - Add element at top
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << value << " onto stack\n";
    }
    
    // Pop operation - Remove and return element from top
    int pop() {
        // Edge case 1: Stack is empty
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop from empty stack.\n";
            return -1;
        }
        
        Node* temp = top;
        int value = temp->data;
        top = top->next;
        delete temp;
        cout << "Popped " << value << " from stack\n";
        return value;
    }
    
    // Peek operation - View top element without removing
    int peek() {
        // Edge case 1: Stack is empty
        if (isEmpty()) {
            cout << "Stack is empty! No top element.\n";
            return -1;
        }
        cout << "Top element is: " << top->data << "\n";
        return top->data;
    }
    
    // Check if stack is empty
    bool isEmpty() {
        return top == NULL;
    }
    
    // Get size of stack
    int size() {
        int count = 0;
        Node* temp = top;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    
    // Display all elements in stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty! Nothing to display.\n";
            return;
        }
        
        cout << "Stack elements (Top to Bottom): ";
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    
    // Clear the stack
    void clear() {
        while (!isEmpty()) {
            pop();
        }
        cout << "Stack cleared!\n";
    }
    
    // Destructor - Free memory
    ~Stack() {
        clear();
    }
};

// Main function with examples covering all edge cases
int main() {
    cout << "===== STACK IMPLEMENTATION USING LINKED LIST =====\n\n";
    
    Stack s;
    
    // Edge Case 1: Peek/Pop on empty stack
    cout << "--- Edge Case 1: Operations on Empty Stack ---\n";
    s.peek();
    s.pop();
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << "\n";
    cout << "Stack size: " << s.size() << "\n\n";
    
    // Edge Case 2: Single element
    cout << "--- Edge Case 2: Single Element ---\n";
    s.push(42);
    s.display();
    s.peek();
    cout << "Stack size: " << s.size() << "\n\n";
    
    // Edge Case 3: Push-Pop-Push sequence
    cout << "--- Edge Case 3: Push-Pop-Push Sequence ---\n";
    s.push(10);
    s.push(20);
    s.display();
    s.pop();
    s.display();
    s.push(30);
    s.display();
    cout << "Stack size: " << s.size() << "\n\n";
    
    // Edge Case 4: Multiple pushes
    cout << "--- Edge Case 4: Multiple Pushes ---\n";
    s.push(5);
    s.push(15);
    s.push(25);
    s.push(35);
    s.display();
    cout << "Stack size: " << s.size() << "\n\n";
    
    // Edge Case 5: Pop all elements
    cout << "--- Edge Case 5: Pop All Elements ---\n";
    while (!s.isEmpty()) {
        s.pop();
    }
    s.display();
    cout << "Stack size: " << s.size() << "\n\n";
    
    // Edge Case 6: Alternating push and pop
    cout << "--- Edge Case 6: Alternating Push and Pop ---\n";
    s.push(100);
    s.display();
    s.pop();
    s.display();
    s.push(200);
    s.push(300);
    s.display();
    s.pop();
    s.display();
    cout << "Stack size: " << s.size() << "\n\n";
    
    // Edge Case 7: Large sequence of operations
    cout << "--- Edge Case 7: Large Sequence ---\n";
    for (int i = 1; i <= 5; i++) {
        s.push(i * 10);
    }
    s.display();
    cout << "Stack size: " << s.size() << "\n";
    
    cout << "Popping elements:\n";
    for (int i = 0; i < 3; i++) {
        int val = s.pop();
    }
    s.display();
    cout << "Stack size: " << s.size() << "\n\n";
    
    // Edge Case 8: Clear and verify empty
    cout << "--- Edge Case 8: Clear Stack ---\n";
    s.clear();
    cout << "After clear - Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << "\n";
    s.display();
    cout << "Stack size: " << s.size() << "\n\n";
    
    // Edge Case 9: Peek without pop
    cout << "--- Edge Case 9: Peek Operations ---\n";
    s.push(111);
    s.push(222);
    s.push(333);
    s.display();
    s.peek();
    s.peek();  // Peek again - element should still be there
    s.display();
    cout << "Stack size: " << s.size() << "\n\n";
    
    // Edge Case 10: Mixed operations
    cout << "--- Edge Case 10: Mixed Operations ---\n";
    s.push(444);
    cout << "Size: " << s.size() << "\n";
    s.display();
    s.pop();
    s.peek();
    s.push(555);
    s.push(666);
    s.display();
    s.pop();
    s.pop();
    s.pop();
    cout << "After multiple pops:\n";
    s.display();
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << "\n";
    s.pop();  // Pop from empty - should show error
    cout << "\n";
    
    cout << "===== PROGRAM END =====\n";
    
    return 0;
}
