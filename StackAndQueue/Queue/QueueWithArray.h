#include <stdexcept>
#include <iostream>

using namespace std;

template <class T> class QueueWithArray {
private:
    T* arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    QueueWithArray(int size = 10);

    void insert(const T& x);
    T extract();
    T peek();
    bool isEmpty();
    bool isFull();
    void menu();
};


template <class T> QueueWithArray<T>::QueueWithArray(int size) : capacity(size), front(0), rear(-1), count(0) {
    arr = new T[capacity];
}


template <class T> void QueueWithArray<T>::insert(const T& x) {
    if (isFull()) {
        throw overflow_error("Queue is full");
    }
    rear = (rear + 1) % capacity;
    arr[rear] = x;
    count++;
}

template <class T> T QueueWithArray<T>::extract() {
    if (isEmpty()) {
        throw underflow_error("Queue is empty");
    }
    T x = arr[front];
    front = (front + 1) % capacity;
    count--;
    return x;
}

template <class T> T QueueWithArray<T>::peek() {
    if (isEmpty()) {
        throw underflow_error("Queue is empty");
    }
    return arr[front];
}

template <class T> bool QueueWithArray<T>::isEmpty() {
    return count == 0;
}

template <class T> bool QueueWithArray<T>::isFull() {
    return count == capacity;
}



template <class T> void QueueWithArray<T>::menu() {
    int choice;
    do {
        cout << "===========================================\n";
        cout << "|            QUEUE ARRAY MENU             |\n";
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
            try {
                insert(value);
                cout << "===========================================\n";
                cout << "| " << value << " INSERTED INTO QUEUE                 |\n";
                cout << "===========================================\n";
            }
            catch (const overflow_error& e) {
                cout << "===========================================\n";
                cout << "| ERROR: " << e.what() << " |\n";
                cout << "===========================================\n";
            }
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
                cout << "| ERROR: " << e.what() << " |\n";
                cout << "===========================================\n";
            }
            break;
        case 3:
            try {
                T frontElement = peek();
                cout << "===========================================\n";
                cout << "| FRONT ELEMENT IS: " << frontElement << "                 |\n";
                cout << "===========================================\n";
            }
            catch (const underflow_error& e) {
                cout << "===========================================\n";
                cout << "| ERROR: " << e.what() << " |\n";
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