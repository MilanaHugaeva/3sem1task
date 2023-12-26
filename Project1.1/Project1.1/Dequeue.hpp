#pragma once
#include <cmath>
#include <ostream>
#include <sstream>
#include <string>

template <typename Type>
class Dequeue {
public:
    /**
    *@brief Создает пустую ограниченную очередь, содержащую до `capacity`
    *элементов для `int` типов данных
    * 
    *@param capacity Максимальный размер очереди
    */
    Dequeue(const int capacity);

    /**
    *@brief Удаляет объект
    */
    ~Dequeue();

    /**
    *@brief Конструктор копирования
    */
    Dequeue(const Dequeue& deque) noexcept;

    /**
    *@brief Конструктор перемещения
    */
    Dequeue(Dequeue&& deque) noexcept;

    /**
    *@brief Удаляет элемент из передней части очереди
    * 
    *@return  Удалённый элемент из передней части очереди
    */
    Type takeFront();

    /**
    *@brief Удаляет элемент из задней части очереди
    *
    *@return  Удалённый элемент из задней части очереди
    */
    Type takeBack();

    /**
    *@brief Получить элемент из передней части очереди
    *
    *@return Элемент из передней части очереди
    */
    Type getFront() const;

    /**
    *@brief Получить элемент из задней части очереди
    *
    *@return Элемент из задней части очереди
    */
    Type getBack() const;

    /**
    *@brief Записывает заданный элемент в начало очереди
    *
    *@param element Элемент, который должен быть помещен в начало очереди        ,
    */
    void offerFront(const Type& element);

    /**
    *@brief Записывает заданный элемент в конец очереди
    *
    *@param element Элемент, который должен быть помещен в конец очереди
    */
    void offerBack(const Type& element);

    /**
    *@brief Получить является ли очередь пустой
    *
    *@return true Очередь пустая
    *@return false Очередь содержит некоторые элементы
    */
    bool isEmpty() const;

    /**
    * @brief Получить является ли очередь полной
    *
    *@return true Очередь полная
    *@return false Очередь не полна
    */
    bool isFull() const;

    /**
    *@brief Функция, которая преобразует коллекцию в строку.
    *@return Строку, состоящую из Nodes.
    */
    std::wstring ToString() noexcept;

    /**
    *@brief Функция, перегружающая оператор сравнения.
    *@param Сравнивает второй список.
    *@return Если содержимое списка равно второму списку то значение true и в противном случае значение false.
    */
    bool operator==(Dequeue<Type>& second);

    /**
    *@brief Замена переменных
    */
    friend void swap(Dequeue& lhs, Dequeue& rhs);

    Dequeue& operator = (const Dequeue& Dequeue);

    Dequeue& operator = (Dequeue&& Dequeue);
    
    void assertNotFull() const;
    void assertNotEmpty() const;


private:
   
    Type* elements;
    int start_index;
    int end_index;
    int capacity;
};

template <typename Type>
inline Dequeue<Type>::Dequeue(const int capacity)
    : start_index(-1),
    end_index(0),
    capacity(capacity),
    elements(new Type[capacity]) 
{
    if ( capacity <= 0)
    {
        throw std::logic_error("Невожможное значение!");
    }
} 

template<typename Type>
inline Dequeue<Type>::~Dequeue()
{
    delete[]elements;
}

template<typename Type>
inline Dequeue<Type>::Dequeue(const Dequeue& deque) noexcept
        : start_index(-1),
        end_index(0),
        capacity(capacity),
        elements(new int[capacity])
    {
        this->capacity = deque.capacity;
        this->start_index = deque.start_index;
        this->end_index = deque.end_index;
        for (auto i = 0; i < capacity; ++i)
        {
            this->elements[i] = deque.elements[i];
        }    
    }

template<typename Type>
inline Dequeue<Type>::Dequeue(Dequeue&& deque) noexcept : Dequeue() 
{
    std::swap(*this, deque);
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
inline Type Dequeue<Type>::getBack() const {
    assertNotEmpty();

    return elements[end_index];
};

template <typename Type>
inline void Dequeue<Type>::offerFront(const Type& element) {
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
}
template<typename Type>
inline std::wstring Dequeue<Type>::ToString() noexcept
{
    return std::wstring();
}
template<typename Type>
inline bool Dequeue<Type>::operator==(Dequeue<Type>& second)
{
    return(this->ToString() == second.ToString());
}
;

template<typename Type>
inline Dequeue<Type>& Dequeue<Type>::operator=(const Dequeue& Dequeue)
{
    if (this == &Dequeue)
    {
        return *this;
    }
    std::swap(*this, Dequeue);
    return *this;
}

template<typename Type>
inline Dequeue<Type>& Dequeue<Type>::operator=(Dequeue&& dequeue)
{
    if (*this != dequeue)
    {
        std::swap(*this, dequeue);
    }
    return *this;
}

template<typename Type>
std::wstring ToString(const Dequeue<Type>& dequeue)
{
    std::wstringstream buffer{};
    buffer << dequeue;

    return buffer.str();
}

template <typename Type>
inline void Dequeue<Type>::assertNotFull() const {
    if (isFull()) throw std::length_error("Очередь полная");
};

template <typename Type>
inline void Dequeue<Type>::assertNotEmpty() const {
    if (isEmpty())
        throw std::out_of_range("Очередь не содержит элементов");
};