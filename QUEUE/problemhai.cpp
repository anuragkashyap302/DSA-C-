class MyCircularQueue {
    int* arr;
    int k;
    int qfront;
    int qrear;

public:
    MyCircularQueue(int k) {
        arr = new int[k];
        qfront = -1;
        qrear = -1;
    }
    
    bool enQueue(int value) {
        if ((qfront == 0 && qrear == k - 1) || (qrear == (qfront - 1) % (k - 1))) {
            return false;  // Queue is full
        }
        else if (qfront == -1) { // Queue is empty
            qfront = qrear = 0;
            arr[qrear] = value;
        }
        else if (qrear == k - 1 && qfront != 0) { // Wrap around
            qrear = 0;
            arr[qrear] = value;
        }
        else { // Normal case
            qrear++;
            arr[qrear] = value;
        }
        return true;
    }
    
    bool deQueue() {
        if (qfront == -1) {
            return false; // Queue is empty
        }
        if (qfront == qrear) { // Single element
            qfront = qrear = -1;
        }
        else if (qfront == k - 1) { // Wrap around
            qfront = 0;
        }
        else {
            qfront++;
        }
        return true;
    }

    int Front() {
        if (qfront == -1) {
            return -1; // Queue is empty
        }
        return arr[qfront];
    }

    int Rear() {
        if (qfront == -1) {
            return -1; // Queue is empty
        }
        return arr[qrear];
    }

    bool isEmpty() {
        return qfront == -1;
    }
    
    bool isFull() {
        return (qfront == 0 && qrear == k - 1) || (qrear == (qfront - 1) % (k - 1));
    }

    ~MyCircularQueue() {
        delete[] arr;
    }
};

/*["MyCircularQueue","enQueue","enQueue","deQueue","enQueue","deQueue","enQueue","deQueue","enQueue","deQueue", "Front"]
[[2],[1],[2],[],[3],[],[3],[],[3],[],[]] again i am geeting error in this test test
*/