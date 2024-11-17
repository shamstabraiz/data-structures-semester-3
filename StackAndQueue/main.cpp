#include <iostream>
#include "Stack/StackWithArray.h"
#include "Stack/StackWithLinkedList.h"
#include "Queue/QueueWithArray.h"
#include "Queue/QueueWithLinkedList.h"

using namespace std;

void displayMenu() {
    cout << "===============================\n";
    cout << "|     STACK AND QUEUE MENU     |\n";
    cout << "===============================\n";
    cout << "|  1 | Stack Using Array       |\n";
    cout << "|  2 | Queue Using Array       |\n";
    cout << "|  3 | Stack Using Linked List |\n";
    cout << "|  4 | Queue Using Linked List |\n";
    cout << "|  5 | Exit                    |\n";
    cout << "===============================\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    int size;

    cout << "===============================\n";
    cout << "|   ENTER SIZE                |\n";
    cout << "===============================\n";
    cout << "Size: ";
    cin >> size;

    StackWithArray<int> stack(size);
    QueueWithArray<int> queue(size);

    StackWithLinkedList<int> stackLink;
    QueueWithLinkedList<int> queueLink;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            stack.menu();
            break;
        case 2:
            queue.menu();
            break;
        case 3:
            stackLink.menu();
            break;
        case 4:
            queueLink.menu();
            break;
        case 5:
            cout << "===============================\n";
            cout << "|       EXITING PROGRAM        |\n";
            cout << "===============================\n";
            break;
        default:
            cout << "===============================\n";
            cout << "|     INVALID OPTION. TRY AGAIN|\n";
            cout << "===============================\n";
        }
    } while (choice != 5);

    return 0;
}
