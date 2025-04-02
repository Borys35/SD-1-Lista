//
// Created by borys on 21/03/2025.
//

#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include "BaseList.hpp"

#endif //ARRAYLIST_H

template<class T>
class ArrayList : public BaseList<T> {
public:
    ArrayList();
    ~ArrayList();
    void push_front(T value) override;
    void push_back(T value) override;
    void insert(T value, T index) override;
    T remove(T index) override;
    T get(T index) override;
    T count() override;

private:
    int* array;
    int size;
    int max_size;
    void increase_size();
};