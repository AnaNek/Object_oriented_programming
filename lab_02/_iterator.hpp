#ifndef _ITERATOR_H
#define _ITERATOR_H

#include "iterator.h"

//Iterator

template<typename T>
Iterator<T>::Iterator()
{
    cur.reset();
}

template<typename T>
std::shared_ptr< Node<T> > Iterator<T>::getCur()
{
    return cur.lock();
}

template<typename T>
T& Iterator<T>::operator*()
{
    if (notInRange())
        throw rangeError(std::chrono::system_clock::now(),
                         __FILE__, typeid(*this).name(), __FUNCTION__);

    return cur.lock()->getData();
}

template<typename T>
T* Iterator<T>::operator->()
{
    return cur;
}

template<typename T>
const T& Iterator<T>::operator*() const
{
    if (notInRange())
        throw rangeError(std::chrono::system_clock::now(),
                         __FILE__, typeid(*this).name(), __FUNCTION__);

    return cur.lock()->getData();
}

template<typename T>
const T* Iterator<T>::operator->() const
{
    return cur;
}

template<typename T>
bool Iterator<T>::notInRange() const
{
    return cur.lock() == nullptr;
}

template<typename T>
Iterator<T>::operator bool() const
{
    return ((cur.lock() == nullptr) ? true : false);
}

template<typename T>
Iterator<T>& Iterator<T>::operator++()
{
    if (notInRange())
        throw rangeError(std::chrono::system_clock::now(),
                         __FILE__, typeid(*this).name(), __FUNCTION__);

    cur = cur.lock()->getNext();
    return *this;
}

template<typename T>
bool Iterator<T>::operator==(const Iterator & rhs) const
{
    return ( this->cur.lock() == rhs.cur.lock() );
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator & rhs) const
{
    return !( *this == rhs );
}

//constIterator

template<typename T>
constIterator<T>::constIterator()
{
    cur.reset();
}

template<typename T>
std::shared_ptr< Node<T> > constIterator<T>::getCur()
{
    return cur.lock();
}

template<typename T>
const T& constIterator<T>::operator*() const
{
    if (notInRange())
        throw rangeError(std::chrono::system_clock::now(),
                         __FILE__, typeid(*this).name(), __FUNCTION__);

    return cur.lock()->getData();
}

template<typename T>
const T* constIterator<T>::operator->() const
{
    return cur;
}

template<typename T>
bool constIterator<T>::notInRange() const
{
    return cur.lock() == nullptr;
}

template<typename T>
constIterator<T>::operator bool() const
{
    return ((cur.lock() == nullptr) ? true : false);
}

template<typename T>
constIterator<T>& constIterator<T>::operator++()
{
    if (notInRange())
        throw rangeError(std::chrono::system_clock::now(),
                         __FILE__, typeid(*this).name(), __FUNCTION__);

    cur = cur.lock()->getNext();
    return *this;
}

template<typename T>
bool constIterator<T>::operator==(const constIterator & rhs) const
{
    return ( this->cur.lock() == rhs.cur.lock() );
}

template<typename T>
bool constIterator<T>::operator!=(const constIterator & rhs) const
{
    return !( *this == rhs );
}

#endif
