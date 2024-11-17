#include <iostream>
#include <stdexcept>

using namespace std;

template <class T> class QueueWithLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value, Node* link = 0) : data(value), next(link) { }
    };

    Node* front;
    Node* rear;

public:
    QueueWithLinkedList();
    ~QueueWithLinkedList();

    void insert(T x);
    T extract();
    T peek();
    bool isEmpty();
};

template <class T> QueueWithLinkedList<T>::QueueWithLinkedList() : front(0), rear(0) { }

template <class T> QueueWithLinkedList<T>::~QueueWithLinkedList() {
    while (!isEmpty()) {
        extract(); // Clean up dynamically allocated nodes
    }
}

template <class T> void QueueWithLinkedList<T>::insert(T x) {
    Node* newNode = new Node(x);

    if (!rear) { // If the queue is empty
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }

}

template <class T> T QueueWithLinkedList<T>::extract() {
    if (isEmpty()) {
        throw underflow_error("Queue is empty");
    }

    Node* temp = front;
    T data = front->data;
    front = front->next;

    if (!front) { // If the queue becomes empty, reset rear to 0
        rear = 0;
    }

    delete temp;
    return data;
}

template <class T> T QueueWithLinkedList<T>::peek() {
    if (isEmpty()) {
        throw underflow_error("Queue is empty");
    }
    return front->data;
}

template <class T> bool QueueWithLinkedList<T>::isEmpty() {
    return front == 0;
}

