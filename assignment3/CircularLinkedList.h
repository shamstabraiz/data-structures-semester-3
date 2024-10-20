#include <iostream>
#include "ListErrors.h"

using namespace std;


template <class T> class CircularLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val, Node* nextlink = 0) :data(val), next(nextlink) { }
    };
    Node* head;
    Node* tail;
public:
    CircularLinkedList() :head(0), tail(0) { }
    bool empty() const { return head == 0 && tail == 0; }
    void addFirst(const T& val);
    void deleteFirst();
    void deleteItem(const T& val);
    void addLast(const T& val);
    void display();
    void reverse();
    void printMenu();
    void useCirculatLinkList();
    T getInputFromUser();
};

template <class T> void CircularLinkedList<T>::addFirst(const T& val) {
    Node* n = new Node(val);
    if (head == 0 && tail == 0) {
        tail = n;
        tail->next = n;
    }
    else {
        n->next = head;
        tail->next = n;
    }
    head = n;
}

template <class T> void CircularLinkedList<T>::addLast(const T& val) {
    if (head == 0) { return addFirst(val); }
    Node* m = head;
    while (m != tail) {
        m = m->next;
    }
    Node* n = new Node(val);
    m->next = n;
    n->next = head;
    tail = n;
}


template <class T> void CircularLinkedList<T>::display() {
    if (empty()) {
        cout << "===========================================\n";
        cout << "| The List is Empty                        |\n";
        cout << "===========================================\n\n";
        return;
    }

    cout << "===========================================\n";
    cout << "| Linked List Elements:                    |\n";
    cout << "===========================================\n";
    cout << "[";
    Node* n;
    for (n = head; n != tail; n = n->next) {
        cout << n->data;
        if (n != tail) {
            cout << " , ";
        }
    }
    cout << n->data << "]\n";
    cout << "===========================================\n\n";
}

template <class T> void CircularLinkedList<T>::deleteFirst() {
    if (head == 0) { throw ListEmptyExeption(); return; }
    Node* n = head;
    T val = n->data;
    head = n->next;
    delete n;
    if (head != 0) {
        tail->next = head;
    }
    else {
        tail = 0;
    }

}

template <class T> void CircularLinkedList<T>::deleteItem(const T& val) {
    if (head == 0) throw ListEmptyExeption();
    if (head->data == val) {
        deleteFirst();
        return;
    }

    Node* p, * n = head;
    while (n != tail && n->data != val) {
        p = n;
        n = n->next;
    }

    if (n->data != val) {
        throw ListItemNotFoundExecption();
        return;
    }
    p->next = n->next;
    if (n == tail)
        tail = p;

    delete n;
    return;
}

template <class T> void CircularLinkedList<T>::reverse() {
    if (head == 0 || head->next == 0) {
        throw ListEmptyExeption();
        return;
    }
    Node* first = head;
    Node* p, * q = head, * r = head->next;

    head->next = 0;

    while (r != head) {
        p = q;
        q = r;
        if (r != head) {
            r = r->next;
            q->next = p;
        }
    }
    head = q;
    first->next = head;
    tail = first;
}

template <class T> void CircularLinkedList<T>::printMenu() {
    cout << "======================================\n";
    cout << "|      CIRCULAR LINKED LIST MENU       |\n";
    cout << "======================================\n";
    cout << "|  1 | Add First to Circular Linked List|\n";
    cout << "|  2 | Add Last to Circular Linked List |\n";
    cout << "|  3 | Delete First Element             |\n";
    cout << "|  4 | Delete Given Element             |\n";
    cout << "|  5 | Reverse Circular Linked List     |\n";
    cout << "|  6 | Display Circular Linked List     |\n";
    cout << "|  7 | Return To Main Menu              |\n";
    cout << "======================================\n";
}

template <class T> void CircularLinkedList<T>::useCirculatLinkList() {
    int choice;
    do {
        printMenu();
        cout << "===========================================\n";
        cout << "| Please Select an Item From the Menu Above |\n";
        cout << "===========================================\n";
        cout << "Your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1:
            addFirst(getInputFromUser());
            cout << "===========================================\n";
            cout << "| Element Has Been Added to the List       |\n";
            cout << "===========================================\n\n";
            break;

        case 2:
            addLast(getInputFromUser());
            cout << "===========================================\n";
            cout << "| Element Has Been Added to the List       |\n";
            cout << "===========================================\n\n";
            break;

        case 3:
            try {
                deleteFirst();
                cout << "===========================================\n";
                cout << "| Element Has Been Deleted                 |\n";
                cout << "===========================================\n\n";
            }
            catch (ListEmptyExeption& e) {
                cout << "===========================================\n";
                cout << "| Error: The List is Empty                 |\n";
                cout << "===========================================\n\n";
            }
            break;

        case 4:
            try {
                deleteItem(getInputFromUser());
                cout << "===========================================\n";
                cout << "| Element Has Been Deleted                 |\n";
                cout << "===========================================\n\n";
            }
            catch (ListEmptyExeption& e) {
                cout << "===========================================\n";
                cout << "| Error: The List is Empty                 |\n";
                cout << "===========================================\n\n";
            }
            catch (ListItemNotFoundExecption& e) {
                cout << "===========================================\n";
                cout << "| Error: The Element Was Not Found         |\n";
                cout << "===========================================\n\n";
            }
            break;

        case 5:
            reverse();
            cout << "===========================================\n";
            cout << "| The List Has Been Reversed               |\n";
            cout << "===========================================\n\n";
            break;

        case 6:
            display();
            break;

        case 7:
            cout << "===========================================\n";
            cout << "| Exiting the Program...                   |\n";
            cout << "===========================================\n\n";
            return;

        default:
            cout << "===========================================\n";
            cout << "| Please select a valid item from the menu |\n";
            cout << "===========================================\n\n";
            break;
        }
    } while (choice != 7);
}

template <class T> T CircularLinkedList<T>::getInputFromUser() {
    T input;
    cout << "===========================================\n";
    cout << "| Please Enter Your Input:                 |\n";
    cout << "===========================================\n";
    cout << "Your input: ";
    cin >> input;
    cout << "===========================================\n\n";
    return input;
}