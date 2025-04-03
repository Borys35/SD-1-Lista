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

    if (this->head == nullptr) {
        // error;
        return;
    }

    DoublyLinkedListNode<T> *curNode = this->head;
    for (int i = 0; i < index; i++) {
        if (curNode->next != nullptr) {
            curNode = curNode->next;
            if (i == index - 1) {
                auto *nodeToRemove = new DoublyLinkedListNode<T>;
                nodeToRemove->value = value;
                nodeToRemove->prev = curNode->prev;
                nodeToRemove->next = curNode;
                curNode->prev->next = nodeToRemove;
                curNode->prev = nodeToRemove;
            }
        } else {
            // error
            break;
        }
    }
}

template<class T>
T DoublyLinkedList<T>::remove_front() {
    if (this->head == nullptr) {
        // error
        return -1;
    }
    T v = this->head->value;
    this->head->next->prev = nullptr;
    this->head = this->head->next;
    return v;
}

template<class T>
T DoublyLinkedList<T>::remove_back() {
    if (this->tail == nullptr) {
        // error
        return -1;
    }
    T v = this->tail->value;
    this->tail->prev->next = nullptr;
    this->tail = this->tail->prev;
    return v;
}

template<class T>
T DoublyLinkedList<T>::remove(int index) {
    if (this->head == nullptr) {
        // error
        return -1;
    }

    DoublyLinkedListNode<T> *curNode = this->head;
    for (int i = 0; i < index; i++) {
        if (curNode->next != nullptr) {
            curNode = curNode->next;
            if (i == index - 1) {
                curNode->next->prev = curNode->prev;
                curNode->prev->next = curNode->next;
                T v = curNode->value;
                delete curNode;
                return v;
            }
        } else {
            // error
            return -1;
        }
    }

    // error
    return -1;
}

template<class T>
T DoublyLinkedList<T>::get(int index) {
    if (index == 0)
        return this->head->value;

    DoublyLinkedListNode<T> *curNode = this->head;
    for (int i = 0; i < index; i++) {
        curNode = curNode->next;
        if (curNode == nullptr) {
            // error
            return -1;
        }
    }

    return curNode->value;
}

template<class T>
int DoublyLinkedList<T>::count() {
    return -1;
}

template class DoublyLinkedList<int>;

