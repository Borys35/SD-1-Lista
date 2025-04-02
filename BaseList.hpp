//
// Created by borys on 02/04/2025.
//

#ifndef BASELIST_HPP
#define BASELIST_HPP

#endif //BASELIST_HPP

template<class T>
class BaseList {
public:
    virtual ~BaseList() = default;

    virtual void push_front(T value) = 0;
    virtual void push_back(T value) = 0;
    virtual void insert(T value, T index) = 0;
    virtual T remove(T index) = 0;
    virtual T get(T index) = 0;
    virtual T count() = 0;
};
