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

// Queue using Linked List
class Queue {
private:
    Node* front;  // Pointer to the front of the queue
    Node* rear;   // Pointer to the rear of the queue
    
public:
    // Constructor
    Queue() {
        front = NULL;
        rear = NULL;
    }
    
    // Enqueue operation - Add element at rear
    void enqueue(int value) {
        Node* newNode = new Node(value);
        
        // If queue is empty
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued " << value << " into queue\n";
    }
    
    // Dequeue operation - Remove and return element from front
    int dequeue() {
        // Edge case 1: Queue is empty
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue from empty queue.\n";
            return -1;
        }
        
        Node* temp = front;
        int value = temp->data;
        front = front->next;
        
        // If queue becomes empty after dequeue
        if (front == NULL) {
            rear = NULL;
        }
        
        delete temp;
        cout << "Dequeued " << value << " from queue\n";
        return value;
    }
    
    // Peek operation - View front element without removing
    int peek() {
        // Edge case 1: Queue is empty
        if (isEmpty()) {
            cout << "Queue is empty! No front element.\n";
            return -1;
        }
        cout << "Front element is: " << front->data << "\n";
        return front->data;
    }
    
    // Check if queue is empty
    bool isEmpty() {
        return front == NULL && rear == NULL;
    }
    
    // Get size of queue
    int size() {
        int count = 0;
        Node* temp = front;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    
    // Display all elements in queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty! Nothing to display.\n";
            return;
        }
        
        cout << "Queue elements (Front to Rear): ";
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    
    // Get rear element
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty! No rear element.\n";
            return -1;
        }
        cout << "Rear element is: " << rear->data << "\n";
        return rear->data;
    }
    
    // Clear the queue
    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
        cout << "Queue cleared!\n";
    }
    
    // Destructor - Free memory
    ~Queue() {
        clear();
    }
};

// Main function with examples covering all edge cases
int main() {
    cout << "===== QUEUE IMPLEMENTATION USING LINKED LIST =====\n\n";
    
    Queue q;
    
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
    cout << "Front: " << q.peek() << " Rear: " << q.getRear() << "\n";
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
    cout << "Front: " << q.peek() << " Rear: " << q.getRear() << "\n";
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
    
    // Edge Case 10: Clear and verify
    cout << "--- Edge Case 10: Clear Queue ---\n";
    q.clear();
    cout << "After clear - Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << "\n";
    q.display();
    cout << "Queue size: " << q.size() << "\n\n";
    
    // Edge Case 11: Peek operations (no removal)
    cout << "--- Edge Case 11: Peek Operations (No Removal) ---\n";
    q.enqueue(555);
    q.enqueue(666);
    q.enqueue(777);
    q.display();
    q.peek();
    q.peek();  // Peek again - elements should still be there
    q.display();
    cout << "Queue size: " << q.size() << "\n\n";
    
    // Edge Case 12: Mixed operations with error handling
    cout << "--- Edge Case 12: Mixed Operations with Error Handling ---\n";
    q.enqueue(888);
    q.display();
    cout << "Front: " << q.peek() << " Rear: " << q.getRear() << "\n";
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << "After multiple dequeues:\n";
    q.display();
    q.dequeue();  // Dequeue from empty - should show error
    q.peek();     // Peek on empty - should show error
    cout << "\n";
    
    cout << "===== PROGRAM END =====\n";
    
    return 0;
}
