#ifndef ITERATOR_H
#define ITERATOR_H

#include <memory>
#include "node.h"
#include "errors.h"

template <typename T>
class List;

template<typename T>
class AbstractIterator
{
protected:
    virtual bool notInRange() const = 0;
};

template<typename T>
class Iterator : public AbstractIterator<T>
{
private:
    std::weak_ptr< Node<T> > cur;
public:
    Iterator();
    Iterator(std::shared_ptr< Node<T> > ptr): cur(ptr) {}

    std::shared_ptr< Node<T> > getCur();

    T& operator*();
    const T& operator*() const;
    T* operator->();
    const T* operator->() const;

    virtual bool notInRange() const override;

    explicit operator bool() const;

    Iterator<T>& operator++();

    bool operator==(const Iterator & rhs) const;

    bool operator!=(const Iterator & rhs) const;
};

template<typename T>
class constIterator : public AbstractIterator<T>
{
private:
    std::weak_ptr< Node<T> > cur;
public:
    constIterator();
    constIterator(std::shared_ptr< Node<T> > ptr): cur(ptr) {}

    std::shared_ptr< Node<T> > getCur();

    const T& operator*() const;
    const T* operator->() const;

    virtual bool notInRange() const override;

    explicit operator bool() const;

    constIterator<T>& operator++();

    bool operator==(const constIterator & rhs) const;

    bool operator!=(const constIterator & rhs) const;
};

#endif
