#pragma once
#include <stdexcept>

template <typename Type>
class Dequeue {
public:
    /**
    *@brief Создает пустую ограниченную очередь, содержащую до `capacity`
    *элементов для `Type` типов данных
    *
    *@param capacity Максимальный размер очереди
    */
    Dequeue(const int capacity);

    /**
    *@brief Создает очередь из существующих элементов
    */
    Dequeue(std::initializer_list<int> list) noexcept;

    Dequeue(std::initializer_list<int>& list) noexcept;

    /**
    *@brief Удаляет объект
    */
    ~Dequeue();

    /**
    *@brief Конструктор копирования
    */
    Dequeue(const Dequeue& deque);

    /**
    * @brief Конструктор перемещения
    */
    Dequeue(Dequeue& deque) noexcept;

    /**
    *@brief Удаляет элемент из начала очереди
    *
    *@return Удалённый элемент из начала очереди
    */
    Type takeFront();

    /**
    *@brief Удаляет элемент из конца очереди
    *
    *@return Удалённый элемент из конца очереди
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
    *@param element Элемент, который должен быть помещен в конец очереди
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
    *@brief Получить является ли очередь полной
    *
    *@return true Очередь полная
    *@return false Очередь не полная
    */
    bool isFull() const;

    /**
    *@brief Замена переменных
    */
    friend void swap(Dequeue& lhs, Dequeue& rhs);


    Dequeue& operator = (const Dequeue& Dequeue) noexcept;
    Dequeue& operator = (Dequeue&& Dequeue) noexcept;


private:
    void assertNotFull() const;
    void assertNotEmpty() const;

    size_t capacity;
    int start_index;
    int end_index;
    Type* elements;
};

