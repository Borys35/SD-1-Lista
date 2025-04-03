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
    auto *node = new DoublyLinkedListNode<T>;
    node->value = value;
    node->prev = this->tail;
    node->next = nullptr;
    if (this->tail == nullptr) {
        this->head = node;
        this->tail = node;
    } else {
        this->tail->next = node;
        this->tail = node;
    }
}

template<class T>
void DoublyLinkedList<T>::push_front(T value) {
    auto *node = new DoublyLinkedListNode<T>;
    node->value = value;
    node->next = this->head;
    node->prev = nullptr;
    if (this->head == nullptr) {
        this->head = node;
        this->tail = node;
    } else {
        this->head->prev = node;
        this->head = node;
    }
}

template<class T>
void DoublyLinkedList<T>::insert(T value, int index) {
    if (index == 0)
        push_front(value);

    DoublyLinkedListNode<T> *curNode = this->head;
    for (int i = 0; i < index; i++) {
        if (head->next != nullptr) {
            curNode = head->next;
            if (i == index - 1) {
                DoublyLinkedListNode<T> *newNode = nullptr;
                newNode->value = value;
                newNode->prev = curNode->prev;
                newNode->next = curNode;
                curNode->prev->next = newNode;
                curNode->prev = newNode;
            }
        } else {
            break;
        }
    }
}

template<class T>
T DoublyLinkedList<T>::remove(int index) {

}

template<class T>
T DoublyLinkedList<T>::get(int index) {
    if (index == 0)
        return this->head->value;

    DoublyLinkedListNode<T> *curNode = this->head;
    for (int i = 0; i < index; i++) {
        curNode = curNode->next;
    }

    return curNode->value;
}

template<class T>
int DoublyLinkedList<T>::count() {
    return 0;
}

template class DoublyLinkedList<int>;

