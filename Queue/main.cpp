#include <iostream>

using namespace std;

template <class T> class Queue {

    int front, rear, size;

    T* queue;

public:
    Queue(int size) :front(0), rear(0), size(size + 1), queue(new T[size + 1]) { };

    bool empty();
    bool full();
    void insert(const T& val);
    T extract();
};

template <class T> bool Queue<T>::empty() {
    return front == rear;
}

template <class T> bool Queue<T>::full() {
    return (rear + 1) % size == front;
}


template <class T> void Queue<T>::insert(const T& val) {
    if (full()) {
        cout << "full\n";
        return;
    }
    rear = rear + 1 % size;
    queue[rear] = val;
}
template <class T> T Queue<T>::extract() {
    if (empty()) {
        return 0;
    }
    front = front + 1 % size;
    return queue[front];
}
int main() {
    Queue<int> q(3);
    q.insert(1);
    q.insert(2);
    q.insert(3);
    q.insert(4);

    for (int i = 1; i <= 3; i++)
    {
        cout << q.extract() << "\n";
    }



}

