#include <stdexcept>

#include "DoublyLinkedList.h"

using namespace std;

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
}

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(T value)
{
    this->head = new Node(value);
    this->tail = this->head;
    this->listCount = 1;
}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    delete this->head;
    delete this->tail;
    this->listCount = 1;
}

template <typename T>
T& DoublyLinkedList<T>::operator[](size_t index) const
{
    if(index < 0 || index >= this->listCount)
    {
        throw out_of_range("index out of range");
    }

    Node* current = nullptr;

    if(index < this->listCount / 2)
    {
        current = this->head;
        for(size_t i = 0; i < index; ++i)
        {
            current = current->next;
        }
    }
    else
    {
        current = this->tail;
        for(int i = this->listCount - 1; i > index; --i)
        {
            current = current->previous;
        }
    }

    return current->value;
}

template <typename T>
void DoublyLinkedList<T>::insert(T value)
{
    insert(value, this->listCount);
}

template <typename T>
void DoublyLinkedList<T>::insert(T value, size_t index)
{
    if(index == std::string::npos || index > this->listCount)
    {
        throw out_of_range("index out of range");
    }

    Node* newNode = new Node(value);

    if(this->head == nullptr)
    {
        this->head = newNode;
        this->tail = newNode;
    }
    else if(index == 0)
    {
        newNode->next = this->head;
        newNode->previous = nullptr;
        newNode->previous = newNode;
        this->head->previous = newNode;
        this->head = newNode;
    }
    else if (index == this->listCount)
    {
        this->tail->next = newNode;
        newNode->previous = this->tail;
        this->tail = newNode;
    }
    else
    {
        Node* current = nullptr;

        if(index < this->listCount / 2)
        {
            current = this->head;
            for(size_t i = 0; i < index; ++i)
            {
                current = current->next;
            }
        }
        else
        {
            current = this->tail;
            for(int i = this->listCount - 1; i > index - 1; --i)
            {
                current = current->previous;
            }
        }

        newNode->next = current->next;
        newNode->previous = current;
        current->next->previous = newNode;
        current->next = newNode;
    }

    ++this->listCount;
}

template <typename T>
void DoublyLinkedList<T>::remove(T value)
{
    Node* current = this->head;
    
    while(current != nullptr && current->value != value)
    {
        current = current->next;
    }

    if(current != nullptr)
    {
        if(current == this->head)
        {
            this->head = this->head->next;
            this->head->previous = nullptr;
        }
        else if(current == this->tail)
        {
            this->tail = this->tail->previous;
            this->tail->next = nullptr;
        }
        else
        {
            current->previous->next = current;
            current->next->previous = current->previous;
        }

        --this->listCount;
    }
}

template <typename T>
void DoublyLinkedList<T>::removeAt(size_t index)
{
    if(index == std::string::npos || index >= this->listCount)
    {
        throw out_of_range("index out of range");
    }

    if(index == 0)
    {
        this->head = this->head->next;
        this->head->previous = nullptr;
    }
    else if(index == this->listCount - 1)
    {
        this->tail = this->tail->previous;
        this->tail->next = nullptr;
    }
    else
    {
        Node* current = nullptr;

        if(index < this->listCount / 2)
        {
            current = this->head;

            for(size_t i = 0; i < index; ++i)
            {
                current = current->next;
            }
        }
        else
        {
            current = this->tail;
            for(int i = this->listCount - 1; i > index; --i)
            {
                current = current->previous;
            }
        }

        current->next = current->next->next;
        current->next->previous = current;
    }

    --this->listCount;
}

template <typename T>
size_t DoublyLinkedList<T>::search(T value)
{
    Node* current = this->head;

    for(size_t i = 0; i < this->listCount; ++i)
    {
        if(current->value == value)
        {
            return i;
        }

        current = current->next;
    }

    return std::string::npos;
}

template <typename T>
void DoublyLinkedList<T>::clear()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->listCount = 0;
}