#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Queue using Stack (Two Stacks Approach 1)
// Approach: enqueue() is O(1), dequeue() is O(n)
class QueueUsingStack {
private:
    stack<int> s1;  // Stack for enqueue operations
    stack<int> s2;  // Stack for dequeue operations
    
public:
    // Constructor
    QueueUsingStack() {
        // Empty constructor
    }
    
    // Enqueue operation - Add element to queue
    // Time Complexity: O(1)
    void enqueue(int value) {
        s1.push(value);
        cout << "Enqueued " << value << " into queue\n";
    }
    
    // Dequeue operation - Remove and return element from queue
    // Time Complexity: O(n) - amortized O(1)
    int dequeue() {
        // Edge case: Queue is empty
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue from empty queue.\n";
            return -1;
        }
        
        // If s2 is empty, transfer all elements from s1 to s2
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        int value = s2.top();
        s2.pop();
        cout << "Dequeued " << value << " from queue\n";
        return value;
    }
    
    // Peek operation - View front element without removing
    int peek() {
        // Edge case: Queue is empty
        if (isEmpty()) {
            cout << "Queue is empty! No front element.\n";
            return -1;
        }
        
        // If s2 is empty, transfer all elements from s1 to s2
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        cout << "Front element is: " << s2.top() << "\n";
        return s2.top();
    }
    
    // Get rear element
    int getRear() {
        // Edge case: Queue is empty
        if (isEmpty()) {
            cout << "Queue is empty! No rear element.\n";
            return -1;
        }
        
        if (!s1.empty()) {
            cout << "Rear element is: " << s1.top() << "\n";
            return s1.top();
        }
        
        cout << "Rear element is in s2\n";
        return -1;
    }
    
    // Check if queue is empty
    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
    
    // Get size of queue
    int size() {
        return s1.size() + s2.size();
    }
    
    // Display all elements in queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty! Nothing to display.\n";
            return;
        }
        
        cout << "Queue elements (Front to Rear): ";
        
        // Display s2 (front elements)
        stack<int> tempS2 = s2;
        while (!tempS2.empty()) {
            cout << tempS2.top() << " -> ";
            tempS2.pop();
        }
        
        // Display s1 (rear elements) in reverse
        stack<int> tempS1 = s1;
        vector<int> arr;
        while (!tempS1.empty()) {
            arr.push_back(tempS1.top());
            tempS1.pop();
        }
        
        for (int i = arr.size() - 1; i >= 0; i--) {
            cout << arr[i];
            if (i > 0 || !s2.empty()) cout << " -> ";
        }
        
        cout << " END\n";
    }
    
    // Clear the queue
    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
        cout << "Queue cleared!\n";
    }
};

// Alternative: Queue using Stack (Two Stacks Approach 2)
// Optimized: enqueue() is O(n), dequeue() is O(1)
class QueueUsingSingleStack {
private:
    stack<int> s1;  // Main stack
    stack<int> s2;  // Helper stack
    
public:
    // Constructor
    QueueUsingSingleStack() {
        // Empty constructor
    }
    
    // Enqueue operation
    // Time Complexity: O(n)
    void enqueue(int value) {
        // Transfer all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        
        // Push new element to s1
        s1.push(value);
        
        // Transfer all elements back from s2 to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        
        cout << "Enqueued " << value << " into queue (Single Stack Approach)\n";
    }
    
    // Dequeue operation
    // Time Complexity: O(1)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue from empty queue.\n";
            return -1;
        }
        
        int value = s1.top();
        s1.pop();
        cout << "Dequeued " << value << " from queue (Single Stack Approach)\n";
        return value;
    }
    
    // Peek operation
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty! No front element.\n";
            return -1;
        }
        
        cout << "Front element is: " << s1.top() << "\n";
        return s1.top();
    }
    
    // Check if queue is empty
    bool isEmpty() {
        return s1.empty();
    }
    
    // Get size of queue
    int size() {
        return s1.size();
    }
    
    // Display all elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty! Nothing to display.\n";
            return;
        }
        
        cout << "Queue elements (Front to Rear): ";
        stack<int> temp = s1;
        vector<int> arr;
        while (!temp.empty()) {
            arr.push_back(temp.top());
            temp.pop();
        }
        
        for (int i = arr.size() - 1; i >= 0; i--) {
            cout << arr[i];
            if (i > 0) cout << " -> ";
        }
        cout << " END\n";
    }
    
    // Clear the queue
    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
        cout << "Queue cleared!\n";
    }
};

// Main function with examples covering all edge cases
int main() {
    cout << "===== QUEUE USING STACK (TWO STACKS APPROACH) =====\n\n";
    
    QueueUsingStack q;
    
    // Edge Case 1: Peek/Dequeue on empty queue
    cout << "--- Edge Case 1: Operations on Empty Queue ---\n";
    q.peek();
    q.dequeue();
    q.getRear();
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << "\n";
    cout << "Queue size: " << q.size() << "\n\n";
    
    // Edge Case 2: Single element
    cout << "--- Edge Case 2: Single Element ---\n";
    q.enqueue(42);
    q.display();
    q.peek();
    q.getRear();
    cout << "Queue size: " << q.size() << "\n\n";
    
    // Edge Case 3: Enqueue-Dequeue-Enqueue sequence
    cout << "--- Edge Case 3: Enqueue-Dequeue-Enqueue Sequence ---\n";
    q.enqueue(10);
    q.enqueue(20);
    q.display();
    q.dequeue();
    q.display();
    q.enqueue(30);
    q.display();
    cout << "Queue size: " << q.size() << "\n\n";
    
    // Edge Case 4: Multiple enqueues (FIFO verification)
    cout << "--- Edge Case 4: Multiple Enqueues (FIFO Order) ---\n";
    q.enqueue(5);
    q.enqueue(15);
    q.enqueue(25);
    q.enqueue(35);
    q.display();
    cout << "Queue size: " << q.size() << "\n\n";
    
    // Edge Case 5: Dequeue all elements
    cout << "--- Edge Case 5: Dequeue All Elements ---\n";
    while (!q.isEmpty()) {
        q.dequeue();
    }
    q.display();
    cout << "Queue size: " << q.size() << "\n\n";
    
    // Edge Case 6: Alternating enqueue and dequeue
    cout << "--- Edge Case 6: Alternating Enqueue and Dequeue ---\n";
    q.enqueue(100);
    q.display();
    q.dequeue();
    q.display();
    q.enqueue(200);
    q.enqueue(300);
    q.display();
    q.dequeue();
    q.display();
    cout << "Queue size: " << q.size() << "\n\n";
    
    // Edge Case 7: Large sequence of operations
    cout << "--- Edge Case 7: Large Sequence ---\n";
    for (int i = 1; i <= 5; i++) {
        q.enqueue(i * 10);
    }
    q.display();
    cout << "Queue size: " << q.size() << "\n";
    
    cout << "Dequeueing 3 elements:\n";
    for (int i = 0; i < 3; i++) {
        q.dequeue();
    }
    q.display();
    cout << "Queue size: " << q.size() << "\n\n";
    
    // Edge Case 8: Enqueue after complete dequeue
    cout << "--- Edge Case 8: Enqueue After Complete Dequeue ---\n";
    q.enqueue(111);
    q.enqueue(222);
    q.display();
    cout << "Queue size: " << q.size() << "\n\n";
    
    // Edge Case 9: Multiple enqueue-dequeue cycles
    cout << "--- Edge Case 9: Multiple Cycles ---\n";
    q.dequeue();
    q.dequeue();
    q.display();
    
    for (int j = 0; j < 2; j++) {
        cout << "Cycle " << (j + 1) << ":\n";
        q.enqueue(400 + j);
        q.enqueue(500 + j);
        q.display();
        q.dequeue();
        q.display();
    }
    cout << "Queue size: " << q.size() << "\n\n";
    
    // Edge Case 10: Peek operations (no removal)
    cout << "--- Edge Case 10: Peek Operations (No Removal) ---\n";
    q.enqueue(555);
    q.enqueue(666);
    q.enqueue(777);
    q.display();
    q.peek();
    q.peek();  // Peek again - elements should still be there
    q.display();
    cout << "Queue size: " << q.size() << "\n\n";
    
    // Edge Case 11: Clear
    cout << "--- Edge Case 11: Clear Queue ---\n";
    q.clear();
    q.display();
    cout << "Queue size: " << q.size() << "\n\n";
    
    // Edge Case 12: Mixed operations with error handling
    cout << "--- Edge Case 12: Mixed Operations ---\n";
    q.enqueue(888);
    q.display();
    q.peek();
    q.getRear();
    q.dequeue();
    q.dequeue();  // Dequeue from empty - should show error
    q.peek();     // Peek on empty - should show error
    cout << "\n";
    
    // ===== SINGLE STACK APPROACH =====
    cout << "\n===== QUEUE USING STACK (SINGLE STACK APPROACH) =====\n\n";
    
    QueueUsingSingleStack q2;
    
    // Edge Case 1: Operations on empty queue
    cout << "--- Edge Case 1: Operations on Empty Queue ---\n";
    q2.peek();
    q2.dequeue();
    cout << "Is queue empty? " << (q2.isEmpty() ? "Yes" : "No") << "\n";
    cout << "Queue size: " << q2.size() << "\n\n";
    
    // Edge Case 2: Single element
    cout << "--- Edge Case 2: Single Element ---\n";
    q2.enqueue(50);
    q2.display();
    q2.peek();
    cout << "Queue size: " << q2.size() << "\n\n";
    
    // Edge Case 3: Multiple enqueues (verify FIFO)
    cout << "--- Edge Case 3: Multiple Enqueues (FIFO Order) ---\n";
    q2.enqueue(60);
    q2.enqueue(70);
    q2.enqueue(80);
    q2.enqueue(90);
    q2.display();
    cout << "Queue size: " << q2.size() << "\n\n";
    
    // Edge Case 4: Dequeue all elements
    cout << "--- Edge Case 4: Dequeue All Elements ---\n";
    while (!q2.isEmpty()) {
        q2.dequeue();
    }
    q2.display();
    cout << "Queue size: " << q2.size() << "\n\n";
    
    // Edge Case 5: Alternating operations
    cout << "--- Edge Case 5: Alternating Enqueue-Dequeue ---\n";
    q2.enqueue(100);
    q2.enqueue(200);
    q2.display();
    q2.dequeue();
    q2.display();
    q2.enqueue(300);
    q2.enqueue(400);
    q2.display();
    cout << "Queue size: " << q2.size() << "\n\n";
    
    // Edge Case 6: Peek operations
    cout << "--- Edge Case 6: Peek Operations ---\n";
    q2.display();
    q2.peek();
    q2.peek();  // Peek again
    q2.display();
    cout << "Queue size: " << q2.size() << "\n\n";
    
    // Edge Case 7: Complex sequence
    cout << "--- Edge Case 7: Complex Sequence ---\n";
    for (int i = 1; i <= 4; i++) {
        q2.enqueue(i * 100);
    }
    q2.display();
    q2.dequeue();
    q2.dequeue();
    q2.display();
    q2.enqueue(999);
    q2.display();
    cout << "Queue size: " << q2.size() << "\n\n";
    
    // Edge Case 8: Clear
    cout << "--- Edge Case 8: Clear Queue ---\n";
    q2.clear();
    q2.display();
    cout << "\n";
    
    cout << "===== PROGRAM END =====\n";
    cout << "\nTwo Stacks Approach (Optimized for Dequeue):\n";
    cout << "  - enqueue(): O(1) time\n";
    cout << "  - dequeue(): O(n) time, amortized O(1)\n\n";
    cout << "Single Stack Approach:\n";
    cout << "  - enqueue(): O(n) time\n";
    cout << "  - dequeue(): O(1) time\n";
    
    return 0;
}
