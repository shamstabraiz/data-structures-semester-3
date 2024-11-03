
#include <iostream>
#include "errors.cpp"
using namespace std;

template <class T> class DoublyLinkedList {

    struct Node {
        Node* next;
        Node* prev;
        T data;
        Node(const T& val, Node* nextLink = 0, Node* prevLink = 0) :data(val), next(nextLink), prev(prevLink) { };
    };
    Node* head;
public:
    DoublyLinkedList() :head(0) { };
    bool empty();
    void addFirst(const T& val);
    void addLast(const T& val);
    void del(const T& val);
    void delFirst();
    void delLast();
    void reverse();
    void display();
};

template <class T> bool DoublyLinkedList<T>::empty() {
    return head == 0;
}
template <class T> void DoublyLinkedList<T>::addFirst(const T& val) {
    Node* n = new Node(val);
    if (!empty()) {
        head->prev = n;
    }
    n->next = head;
    head = n;
}

template <class T> void DoublyLinkedList<T>::addLast(const T& val) {
    if (empty()) {
        addFirst(val);
        return;
    }
    Node* p = head;
    while (p->next != 0) {
        p = p->next;
    }
    Node* n = new Node(val);
    n->prev = p;
    p->next = n;
}
template <class T> void DoublyLinkedList<T>::del(const T& val) {
    if (empty()) {
        return;
    }
    Node* p = head;
    while (p != 0 && p->) {
        p = p->next;
    }
    Node* n = new Node(val);
    n->prev = p;
    p->next = n;
}


template <class T> void DoublyLinkedList<T>::display() {
    cout << "[";
    for (Node* n = head;n != 0; n = n->next)
    {
        if (n->next) {
            cout << n->data << " ,";
        }
        else {
            cout << n->data;
        }
    }
    cout << "]\n";
}

