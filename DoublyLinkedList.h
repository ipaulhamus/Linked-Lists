#ifndef LINKEDLISTS_DOUBLYLINKEDLIST_H
#define LINKEDLISTS_DOUBLYLINKEDLIST_H

#include "LinkedListBase.h"

template<typename T>
class DoublyLinkedList : public LinkedListBase<T>
{
    class Node
    {
    public:
        T value;
        Node* next;
        Node* previous;

        Node(T value)
        {
            this->value = value;
        }
    };

private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList();

    DoublyLinkedList(T value);

    ~DoublyLinkedList() override;

    T& operator[](size_t index) const override;

    void insert(T value) override;

    void insert(T value, size_t index) override;

    void remove(T value) override;

    void removeAt(size_t index) override;

    size_t search(T value) override;

    void clear() override;
};


#endif //LINKEDLISTS_DOUBLYLINKEDLIST_H

template class DoublyLinkedList<int>;