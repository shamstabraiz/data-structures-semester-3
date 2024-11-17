#include <iostream>
#include <string>
#include "Stack/StackWithLinkedList.h"
#include <stdexcept>

using namespace std;

inline int precedence(char symbol) {
    switch (symbol) {
    case '+': case '-': return 1;
    case '*': case '/': case '%': return 2;
    case '^': return 3;
    default: return 0;
    }
}
inline bool isOperator(char symbol) {
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^' || symbol == '%';
}

inline string getSymbolType(char symbol) {
    if (isOperator(symbol)) return "Operator";
    if (symbol == '(' || symbol == ')') return "Parenthesis";
    return "Operand";
}
string infixToPostfix(const string& infix) {
    StackWithLinkedList<char> stack;
    string postfix;
    cout << "\nSymbol\t\tStack\t\tPostfix\n";
    cout << "-----------------------------------------------------------\n";
    for (char symbol : infix) {
        cout << symbol << "\t\t";

        if (symbol == '(') {
            stack.push(symbol);
        }
        else if (symbol == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix += stack.pop();
            }
            stack.pop(); // Remove '('
        }
        else if (isOperator(symbol)) {
            while (!stack.isEmpty() && precedence(symbol) <= precedence(stack.peek())) {
                postfix += stack.pop();
            }
            stack.push(symbol);
        }
        else {
            postfix += symbol;
        }

        stack.print();
        cout << "\t\t" << postfix << '\n';
    }

    while (!stack.isEmpty()) {
        postfix += stack.pop();
    }
    cout << "-----------------------------------------------------------\n";

    return postfix;
}

int main() {
    cout << "╔════════════════════════════════════════════════╗\n";
    cout << "║     Welcome to the Infix to Postfix Converter  ║\n";
    cout << "║            Powered by Stack Data Structure     ║\n";
    cout << "╚════════════════════════════════════════════════╝\n\n";

    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    try {

        string postfix = infixToPostfix(infix);
        cout << "Postfix Expression: " << postfix << '\n';
        cout << "\nThank you for using the converter!\n";
    }
    catch (const underflow_error& e) {
        cout << e.what() << endl;
    }


    return 0;
}