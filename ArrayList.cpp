//
// Created by borys on 21/03/2025.
//

#include "ArrayList.h"

ArrayList::ArrayList() {
    size = 0;
    max_size = 4;
    array = new int[max_size];
    for (int i = 0; i < max_size; i++) {
        array[i] = 0;
    }
}

ArrayList::~ArrayList() {
    delete[] array;
}

int ArrayList::count() {
    return size;
}

void ArrayList::increase_size() {
    max_size *= 2;
    int *temp = new int[max_size];
    for (int i = 0; i < size - 1; i++) {
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
}


void ArrayList::push_back(int value) {
    size++;
    if (size > max_size) {
        increase_size();
    }
    array[size - 1] = value;
}

void ArrayList::push(int value) {
    size++;
    if (size > max_size) {
        increase_size();
    }
    for (int i = size - 1; i > 0; i--) {
        array[i] = array[i - 1];
    }
    array[0] = value;
}

void ArrayList::insert(int value, unsigned int index) {
    size++;
    if (size > max_size) {
        increase_size();
    }
    for (int i = size - 1; i > index; i--) {
        array[i] = array[i - 1];
    }
    array[index] = value;
}

int ArrayList::remove(unsigned int index) {
    size--;
    int v = array[index];
    for (unsigned int i = index; i < size - 1; i++) {
        array[i] = array[i + 1];
    }
    return v;
}

int ArrayList::get(int index) {
    if (index > size - 1 || index < 0) {
        return -1;
    }
    return array[index];
}



