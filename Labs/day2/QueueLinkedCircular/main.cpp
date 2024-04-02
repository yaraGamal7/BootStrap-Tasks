#include <iostream>
#include <string.h>

using namespace std;

class Queue {
    int *arr;
    int size;
    int front;
    int rear;

public:
    Queue(int _size) {
        size = _size;
        arr = new int[size];
        front = rear = -1; // Initially empty
    }

    int isFull() {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            return 1;
        } else {
            return 0;
        }
    }

    int isEmpty() {
        if(front == -1)
            return 1;
        else
            return 0;
    }

    void enQueue(int d) {
        if (isFull()) {
            cout << "Queue is Full" << endl;
            return;
        }

        if (front == -1) {
            front = rear = 0;
        } else if (rear == size - 1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }

        arr[rear] = d;
    }

    int deQueue(int &d) {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return 0;
        }

        d = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }
        return 1;
    }

    ~Queue() {
        delete[] arr;
        cout<<"destrctor";
    }
};

int main() {
    Queue q(5);

    // Enqueue elements
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(30);
    q.enQueue(30);
    q.enQueue(30);
    q.enQueue(30);


    int dequeuedElement;
    while (q.deQueue(dequeuedElement)) {
        cout << "Dequeued: " << dequeuedElement << endl;
    }

    q.enQueue(300);
    q.enQueue(400);
    q.enQueue(500);

    while (q.deQueue(dequeuedElement)) {
        cout << "Dequeued: " << dequeuedElement << endl;
    }


    return 0;
}
