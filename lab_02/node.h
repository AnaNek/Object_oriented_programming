#ifndef NODE_H
#define NODE_H

#include <memory>

template <typename T>
class List;

template<typename T>
class Iterator;

template<typename T>
class constIterator;

template <typename T>
class Node
{
    friend class List<T>;
    friend class Iterator<T>;
    friend class constIterator<T>;
private:
    T data;
    std::shared_ptr<Node> next;

public:
    Node(T insertData = 0);
    Node(Node<T> &newElem);

    T& getData();
    std::shared_ptr<Node<T> > getNext();
    void setData(T insertData);
    void setNext(Node<T> &nextElem);
};

#endif
