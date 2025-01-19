#include "LinkedListBase.h"

template <typename T>
std::string LinkedListBase<T>::toString() const
{
std::string str = "";

    for(size_t i = 0; i < this->listCount; i++)
    {
        str += std::to_string(this->operator[](i));
        str += ", ";
    }

    return str;
}

template class LinkedListBase<int>;