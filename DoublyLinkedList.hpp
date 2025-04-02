//
// Created by borys on 02/04/2025.
//

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "BaseList.hpp"

#endif //DOUBLYLINKEDLIST_H

template<class T>
struct DoublyLinkedListNode<T> {
    T value;
    DoublyLinkedListNode& next;
    DoublyLinkedListNode& prev;
};

template<class T>
class DoublyLinkedList : public BaseList<T> {
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void push_front(T value) override;
    void push_back(T value) override;
    void insert(T value, int index) override;
    T remove(int index) override;
    T get(int index) override;
    int count() override;

private:
    DoublyLinkedList& head;
    DoublyLinkedList& tail;
};