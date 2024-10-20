#include <iostream>
#include "LinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularLinkedList.h"
#include "ListErrors.h"

using namespace std;


void printMainMenu() {
    cout << "========================================\n";
    cout << "|       Wellcome To List Programe       |\n";
    cout << "========================================\n";
    cout << "|  1 | Single Linked List               |\n";
    cout << "|  2 | Doubly Linked List               |\n";
    cout << "|  3 | Circular Linked List             |\n";
    cout << "|  4 | Exit Programe                    |\n";
    cout << "========================================\n";
}
int getListChoiceFromUser() {
    printMainMenu();
    int a;
    cout << "===========================================\n";
    cout << "| Please Select an Item From the Menu Above |\n";
    cout << "===========================================\n";
    cout << "Your choice: ";
    cin >> a;
    cout << "===========================================\n\n";
    return a;
}


int main() {
    LinkedList<int> LINKEDLIST;
    DoublyLinkedList<int> DoublyList;
    CircularLinkedList<int> CirculatList;

    int ListChoice = getListChoiceFromUser();
    char temp;
    do {
        switch (ListChoice) {
        case 1:
            LINKEDLIST.useLinkList();
            ListChoice = getListChoiceFromUser();
            break;
        case 2:
            DoublyList.useLinkDoublyList();
            ListChoice = getListChoiceFromUser();
            break;
        case 3:
            CirculatList.useCirculatLinkList();
            ListChoice = getListChoiceFromUser();
            break;
        case 4:
            cout << "===========================================\n";
            cout << "| Exiting the Program...                  |\n";
            cout << "===========================================\n";
            exit(0);
            break;
        default:
            cout << "===========================================\n";
            cout << "| Please select a valid item from the menu |\n";
            cout << "===========================================\n";
            ListChoice = getListChoiceFromUser();
            break;
        }
    } while (ListChoice != 4);



    return 0;
}