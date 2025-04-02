//
// Created by borys on 02/04/2025.
//

#include "DoublyLinkedList.hpp"

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(): head(nullptr), tail(nullptr) {
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList() = default;

template<class T>
void DoublyLinkedList<T>::push_back(T value) {
    DoublyLinkedListNode<T> node;
    node.value = value;
    node.prev = this.tail;
    node.next = nullptr;
    this.tail->next = &node;
}

template<class T>
void DoublyLinkedList<T>::push_front(T value) {
    DoublyLinkedListNode<T> node;
    node.value = value;
    node.prev = nullptr;
    node.next = this.head;
    this.head->prev = &node;
}

template<class T>
void DoublyLinkedList<T>::insert(T value, int index) {

}

template<class T>
T DoublyLinkedList<T>::remove(int index) {

}

template<class T>
T DoublyLinkedList<T>::get(int index) {
    return (head + index)->value;
}

template<class T>
int DoublyLinkedList<T>::count() {
    return 0;
}

