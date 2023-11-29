#pragma once
#include "Deque.h"

template <typename Type>
inline Dequeue<Type>::Dequeue(const int capacity)
    : start_index(-1),
    end_index(0),
    capacity(capacity),
    elements(new Type[capacity]) {
};

template <typename Type>
Dequeue<Type>::Dequeue(std::initializer_list<int>& list) noexcept
    :Dequeue()
{
    for (auto& element : list) {
        this->offerFront(element);
    }
};

template <typename Type>
Dequeue<Type>::~Dequeue()
{
    delete[]elements;
};

template <typename Type>
Dequeue<Type>::Dequeue(const Dequeue& dequeue) noexcept
    : start_index(-1),
    end_index(0),
    Dequeue(dequeue.capacity),
    elements(new int[dequeue.capacity])
{
    this->capacity = dequeue.capacity;
    this->start_index = dequeue.start_index;
    this->end_index = dequeue.end_index;
    this->elements = dequeue.elements;
};

template <typename Type>
Dequeue<Type>::Dequeue(Dequeue&& dequeue) noexcept
{
    std::swap(*this, dequeue);
};

template <typename Type>
inline Type Dequeue<Type>::takeFront() {
    assertNotEmpty();

    Type element = getFront();

    if (start_index == end_index) {
        start_index = -1;
        end_index = -1;
    }
    else if (start_index == capacity - 1)
        start_index = 0;
    else
        start_index++;
    return element;
};

template <typename Type>
inline Type Dequeue<Type>::takeBack() {
    assertNotEmpty();

    Type element = getBack();

    if (start_index == end_index) {
        start_index = -1;
        end_index = -1;
    }
    else if (end_index == 0)
        end_index = capacity - 1;
    else
        end_index--;
    return element;
};

template <typename Type>
inline Type Dequeue<Type>::getFront() const {
    assertNotEmpty();

    return elements[start_index];
};

template <typename Type>
inline Type Dequeue< Type>::getBack() const {
    assertNotEmpty();

    return elements[end_index];
};
template <typename Type>
inline void Dequeue< Type>::offerFront(const Type& element) {
    assertNotFull();

    if (start_index == -1) {
        start_index = 0;
        end_index = 0;
    }
    else if (start_index == 0)
        start_index = capacity - 1;
    else
        start_index--;
    elements[start_index] = element;
};

template <typename Type>
inline void Dequeue<Type>::offerBack(const Type& element) {
    assertNotFull();

    if (start_index == -1) {
        start_index = 0;
        end_index = 0;
    }
    else if (end_index == capacity - 1)
        end_index = 0;
    else
        end_index++;
    elements[end_index] = element;
};

template <typename Type>
inline bool Dequeue<Type>::isEmpty() const {
    return start_index == -1;
};

template <typename Type>
inline bool Dequeue<Type>::isFull() const {
    return (start_index == 0 && end_index == capacity - 1) ||
        start_index == end_index + 1;
};

template <typename Type>
Dequeue& Dequeue<Type>::operator=(const Dequeue& dequeue)
{
    if (this != &dequeue)
    {
        Dequeue temp(dequeue);
        std::swap(*this, temp);
    }

    return *this;
};

template <typename Type>
Dequeue& Dequeue<Type>::operator=(Dequeue&& dequeue) noexcept
{
    if (this == &dequeue);
    return *this;
    std::swap(*this, dequeue);
    return *this;
};

template <typename Type>
inline void Dequeue<Type>::assertNotFull() const {
    if (isFull()) throw std::length_error("Очередь полная");
};

template <typename Type>
inline void Dequeue<Type>::assertNotEmpty() const {
    if (isEmpty())
        throw std::out_of_range("Очередь больше не содержит элементов");
}; 