#include <stdexcept>

#include "SinglyLinkedList.h"

#include <set>

#include "DoublyLinkedList.h"

using namespace std;

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList()
{
    this->head = nullptr;
}

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(T value)
{
    this->head = new Node(value);
    this->listCount = 1;
}

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    //delete this->head;

    Node* current = this->head;

    for(size_t i = 0; i < this->listCount; ++i)
    {
        Node* temp = current->next;
        delete current;
        current = temp;
    }
}

template <typename T>
T& SinglyLinkedList<T>::operator[](size_t index) const
{
    if(index >= this->listCount || index < 0)
    {
        throw std::range_error("index out of range");
    }

    Node* current = this->head;

    for(size_t i = 0; i < index; i++)
    {
        current = current->next;
    }

    return current->value;
}

template<typename T>
void SinglyLinkedList<T>::insert(T value)
{
    insert(value, this->listCount);
}

template<typename T>
void SinglyLinkedList<T>::insert(T value, size_t index)
{
    if(index == std::string::npos || index > this->listCount)
    {
        throw std::range_error("index out of range");
    }

    Node* newNode = new Node(value);

    if(this->head == nullptr)
    {
        this->head = newNode;
    }
    else if(index == 0)
    {
        newNode->next = this->head;
        this->head = newNode;
    }
    else
    {
        Node* current = this->head;
        for(size_t i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    ++this->listCount;
}

template <typename T>
void SinglyLinkedList<T>::remove(T value)
{
    Node* current = this->head;
    Node* previous = nullptr;

    for(size_t i = 0; i < this->listCount; i++)
    {
        if(current->value == value)
        {
            if(previous == nullptr)
            {
                this->head = this->head->next;
            }
            else
            {
                previous->next = current->next;
            }

            --this->listCount;
            return;
        }

        previous = current;
        current = current->next;
    }
}

template <typename T>
void SinglyLinkedList<T>::removeAt(size_t index)
{
    if(index == std::string::npos || index >= this->listCount)
    {
        throw std::range_error("index out of range");
    }

    if(index == 0)
    {
        this->head = this->head->next;
    }
    else
    {
        Node* current = this->head;

        for(size_t i = 0; i < index - 1; i++)
        {
            current = current->next;
        }

        current->next = current->next->next;
    }

    --this->listCount;
}

template <typename T>
size_t SinglyLinkedList<T>::search(T value)
{
    Node* current = this->head;

    for(size_t i = 0; i < this->listCount; i++)
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
void SinglyLinkedList<T>::clear()
{
    this->head = nullptr;
    this->listCount = 0;
}


template class SinglyLinkedList<int>;