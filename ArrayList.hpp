#pragma once

#include "BaseList.hpp"

template<class T>
class ArrayList : public BaseList<T> {
public:
    ArrayList();
    ~ArrayList();
    void push_front(T value) override;
    void push_back(T value) override;
    void insert(T value, int index) override;
    T remove_front() override;
    T remove_back() override;
    T remove(int index) override;
    T get(int index) override;
    int count() override;
    int search(T value) override;

private:
    int* array;
    int size;
    int max_size;
    void increase_size();
};