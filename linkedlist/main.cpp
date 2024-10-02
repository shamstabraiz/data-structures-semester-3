#include <iostream>

using namespace std;
class ListEmptyExeption {};
class ListItemNotFoundExecption {};
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
    void deleteFirst();
    void deleteItem(const T& val);
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
    while (p->next != 0) {
        p = p->next;
    }
    Node* n = new Node(val);
    p->next = n;
}


template <class T> void LinkedList<T>::display() {
    cout << "[";
    for (Node* n = head; n != 0; n = n->next) {
        cout << n->data;
        if (n->next != 0) { cout << " ,"; }
    }
    cout << "]\n";
}


template <class T> void LinkedList<T>::deleteFirst() {
    if (head == 0) { throw ListEmptyExeption(); return; }
    Node* n = head;
    T val = n->data;
    head = n->next;
    delete n;
}

template <class T> void LinkedList<T>::deleteItem(const T& val) {
    if (head == 0) { throw ListEmptyExeption(); return; };
    if (head->data == val) { deleteFirst();return; }
    Node* n = head;
    Node* p = head;

    while (n->next != 0 && n->data != val)
    {
        p = n;
        n = n->next;
    }

    if (n->next == 0) {
        throw ListItemNotFoundExecption();
        return;
    }
    p->next = n->next;
    delete n;
    return;
}



int main() {

    LinkedList<int> marks;
    marks.addFirst(4);
    marks.addFirst(3);
    marks.addFirst(2);
    marks.addFirst(1);
    marks.addLast(5);
    marks.addLast(6);
    marks.addLast(7);
    marks.addLast(8);
    marks.display();
    try {
        marks.deleteFirst();
    }
    catch (ListEmptyExeption& e) {
        cout << "error list is empty\n";
    }

    try {
        marks.deleteItem(4);
    }
    catch (ListItemNotFoundExecption& e) {
        cout << "The item is not found in the list\n";
    }

    try {
        marks.deleteItem(50);
    }
    catch (ListItemNotFoundExecption& e) {
        cout << "The item is not found in the list\n";
    }

    marks.display();


    cout << "\n Now For Names\n";

    LinkedList<string> names;

    names.addLast("shams");
    names.addLast("Ali");
    names.addLast("Fareed");
    names.addLast("Mailad");
    names.display();
    names.deleteFirst();
    names.display();


    return 0;
}