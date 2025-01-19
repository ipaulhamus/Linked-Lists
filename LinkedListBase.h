#ifndef LINKEDLISTS_LINKEDLISTBASE_H
#define LINKEDLISTS_LINKEDLISTBASE_H

#include <string>

template<typename T>
class LinkedListBase
{
protected:

    size_t listCount = 0;

    LinkedListBase()
    {
        listCount = 0;
    }

public:

    virtual ~LinkedListBase() = default;

    virtual T& operator[](size_t index) const = 0;

    bool isEmpty = false;

    virtual void insert(T value) = 0;
    virtual void insert(T value, size_t index) = 0;
    virtual void remove(T value) = 0;
    virtual void removeAt(size_t index) = 0;
    virtual size_t search(T value) = 0;
    virtual void clear() = 0;

    size_t getCount() const;
    std::string toString() const;
};


#endif //LINKEDLISTS_LINKEDLISTBASE_H
