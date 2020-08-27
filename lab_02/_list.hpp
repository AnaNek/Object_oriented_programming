#ifndef _LIST_H
#define _LIST_H

#include "list.h"

// конструкторы

template <typename T>
List<T>::List()
{
    this->head = nullptr;
    this->tail.lock() = nullptr;
}

template <typename T>
List<T>::List(const List<T>& list)
{
    // копирование
    if (!list.head)
    {
        this->head = nullptr;
        this->tail.reset();
    }
    else
    {
        std::shared_ptr< Node<T> > newNode(new Node<T>(list.head->getData()));
        this->head = newNode;

        constIterator<T> iter = list.begin();
        ++iter;
        for (; iter != list.end(); ++iter)
        {
            Node<T> *nextNode = new Node<T>(*iter);
            newNode->setNext(*nextNode);
            newNode = newNode->getNext();
        }

        this->tail = newNode;
    }
}

template <typename T>
List<T>::List(List<T>&& list)
{
    *this = list; // перенос
}

template<typename T>
List<T>::List(T *insertData, size_t numElems)
{
    if (!insertData || !numElems)
    {
        this->head = nullptr;
    }
    else
    {
        this->head = std::shared_ptr< Node<T> > (new Node<T>(insertData[0]));

        if (!this->head)
            throw memError(std::chrono::system_clock::now(),
                           __FILE__, typeid(*this).name(), __FUNCTION__);

        std::shared_ptr< Node<T> >newNode = this->head;

        for (int i = 1; i < (int)numElems; i++)
        {
            newNode->next = std::shared_ptr< Node<T> > (new Node<T>(insertData[i]));
            newNode = newNode->getNext();
        }

        this->tail = newNode;
    }
}

template<typename T>
List<T>::List(const T &insertData, size_t numElems)
{
    if (!numElems)
    {
        this->head = nullptr;
    }
    else
    {
        this->head = std::shared_ptr< Node<T> > (new Node<T>(insertData));

        if (!this->head)
            throw memError();

        std::shared_ptr< Node<T> >newNode = this->head;

        for (int i = 1; i < (int)numElems; i++)
        {
            newNode->next = std::shared_ptr< Node<T> > (new Node<T>(insertData));
            newNode = newNode->getNext();
        }

        this->tail = newNode;
    }
}

template<typename T>
List<T>::List(const Iterator<T> &beg, const Iterator<T> &end)
{
    for (auto it = beg; it != end; ++it)
    {
        append(*it);
    }
}

template<typename T>
List<T>::List(std::initializer_list<T> l)
{
    if (l.begin() == l.end())
    {
        this->head = nullptr;
    }
    else
    {
        for (auto it = l.begin(); it != l.end(); ++it)
        {
            append(*it);
        }
    }
}

// перегруженные операторы

template <typename T>
List<T>& List<T>::operator=(const List<T>& list)
{
    if (this == &list)
        return *this;

    if (this->head)
        this->clear();

    if (!&list.head)
    {
        this->head = nullptr;
        this->tail.reset();
        return *this;
    }

    this->head = std::shared_ptr< Node<T> > (new Node<T>(list.head->getData()));

    if (!this->head)
        throw memError(std::chrono::system_clock::now(),
                       __FILE__, typeid(*this).name(), __FUNCTION__);

    std::shared_ptr< Node<T> >curNodeRight = list.head->next;
    std::shared_ptr< Node<T> >curNodeLeft = this->head;


    while (curNodeRight != nullptr)
    {
        curNodeLeft->next = std::shared_ptr< Node<T> > (new Node<T>(curNodeRight->getData()));
        curNodeLeft = curNodeLeft->next;
        curNodeRight = curNodeRight->next;
    }

    this->tail = curNodeLeft;
    return *this;
}

template <typename T>
List<T>& List<T>::operator=(List<T>&& list)
{
    if (this == &list)
        return *this;

    if (this->head)
        this->clear();

    if (!&list.head)
    {
        this->head = nullptr;
        this->tail.reset();
        return *this;
    }

    this->head = std::shared_ptr< Node<T> > (new Node<T>(list.head->getData()));

    if (!this->head)
        throw memError();

    std::shared_ptr< Node<T> >curNodeRight = list.head->next;
    std::shared_ptr< Node<T> >curNodeLeft = this->head;


    while (curNodeRight != nullptr)
    {
        curNodeLeft->next = std::shared_ptr< Node<T> > (new Node<T>(curNodeRight->getData()));
        curNodeLeft = curNodeLeft->next;
        curNodeRight = curNodeRight->next;
    }

    this->tail = curNodeLeft;
    return *this;
}

template <typename T>
List<T> List<T>::operator+(const List<T> &insertList) const
{
    List<T> list = List(*this);

    Iterator<T> it = list.end();
    list.insert_before(it, insertList);
    return list;
}

template <typename T>
List<T> List<T>::operator+(const T &insertData) const
{
    List<T> list = List(*this);

    Iterator<T> it = list.end();
    list.insert_before(it, insertData);
    return list;
}

template <typename T>
List<T>& List<T>::operator+=(List<T> &&insertList)
{
    if (!head)
    {
        head = insertList.head;
        tail = insertList.tail;
        tail.lock()->next = nullptr;
    }
    else
    {
        tail.lock()->next = insertList.head;
        tail = insertList.tail;
        tail.lock()->next = nullptr;
    }
    return *this;
}

template <typename T>
List<T>& List<T>::operator+=(const List<T> &insertList)
{
    Iterator<T> it = end();
    insert_before(it, insertList);
    return *this;
}

template <typename T>
List<T>& List<T>::operator+=(const T &insertData)
{
    Iterator<T> it = end();
    insert_before(it, insertData);
    return *this;
}

template <typename T>
std::ostream & operator<<(std::ostream &os, List<T>&l)
{
    os << "List: ";
    for (T el : l)
    {
        os << el << " ";
    }
    os << "\n";
    return os;
}

// методы

template <typename T>
List<T>& List<T>::append(const T &insertData)
{
    Iterator<T> it = end();
    insert_before(it, insertData);
    return *this;
}

template <typename T>
List<T>& List<T>::append(T *insertData, size_t numElems)
{
    if (!insertData || !numElems)
    {
        this->head = nullptr;
    }
    else
    {
        List<T> insertList = List(insertData, numElems);
        Iterator<T> it = end();
        insert_before(it, insertList);
        insertList.clear();
    }
    return *this;
}

template <typename T>
List<T>& List<T>::append(const List<T> &insertList)
{
    Iterator<T> it = end();
    insert_before(it, insertList);

    return *this;
}

template <typename T>
List<T>& List<T>::pushFront(const T &insertData)
{
    Iterator<T> it = begin();
    insert_before(it, insertData);

    return *this;
}

template <typename T>
List<T>& List<T>::pushFront(T *insertData, size_t numElems)
{
    if (!insertData || !numElems)
    {
        this->head = nullptr;
    }
    else
    {
        List<T> *insertList = new List(insertData, numElems);
        Iterator<T> it = begin();
        insert_before(it, *insertList);
    }

    return *this;
}

template <typename T>
List<T>& List<T>::pushFront(const List<T> &insertList)
{
    if (!insertList.head)
        return *this;

    Iterator<T> it = begin();
    insert_before(it, insertList);

    return *this;
}


template <typename T>
List<T>& List<T>::remove(Iterator<T> &it)
{
    if(!this->head)
        throw emptyError(std::chrono::system_clock::now(),
                         __FILE__, typeid(*this).name(), __FUNCTION__);

    if (it == end())
        return *this;

    std::shared_ptr< Node<T> > prevNode = nullptr;
    std::shared_ptr< Node<T> > curNode = this->head;
    for (Iterator<T> iter = begin(); iter != Iterator<T>(this->tail.lock()) \
         && iter != Iterator<T>(it.getCur()->getNext()); ++iter)
    {
        prevNode = curNode;
        curNode = curNode->getNext();
    }

    if (curNode == this->head)
    {
        this->head.reset();
        this->head = curNode->getNext();
    }
    else
    {
        if (curNode == this->tail.lock())
        {
            prevNode->next = nullptr;
            this->tail.reset();
            this->tail = prevNode;
            this->tail.lock()->next = nullptr;
        }
        else
        {
            prevNode->next = curNode->getNext();
            curNode.reset();
        }
    }
    return *this;
}

template <typename T>
T& List<T>::popFront()
{
    if(!this->head)
        throw emptyError(std::chrono::system_clock::now(),
                         __FILE__, typeid(*this).name(), __FUNCTION__);

    std::shared_ptr< Node<T> > curNode = this->head;
    this->head = this->head->getNext();

    return curNode->getData();
}

template <typename T>
List<T>& List<T>::insert(Iterator<T> &it, const T &data)
{
    if (it == end())
        return *this;

    Iterator<T> iter = Iterator<T>(it.getCur()->getNext());
    insert_before(iter, data);

    return *this;
}

template <typename T>
List<T>& List<T>::insert(Iterator<T> &it, const List<T> &list)
{
    if (!list.head || it == end())
        return *this;

    Iterator<T> iter = Iterator<T>(it.getCur()->getNext());
    insert_before(iter, list);

    return *this;
}

template <typename T>
List<T>& List<T>::insert_before(Iterator<T> &it, const T &data)
{
    std::shared_ptr< Node<T> > prevNode = nullptr;
    std::shared_ptr< Node<T> > curNode = this->head;
    for (Iterator<T> iter = begin(); iter != end() && iter != it; ++iter)
    {
        prevNode = curNode;
        curNode = curNode->getNext();
    }

    if (curNode == this->head || !this->head)
    {
        std::shared_ptr< Node<T> > newNode(new Node<T>(data));
        newNode->next = this->head;
        this->head = newNode;
    }
    else
    {
        std::shared_ptr< Node<T> > newNode(new Node<T>(data));
        newNode->next = curNode;
        prevNode->next = newNode;

        if (curNode == nullptr)
        {
            this->tail = newNode;
        }
    }

    return *this;
}

template <typename T>
List<T>& List<T>::insert_before(Iterator<T> &it, const List<T> &list)
{
    if (!list.head)
        return *this;

    std::shared_ptr< Node<T> > prevNode = nullptr;
    std::shared_ptr< Node<T> > curNode = this->head;

    for (Iterator<T> iter = begin(); iter != end() && iter != it; ++iter)
    {
        prevNode = curNode;
        curNode = curNode->getNext();
    }

    std::shared_ptr< Node<T> > newNode(new Node<T>(list.head->getData()));
    std::shared_ptr< Node<T> > newHead = newNode;

    constIterator<T> iter = list.begin();
    ++iter;
    for (; iter != list.end(); ++iter)
    {
        Node<T> *nextNode = new Node<T>(*iter);
        newNode->setNext(*nextNode);
        newNode = newNode->getNext();
    }

    if (curNode == this->head)
    {
        newNode->next = this->head;
        this->head = newHead;
    }
    else
    {
        if (curNode == nullptr)
        {
            this->tail = newNode;
        }
        newNode->next = curNode;
        prevNode->next = newHead;
    }

    return *this;
}

template <typename T>
void List<T>::clear(void)
{
    int len = size();

    for (int i = 0; i < len; i++)
    {
        popFront();
    }
}

template <typename T>
size_t List<T>::size()
{
    size_t size = 0;

    for (Iterator<T> it = begin(); it != end(); ++it)
    {
        size++;
    }

    return size;
}

// деструктор

template <typename T>
List<T>::~List()
{
    this->clear();
}

#endif
