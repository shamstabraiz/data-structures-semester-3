#include <iostream>

using namespace std;

template <class T> class Stack {

    int top;
    int size;
    T* stack;
public:
    Stack(int size) :top(-1), size(size), stack(new T[size]) { };
    bool empty();
    bool full();
    void push(const T& val);
    void pop();
    void display();
};

template <class T> bool Stack<T>::full() {
    return size - 1 == top;
};

template <class T> bool Stack<T>::empty() {
    return top == -1;
};



template <class T> void Stack<T>::push(const T& val) {
    if (full())return;
    top++;
    stack[top] = val;
};

template <class T> void Stack<T>::pop() {
    if (empty())return;
    top--;
};

template <class T> void Stack<T>::display() {
    cout << "[";
    for (int i = 0; i <= top; i++) {
        cout << stack[i] << " ";
    }
    cout << "]\n";
};

template <class T> class StackLinkList {

private:
    struct Node
    {
        T data;
        Node* next;
        Node(T val, Node* link = 0) :data(val), next(link) { }
    };

    Node* top;
public:
    StackLinkList() :top(0) { };
    bool empty();
    void push(const T& val);
    void pop();
    void display();
};

template <class T> bool StackLinkList<T>::empty() {
    return top == 0;
};



template <class T> void StackLinkList<T>::push(const T& val) {
    Node* n = new Node(val);
    n->next = top;
    top = n;
};

template <class T> void StackLinkList<T>::pop() {
    if (empty())return;
    Node* n = top;
    top = top->next;
    delete n;
};

template <class T> void StackLinkList<T>::display() {
    cout << "[";
    for (Node* i = top; i != 0; i = i->next) {
        cout << i->data << " ";
    }
    cout << "]\n";
};
int main() {
    Stack<int> s(10);
    StackLinkList<int> slink;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.display();
    s.pop();
    s.display();

    slink.push(1);
    slink.push(2);
    slink.push(3);
    slink.push(4);
    slink.display();
    slink.pop();
    slink.display();

}