#ifndef _NODE_H
#define _NODE_H

#include "node.h"

template<typename T>
Node<T>::Node(T insertData)
{
    this->data = insertData;
    this->next = std::shared_ptr< Node<T> >(nullptr);
}

template<typename T>
Node<T>::Node(Node<T> &newElem)
{
    this->data = newElem.data;
    this->next = newElem.next;
}

template<typename T>
void Node<T>::setData(T insertData)
{
    this->data = insertData;
}

template<typename T>
void Node<T>::setNext(Node<T> &nextElem)
{
    this->next = std::shared_ptr< Node<T> >(&nextElem);
}

template<typename T>
T& Node<T>::getData()
{
    return this->data;
}

template<typename T>
std::shared_ptr<Node<T> > Node<T>::getNext()
{
    return this->next;
}

#endif
