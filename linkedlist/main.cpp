#include <iostream>

using namespace std;

template <class T> class LinkedList {
private:
    struct Node
    {
        T data;
        Node* next;
        Node(T val, Node* link = 0) :data(val), next(link) {}
    };

    Node* head;
public:
    LinkedList() :head(0) {}

    bool empty() const { return head == 0; }

    void addFirst(const T& val);
    void addLast(const T& val);
    void display();
};

template <class T> void LinkedList<T>::addFirst(const T& val) {
    Node* n = new Node(val);
    n->next = head;
    head = n;
}

template <class T> void LinkedList<T>::addLast(const T& val) {
    if (head == 0) { return addFirst(val); }
    Node* p = head;
    while (p != 0) {
        p = p->next;
    }
    Node* n = new Node(val);
    p->next = n;
}

template <class T> void LinkedList<T>::display() {
    cout << "[";
    for (Node* n = head; n != 0; n = n->next) {
        cout << n->data;
        if (n->next != 0) {
            cout << " ,";
        }
    }

    cout << "]";
}



int main() {

    LinkedList<int> marks;
    marks.addFirst(2);
    marks.addFirst(3);
    marks.addFirst(4);
    marks.addFirst(5);
    marks.display();
    return 0;
}