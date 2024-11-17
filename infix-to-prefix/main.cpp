#include <iostream>
#include <string>

using namespace std;

class Error {
public:
    const char* what() const {
        return "Stack is empty!";
    }
};

template <class T>
class Stack {
    struct Node {
        Node* next;
        T data;
        Node(const T& val, Node* link = nullptr) : data(val), next(link) { }
    };
    Node* top;
public:
    Stack() : top(nullptr) { }
    bool empty();
    void push(const T& val);
    T pop();
    T peep();
    void print();
};

template <class T>
bool Stack<T>::empty() {
    return top == nullptr;
}

template <class T>
void Stack<T>::print() {
    Node* n = top;
    while (n != 0) {
        cout << n->data;
        n = n->next;
    }
}

template <class T>
void Stack<T>::push(const T& val) {
    Node* n = new Node(val);
    n->next = top;
    top = n;
}

template <class T>
T Stack<T>::pop() {
    if (empty()) throw Error();
    Node* n = top;
    T val = n->data;
    top = top->next;
    delete n;
    return val;
}

template <class T>
T Stack<T>::peep() {
    if (empty()) throw Error();
    return top->data;
}

inline int precedence(char symbol) {
    switch (symbol) {
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    case '^': return 3;
    default: return 0;
    }
}

inline bool isOperator(char symbol) {
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^';
}

string infixToPostfix(const string& infix) {
    Stack<char> stack;
    string postfix;
    for (char symbol : infix) {
        if (symbol == '(') {
            stack.push(symbol);
        }
        else if (symbol == ')') {
            while (!stack.empty() && stack.peep() != '(') {
                postfix += stack.pop();
            }
            stack.pop(); // Remove '('
        }
        else if (isOperator(symbol)) {
            while (!stack.empty() && precedence(symbol) <= precedence(stack.peep())) {
                postfix += stack.pop();
            }
            stack.push(symbol);
        }
        else {
            postfix += symbol;
        }
        cout << symbol << "\t\t";
        stack.print();
        cout << "\t\t" << postfix << '\n';
    }

    while (!stack.empty()) {
        postfix += stack.pop();
    }
    return postfix;
}

int main() {
    string infix = "a*(b+(c-d)*e)";
    try {
        string postfix = infixToPostfix(infix);
        cout << "Postfix: " << postfix << '\n';
    }
    catch (const Error& e) {
        cout << e.what() << endl;
    }
    return 0;
}
