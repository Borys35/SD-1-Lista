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
    virtual void insert(T value, int index) = 0;
    virtual T remove(int index) = 0;
    virtual T get(int index) = 0;
    virtual int count() = 0;
};
