#include <iostream>
#include "DoublyLinkedList.h"
#include "LinkedList.h"



int main() {
    DoublyLinkedList<int> l;
    l.addFirst(2);
    l.addFirst(1);
    l.addLast(3);
    l.addLast(4);
    l.display();
    // l.reverse();
    l.del(4);
    l.display();


}