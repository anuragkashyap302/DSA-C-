#include <iostream>
#include <queue>
using namespace std;

// Stack using Queue (using two queues approach)
// Approach: push() is O(n), pop() is O(1)
class StackUsingQueue {
private:
    queue<int> q1;  // Main queue
    queue<int> q2;  // Helper queue
    
public:
    // Constructor
    StackUsingQueue() {
        // Empty constructor
    }
    
    // Push operation - Add element to stack
    // Time Complexity: O(n)
    void push(int value) {
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        
        // Add new element to q1
        q1.push(value);
        
        // Move all elements back from q2 to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        
        cout << "Pushed " << value << " onto stack\n";
    }
    
    // Pop operation - Remove and return top element
    // Time Complexity: O(1)
    int pop() {
        // Edge case: Stack is empty
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop from empty stack.\n";
            return -1;
        }
        
        int value = q1.front();
        q1.pop();
        cout << "Popped " << value << " from stack\n";
        return value;
    }
    
    // Peek operation - View top element without removing
    int peek() {
        // Edge case: Stack is empty
        if (isEmpty()) {
            cout << "Stack is empty! No top element.\n";
            return -1;
        }
        cout << "Top element is: " << q1.front() << "\n";
        return q1.front();
    }
    
    // Check if stack is empty
    bool isEmpty() {
        return q1.empty();
    }
    
    // Get size of stack
    int size() {
        return q1.size();
    }
    
    // Display all elements in stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty! Nothing to display.\n";
            return;
        }
        
        cout << "Stack elements (Top to Bottom): ";
        queue<int> temp = q1;  // Create temporary copy
        while (!temp.empty()) {
            cout << temp.front() << " -> ";
            temp.pop();
        }
        cout << "END\n";
    }
    
    // Clear the stack
    void clear() {
        while (!isEmpty()) {
            pop();
        }
        cout << "Stack cleared!\n";
    }
};

// Alternative: Stack using Single Queue
// Approach: push() is O(n), pop() is O(1)
class StackUsingSingleQueue {
private:
    queue<int> q;
    
public:
    // Constructor
    StackUsingSingleQueue() {
        // Empty constructor
    }
    
    // Push operation - Add element to stack
    void push(int value) {
        q.push(value);
        
        // Rotate queue to maintain stack behavior
        // Move all elements except the last one to the back
        for (int i = 0; i < (int)q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        
        cout << "Pushed " << value << " onto stack (Single Queue)\n";
    }
    
    // Pop operation - Remove and return top element
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop from empty stack.\n";
            return -1;
        }
        
        int value = q.front();
        q.pop();
        cout << "Popped " << value << " from stack (Single Queue)\n";
        return value;
    }
    
    // Peek operation
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty! No top element.\n";
            return -1;
        }
        cout << "Top element is: " << q.front() << "\n";
        return q.front();
    }
    
    // Check if stack is empty
    bool isEmpty() {
        return q.empty();
    }
    
    // Get size of stack
    int size() {
        return q.size();
    }
    
    // Display all elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty! Nothing to display.\n";
            return;
        }
        
        cout << "Stack elements (Top to Bottom): ";
        queue<int> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " -> ";
            temp.pop();
        }
        cout << "END\n";
    }
    
    // Clear the stack
    void clear() {
        while (!isEmpty()) {
            pop();
        }
        cout << "Stack cleared!\n";
    }
};

// Main function with examples covering all edge cases
int main() {
    cout << "===== STACK USING QUEUE (TWO QUEUES APPROACH) =====\n\n";
    
    StackUsingQueue s;
    
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
    
    // Edge Case 4: Multiple pushes (verify LIFO)
    cout << "--- Edge Case 4: Multiple Pushes (LIFO Order) ---\n";
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
    
    cout << "Popping 3 elements:\n";
    for (int i = 0; i < 3; i++) {
        s.pop();
    }
    s.display();
    cout << "Stack size: " << s.size() << "\n\n";
    
    // Edge Case 8: Clear and verify
    cout << "--- Edge Case 8: Clear Stack ---\n";
    s.clear();
    cout << "After clear - Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << "\n";
    s.display();
    cout << "Stack size: " << s.size() << "\n\n";
    
    // Edge Case 9: Peek without pop
    cout << "--- Edge Case 9: Peek Operations (No Removal) ---\n";
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
    
    // ===== SINGLE QUEUE APPROACH =====
    cout << "\n===== STACK USING QUEUE (SINGLE QUEUE APPROACH) =====\n\n";
    
    StackUsingSingleQueue s2;
    
    // Edge Case 1: Operations on empty stack
    cout << "--- Edge Case 1: Operations on Empty Stack ---\n";
    s2.peek();
    s2.pop();
    cout << "Is stack empty? " << (s2.isEmpty() ? "Yes" : "No") << "\n";
    cout << "Stack size: " << s2.size() << "\n\n";
    
    // Edge Case 2: Single element
    cout << "--- Edge Case 2: Single Element ---\n";
    s2.push(50);
    s2.display();
    s2.peek();
    cout << "Stack size: " << s2.size() << "\n\n";
    
    // Edge Case 3: Multiple pushes (verify LIFO)
    cout << "--- Edge Case 3: Multiple Pushes ---\n";
    s2.push(60);
    s2.push(70);
    s2.push(80);
    s2.push(90);
    s2.display();
    cout << "Stack size: " << s2.size() << "\n\n";
    
    // Edge Case 4: Pop all elements
    cout << "--- Edge Case 4: Pop All Elements ---\n";
    while (!s2.isEmpty()) {
        s2.pop();
    }
    s2.display();
    cout << "Stack size: " << s2.size() << "\n\n";
    
    // Edge Case 5: Alternating operations
    cout << "--- Edge Case 5: Alternating Push-Pop ---\n";
    s2.push(100);
    s2.push(200);
    s2.display();
    s2.pop();
    s2.display();
    s2.push(300);
    s2.push(400);
    s2.display();
    cout << "Stack size: " << s2.size() << "\n\n";
    
    // Edge Case 6: Peek operations
    cout << "--- Edge Case 6: Peek Operations ---\n";
    s2.display();
    s2.peek();
    s2.peek();  // Peek again
    s2.display();
    cout << "Stack size: " << s2.size() << "\n\n";
    
    // Edge Case 7: Complex sequence
    cout << "--- Edge Case 7: Complex Sequence ---\n";
    for (int i = 1; i <= 4; i++) {
        s2.push(i * 100);
    }
    s2.display();
    s2.pop();
    s2.pop();
    s2.display();
    s2.push(999);
    s2.display();
    cout << "Stack size: " << s2.size() << "\n\n";
    
    // Edge Case 8: Clear
    cout << "--- Edge Case 8: Clear Stack ---\n";
    s2.clear();
    s2.display();
    cout << "\n";
    
    cout << "===== PROGRAM END =====\n";
    cout << "\nNote: Two Queues Approach:\n";
    cout << "  - push(): O(n) time, O(n) space\n";
    cout << "  - pop(): O(1) time\n\n";
    cout << "Single Queue Approach:\n";
    cout << "  - push(): O(n) time, O(1) extra space\n";
    cout << "  - pop(): O(1) time\n";
    
    return 0;
}
