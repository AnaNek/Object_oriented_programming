#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <memory>
#include "errors.h"
#include "_node.hpp"
#include "_iterator.hpp"
#include "base_container.h"

template<typename T>
class List : public BaseContainer
{
    friend class Iterator<T>;
    friend class constIterator<T>;

private:
    std::shared_ptr< Node<T> > head;
    std::weak_ptr< Node<T> > tail;
public:
    List();

    List(T*, size_t);

    List(const T&, size_t = 1);

    List(std::initializer_list<T>);

    explicit List(const List<T> &list);

    List(List<T>&& list);

    explicit List(const Iterator<T> &beg, const Iterator<T> &end);

    List<T>& operator=(const List<T>& list);

    List<T>& operator=(List<T>&& list);

    ~List();

    virtual void clear() override;
    virtual size_t size() override;

    List<T>& append(const T&);
    List<T>& append(const List<T>&);
    List<T>& append(T *insertData, size_t numElems);

    List<T>& pushFront(const T&);
    List<T>& pushFront(const List<T>&);
    List<T>& pushFront(T *insertData, size_t numElems);

    T& popFront();

    List<T> operator+(const List<T>&) const;
    List<T> operator+(const T&) const;

    List<T>& operator+=(List<T>&&);
    List<T>& operator+=(const List<T>&);
    List<T>& operator+=(const T&);

    List<T>& remove(Iterator<T> &it);

    List<T>& insert(Iterator<T> &it, const T &data);
    List<T>& insert(Iterator<T> &it, const List<T>&);

    template<T> friend std::ostream & operator<< (std::ostream &, const List<T>&);

    Iterator<T> begin() { return Iterator<T>(head); }
    Iterator<T> end() { return Iterator<T>(nullptr); }
    constIterator<T> begin() const { return constIterator<T>(head); }
    constIterator<T> end() const { return constIterator<T>(nullptr); }


protected:
    List<T>& insert_before(Iterator<T> &it, const T &data);
    List<T>& insert_before(Iterator<T> &it, const List<T>&);
};

#endif
