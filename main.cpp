#include <iostream>

#include "LinkedListBase.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"

template<typename T>
void testLinkedList(LinkedListBase<T>* linkedList);

int main()
{
    std::cout << "==== Singly Linked List ====" << std::endl;
    LinkedListBase<int>* linkedList = new SinglyLinkedList<int>();
    testLinkedList(linkedList);
    delete linkedList;

    std::cout << "\n==== Doubly Linked List ====" << std::endl;

    LinkedListBase<int>* linkedList2 = new DoublyLinkedList<int>();
    testLinkedList(linkedList2);
    delete linkedList2;
}

template<typename T>
void testLinkedList(LinkedListBase<T>* linkedList)
{
    linkedList->insert(30);
    linkedList->insert(22);
    linkedList->insert(11);
    linkedList->insert(4);
    linkedList->insert(90);

    std::cout << "List after inserts: " << std::endl;
    std::cout << linkedList->toString() << std::endl;

    linkedList->remove(11);

    std::cout << "List after removing value '11':" << std::endl;
    std::cout << linkedList->toString() << std::endl;

    linkedList->insert(52, 3);

    std::cout << "List after adding '52' at index '3':" << std::endl;
    std::cout << linkedList->toString() << std::endl;

    std::cout << "Searching for '22':" << std::endl;
    std::cout << linkedList->search(22) << std::endl;

    linkedList->clear();

    std::cout << "List after clearing: " << std::endl;
    std::cout << linkedList->toString() << std::endl;
}


