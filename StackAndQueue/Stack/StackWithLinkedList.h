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
    void menu();
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
    cout << x << " pushed onto the stack.\n";
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

template <class T> void StackWithLinkedList<T>::menu() {
    int choice;
    do {
        cout << "===========================================\n";
        cout << "|     STACK LINKED LIST OPERATIONS        |\n";
        cout << "===========================================\n";
        cout << "|  1 | Push                               |\n";
        cout << "|  2 | Pop                                |\n";
        cout << "|  3 | Peek                               |\n";
        cout << "|  4 | Exit to Main Menu                  |\n";
        cout << "===========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            T value;
            cout << "===========================================\n";
            cout << "|          ENTER VALUE TO PUSH            |\n";
            cout << "===========================================\n";
            cout << "Value: ";
            cin >> value;
            push(value);
            break;
        }
        case 2:
            try {
                T popped = pop();
                cout << "===========================================\n";
                cout << "| " << popped << " POPPED FROM STACK               |\n";
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
                T topElement = peek();
                cout << "===========================================\n";
                cout << "| TOP ELEMENT IS: " << topElement << "                  |\n";
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
            cout << "| INVALID OPTION. TRY AGAIN.              |\n";
            cout << "===========================================\n";
        }
    } while (choice != 4);
}