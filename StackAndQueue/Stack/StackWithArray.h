#include <stdexcept>
#include <iostream>


using namespace std;
template <class T> class StackWithArray {
private:
    T* arr;
    int top;
    int capacity;

public:
    StackWithArray(int size = 10);

    void push(const T& x);
    T pop();
    T peek();
    bool isEmpty();
    bool isFull();
    void menu();
};


template <class T> StackWithArray<T>::StackWithArray(int size) : capacity(size), top(-1) {
    arr = new T[capacity];
}



template <class T> void StackWithArray<T>::push(const T& x) {
    if (isFull()) {
        throw overflow_error("Stack is full");
    }
    arr[++top] = x;
}

template <class T> T StackWithArray<T>::pop() {
    if (isEmpty()) {
        throw underflow_error("Stack is empty");
    }
    return arr[top--];
}

template <class T> T StackWithArray<T>::peek() {
    if (isEmpty()) {
        throw underflow_error("Stack is empty");
    }
    return arr[top];
}

template <class T> bool StackWithArray<T>::isEmpty() {
    return top == -1;
}

template <class T> bool StackWithArray<T>::isFull() {
    return top == capacity - 1;
}
template <class T> void StackWithArray<T>::menu() {
    int choice;
    do {
        cout << "===========================================\n";
        cout << "|         STACK ARRAY OPERATIONS          |\n";
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
            try {
                push(value);
                cout << "===========================================\n";
                cout << "| " << value << " PUSHED TO STACK                     |\n";
                cout << "===========================================\n";
            }
            catch (const overflow_error& e) {
                cout << "===========================================\n";
                cout << "| " << e.what() << "                          |\n";
                cout << "===========================================\n";
            }
            break;
        }
        case 2:
            try {
                T popped = pop();
                cout << "===========================================\n";
                cout << "| " << popped << " POPPED FROM STACK                   |\n";
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