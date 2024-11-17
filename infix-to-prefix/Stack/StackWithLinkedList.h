#include <iostream>
#include <stdexcept>

using namespace std;

template <class T> class StackWithLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value, Node* link = 0) : data(value), next(link) { }
    };

    Node* top;

public:
    StackWithLinkedList();
    ~StackWithLinkedList();

    void push(const T& x);
    T pop();
    T peek();
    bool isEmpty();
    void print();
};

template <class T> StackWithLinkedList<T>::StackWithLinkedList() : top(0) { }

template <class T> StackWithLinkedList<T>::~StackWithLinkedList() {
    while (!isEmpty()) {
        pop();
    }
}

template <class T> void StackWithLinkedList<T>::push(const T& x) {
    Node* newNode = new Node(x);
    newNode->next = top; // Link the new node to the current top
    top = newNode;       // Update the top to the new node
}

template <class T> T StackWithLinkedList<T>::pop() {
    if (isEmpty()) {
        throw underflow_error("Stack is empty");
    }

    Node* temp = top;
    T data = top->data;
    top = top->next; // Update top to the next node
    delete temp;     // Free the memory of the popped node

    return data;
}

template <class T> T StackWithLinkedList<T>::peek() {
    if (isEmpty()) {
        throw underflow_error("Stack is empty");
    }
    return top->data;
}

template <class T> bool StackWithLinkedList<T>::isEmpty() {
    return top == 0;
}

template <class T> void StackWithLinkedList<T>::print() {
    Node* n = top;
    while (n != 0) {
        cout << n->data;
        n = n->next;
    }
}

