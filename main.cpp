#include <iostream>

#include "ArrayList.hpp"
#include "DoublyLinkedList.hpp"

void fillArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1001;
    }
}

template<typename Func>
void arrayToList(int n, int arr[], const Func& push) {
    for (int i = 0; i < n; i++) {
        push(arr[i]);
    }
}

// C++20
int main() {
    srand(time(nullptr));

    std::cout<<"Hello\n";
    DoublyLinkedList linkedList = DoublyLinkedList<int>();
    ArrayList arrayList = ArrayList<int>();

    int size = 10;
    int *baseArray = new int[size];
    fillArray(baseArray, size);
    arrayToList(size, baseArray, [&](int value) { linkedList.push_back(value); });
    arrayToList(size, baseArray, [&](int value) { arrayList.push_back(value); });
    delete [] baseArray;

    std::cout<<"[ ";
    for (int i = 0; i < 10; i++) {
        std::cout<<linkedList.get(i)<<", ";
    }
    std::cout<<"]\n";

    std::cout<<"[ ";
    for (int i = 0; i < 10; i++) {
        std::cout<<arrayList.get(i)<<", ";
    }
    std::cout<<"]\n";

    return 0;
}
