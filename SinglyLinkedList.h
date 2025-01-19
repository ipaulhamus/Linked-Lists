#ifndef LINKEDLISTS_SINGLYLINKEDLIST_H
#define LINKEDLISTS_SINGLYLINKEDLIST_H

#include "LinkedListBase.h"

template <typename T>
class SinglyLinkedList :  public LinkedListBase<T>
{
    class Node
    {
    public:
        T value;
        Node* next;

        Node(T value)
        {
            this->value = value;
            this->next = nullptr;
        }
    };

private:
    Node* head;

public:
    SinglyLinkedList();

    SinglyLinkedList(T value);

    ~SinglyLinkedList() override;

    T& operator[](size_t index) const override;

    void insert(T value) override;

    void insert(T value, size_t index) override;

    void remove(T value) override;

    void removeAt(size_t index) override;

    size_t search(T value) override;

    void clear() override;
};


#endif //LINKEDLISTS_SINGLYLINKEDLIST_H
