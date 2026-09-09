#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int front;
    int rear;
    int count;      // current number of elements
    int capacity;   // max size N

public:
    // Constructor
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    // Destructor to free memory
    ~Queue() {
        delete[] arr;
    }

    // Check if queue is full
    bool isFull() {
        return count == capacity;
    }

    // Check if queue is empty
    bool isEmpty() {
        return count == 0;
    }

    // ENQUEUE - insert at rear
    void enqueue(int value) {
        if (isFull()) {
            cout << "Overflow! Queue is full. Cannot insert " << value << endl;
            return;
        }
        rear = (rear + 1) % capacity;   // circular increment
        arr[rear] = value;
        count++;
        cout << "Enqueued: " << value << endl;
    }

    // DEQUEUE - remove from front
    void dequeue() {
        if (isEmpty()) {
            cout << "Underflow! Queue is empty. Cannot dequeue." << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front = (front + 1) % capacity; // circular increment
        count--;
    }

    // Peek at front element
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element." << endl;
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    // Display current state of queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue state (front to rear): ";
        int i = front;
        for (int j = 0; j < count; j++) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    int N = 5;
    Queue q(N);

    // Fill the queue
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    // Try to overflow
    q.enqueue(60);   // should trigger overflow message

    q.display();

    // Dequeue a couple of elements
    q.dequeue();
    q.dequeue();

    q.display();

    // Enqueue more (space freed by dequeue)
    q.enqueue(60);
    q.enqueue(70);

    q.display();

    // Drain the queue completely
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    // Try to underflow
    q.dequeue();   // should trigger underflow message

    q.display();

    return 0;
}