
#include <iostream>
#include "errors.cpp"

using namespace std;

template <class T> class LinkedList {
private:
    struct Node
    {
        Node* next;
        T data;
        Node(const T& val, Node* link = 0) :data(val), next(link) { };
    };
    Node* head;
public:
    LinkedList() :head(0) { };
    bool empty();
    void addFirst(const T& val);
    void addLast(const T& val);
    void del(const T& val);
    void delFirst();
    void delLast();
    void reverse();
    void display();
};

template <class T> bool LinkedList<T>::empty() {
    return head == 0;
}

template <class T> void LinkedList<T>::addFirst(const T& val) {
    Node* n = new Node(val);
    n->next = head;
    head = n;
}
template <class T> void LinkedList<T>::addLast(const T& val) {
    if (empty()) { addFirst(val);return; }
    Node* last = head;
    while (last->next != 0)last = last->next;
    Node* n = new Node(val);
    last->next = n;
}

template <class T> void LinkedList<T>::delFirst() {
    if (empty()) {
        LinkedListError("List is empty");
        return;
    }
    Node* n = head;
    head = n->next;
    delete n;
}

template <class T> void LinkedList<T>::delLast() {
    if (empty()) {
        LinkedListError("List is empty");
        return;
    }
    Node* prev;
    Node* last = head;
    while (last->next != 0) { prev = last;last = last->next; }
    prev->next = 0;
    delete last;
}

template <class T> void LinkedList<T>::del(const T& val) {
    if (empty()) {
        LinkedListError("List is empty");
        return;
    }
    if (head->data == val) {
        delFirst();
        return;
    }
    Node* last = head;
    Node* prev;
    while (last != 0 && last->data != val) {
        prev = last;
        last = last->next;
    }
    if (last == 0) {
        LinkedListError("Item Not Found");
        return;
    }
    prev->next = last->next;
    delete last;
}

template <class T> void LinkedList<T>::display() {
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

template <class T> void LinkedList<T>::reverse() {
    if (empty()) {
        LinkedListError("List is empty");
        return;
    }

    Node* prev = 0;
    Node* current = head;
    Node* next = 0;

    while (current != 0) {
        next = current->next; // Save the next node
        current->next = prev;  // Reverse the link
        prev = current;        // Move prev one step forward
        current = next;        // Move current one step forward
    }

    head = prev; // Update head to the new front of the list
}