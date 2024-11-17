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
    void menu();
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

    cout << x << " inserted into the queue.\n";
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

template <class T> void QueueWithLinkedList<T>::menu() {
    int choice;
    do {
        cout << "===========================================\n";
        cout << "|        QUEUE LINKED LIST MENU           |\n";
        cout << "===========================================\n";
        cout << "|  1 | Insert into Queue                  |\n";
        cout << "|  2 | Extract from Queue                 |\n";
        cout << "|  3 | Peek at Front Element              |\n";
        cout << "|  4 | Exit to Main Menu                  |\n";
        cout << "===========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            T value;
            cout << "===========================================\n";
            cout << "|          ENTER VALUE TO INSERT          |\n";
            cout << "===========================================\n";
            cout << "Value: ";
            cin >> value;
            insert(value);
            cout << "===========================================\n";
            cout << "| " << value << " INSERTED INTO QUEUE                |\n";
            cout << "===========================================\n";
            break;
        }
        case 2:
            try {
                T extracted = extract();
                cout << "===========================================\n";
                cout << "| " << extracted << " EXTRACTED FROM QUEUE              |\n";
                cout << "===========================================\n";
            }
            catch (const underflow_error& e) {
                cout << "===========================================\n";
                cout << "| " << e.what() << "                          |\n";
                cout << "===========================================\n";
            }
            break;
        case 3:
            try {
                T frontElement = peek();
                cout << "===========================================\n";
                cout << "| FRONT ELEMENT IS: " << frontElement << " |\n";
                cout << "===========================================\n";
            }
            catch (const underflow_error& e) {
                cout << "===========================================\n";
                cout << "| " << e.what() << "                          |\n";
                cout << "===========================================\n";
            }
            break;
        case 4:
            cout << "===========================================\n";
            cout << "| RETURNING TO MAIN MENU                  |\n";
            cout << "===========================================\n";
            break;
        default:
            cout << "===========================================\n";
            cout << "| INVALID OPTION. PLEASE TRY AGAIN.       |\n";
            cout << "===========================================\n";
        }
    } while (choice != 4);
}