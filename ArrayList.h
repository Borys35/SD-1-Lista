//
// Created by borys on 21/03/2025.
//

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#endif //ARRAYLIST_H

class ArrayList {
public:
    ArrayList();
    ~ArrayList();
    void push(int value);
    void push_back(int value);
    void insert(int value, unsigned int index);
    int remove(unsigned int index);
    int get(int index);
    int count();

private:
    int* array;
    int size;
    int max_size;
    void increase_size();
};