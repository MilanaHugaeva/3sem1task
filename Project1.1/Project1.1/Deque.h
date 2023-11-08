#pragma once

template <typename Type>
class Dequeue {
public:
    /**
    *@brief ������� ������ ������������ �������, ���������� �� `capacity`
    * ��������� ��� `Type` ����� ������
    *
    * @param capacity ������������ ������ �������
    */
    Dequeue(const int capacity) noexcept;

    /**
    *@brief ������� ������� �� ������������ ���������
    */
    Dequeue(std::initializer_list<int>& list) noexcept;

    /**
    * @brief ������� ������
    */
    ~Dequeue();

    /**
    * @brief ����������� �����������
    */
    Dequeue(const Dequeue& deque) noexcept;

    /**
    * @brief ����������� �����������
    */
    Dequeue(Dequeue&& deque) noexcept;

    /**
    *@brief ������� ������� �� �������� ����� �������
    *
    *@return �������� ������� �� �������� ����� �������
    */
    Type takeFront();

    /**
    *@brief ������� ������� �� ������ ����� �������
    *
    *@return �������� ������� �� ������ ����� �������
    */
    Type takeBack();

    /**
    *@brief �������� ������� �� �������� ����� �������
    *
    *@return ������� �� �������� ����� �������
    */
    Type getFront() const;

    /**
    *@brief �������� ������� �� ������ ����� �������
    *
    *@return ������� �� ������ ����� �������
    */
    Type getBack() const;

    /**
    *@brief ���������� �������� ������� � ������ �������
    *
    *@param element �������, ������� ������ ���� ������� � ����� �������
    */
    void offerFront(const Type& element);

    /**
    *@brief ���������� �������� ������� � ����� �������
    *
    *@param element �������, ������� ������ ���� ������� � ����� �������
    */
    void offerBack(const Type& element);

    /**
    *@brief �������� �������� �� ������� ������
    *
    *@return true ������� ������
    * @return false ������� �������� ��������� ��������
    */
    bool isEmpty() const;

    /**
    * @brief �������� �������� �� ������� ������
     *
     * @return true ������� ������
     * @return false ������� �� ������
    */
    bool isFull() const;

    /**
    * @brief ������ ����������
    */
    friend void swap(Dequeue& lhs, Dequeue& rhs);

    Dequeue& operator = (const Dequeue& Dequeue);

    Dequeue& operator = (Dequeue&& Dequeue);


private:
    void assertNotFull() const;
    void assertNotEmpty() const;

    int capacity;
    int start_index;
    int end_index;
    Type* elements;
};