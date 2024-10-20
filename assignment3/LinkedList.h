#include <iostream>
#include "ListErrors.h"

using namespace std;


template <class T> class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T val, Node* link = 0) :data(val), next(link) { }
    };
    Node* head;
public:
    LinkedList() :head(0) { }
    bool empty() const { return head == 0; }
    void addFirst(const T& val);
    void deleteFirst();
    void deleteItem(const T& val);
    void addLast(const T& val);
    void display();
    void reverse();
    void printMenu();
    void useLinkList();
    T getInputFromUser();
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
    if (head == 0) {
        cout << "===========================================\n";
        cout << "| The List is Empty                        |\n";
        cout << "===========================================\n\n";
        return;
    }

    cout << "===========================================\n";
    cout << "| Linked List Elements:                    |\n";
    cout << "===========================================\n";
    cout << "[";

    for (Node* n = head; n != 0; n = n->next) {
        cout << n->data;
        if (n->next != 0) {
            cout << " , ";
        }
    }

    cout << "]\n";
    cout << "===========================================\n\n";
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

template <class T> void LinkedList<T>::reverse() {
    if (head == 0 || head->next == 0) {
        throw ListEmptyExeption();
        return;
    }
    Node* p, * q = head, * r = head->next;

    head->next = 0;

    while (r != 0) {
        p = q;
        q = r;
        if (r != 0) {
            r = r->next;
            q->next = p;
        }
    }
    head = q;
}

template <class T> void LinkedList<T>::printMenu() {
    cout << "===============================\n";
    cout << "|       LINKED LIST MENU       |\n";
    cout << "===============================\n";
    cout << "|  1 | Add First to Linked List|\n";
    cout << "|  2 | Add Last to Linked List |\n";
    cout << "|  3 | Delete First Element    |\n";
    cout << "|  4 | Delete Given Element    |\n";
    cout << "|  5 | Reverse Linked List     |\n";
    cout << "|  6 | Display Linked List     |\n";
    cout << "|  7 | Return To Main Menu     |\n";
    cout << "=============================\n";
}

template <class T> void LinkedList<T>::useLinkList() {
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

template <class T> T LinkedList<T>::getInputFromUser() {
    T input;
    cout << "===========================================\n";
    cout << "| Please Enter Your Input:                 |\n";
    cout << "===========================================\n";
    cout << "Your input: ";
    cin >> input;
    cout << "===========================================\n\n";
    return input;
}