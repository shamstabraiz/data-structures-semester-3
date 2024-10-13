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
    void reverse();

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


void printMenu() {
    cout << "1: Add First to Linked List\n";
    cout << "2: Add Last to Linked List\n";
    cout << "3: Delete First Element From List\n";
    cout << "4: Delete Given Element From List\n";
    cout << "5: Reverse Linked List\n";
    cout << "6: Display Linked List\n";
    cout << "7: Exit the Program\n";
}

int getInputFromUser() {
    int input;
    cout << "Please Enter Your Input: ";
    cin >> input;
    cout << endl;
    return input;
}

int main() {
    LinkedList<int> userData;
    int choice;
    do {
        printMenu();
        cout << "Please Select an Item From the Menu Above: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            userData.addFirst(getInputFromUser());
            cout << "Elemnt Have Been Added To The List\n\n";
            break;
        case 2:
            userData.addLast(getInputFromUser());
            cout << "Elemnt Have Been Added To The List\n\n";
            break;
        case 3:
            try {
                userData.deleteFirst();
                cout << "Element Has been Deleted\n\n";

            }
            catch (ListEmptyExeption& e) {
                cout << "The List is Empty\n\n";
            }
            break;
        case 4:
            try {
                userData.deleteItem(getInputFromUser());
                cout << "Element Has been Deleted\n\n";

            }
            catch (ListEmptyExeption& e) {
                cout << "The List is Empty\n\n";
            }
            catch (ListItemNotFoundExecption& e) {
                cout << "The Element Was Not Found In the List\n\n";
            }
            break;
        case 5:
            userData.reverse();
            cout << "The List Has Been Reversed\n\n";
            break;
        case 6:
            userData.display();
            break;
        case 7:
            cout << "Exiting program.\n\n";
            break;
        default:
            cout << "Please select a valid item from the menu.\n\n";
            break;
        }
    } while (choice != 7);
    return 0;
}