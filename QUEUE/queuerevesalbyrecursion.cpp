#include <iostream>
#include <queue>

// Function to reverse the queue using recursion
void reverseQueue(std::queue<int>& q) {
    // Base case: If the queue is empty, return
    if (q.empty()) {
        return;
    }

    // Dequeue the front element
    int front = q.front();
    q.pop();

    // Recursively reverse the remaining queue
    reverseQueue(q);

    // Enqueue the dequeued element to the back of the queue
    q.push(front);
}

int main() {
    std::queue<int> q;

    // Enqueue some elements
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    std::cout << "Original Queue: ";
    std::queue<int> tempQ = q; // Copy the queue to display its content
    while (!tempQ.empty()) {
        std::cout << tempQ.front() << " ";
        tempQ.pop();
    }
    std::cout << std::endl;

    // Reverse the queue
    reverseQueue(q);

    std::cout << "Reversed Queue: ";
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;

    return 0;
}
