#include <iostream>

#include "ArrayList.hpp"
#include "DoublyLinkedList.hpp"

// C++20
int main() {
    std::cout<<"Hello\n";
    DoublyLinkedList linkedList = DoublyLinkedList<int>();
    ArrayList arrayList = ArrayList<int>();

    //linkedList.push_back(5);

    int n = 10;
    for (int i = 0; i < n; i++) {
        linkedList.push_front(i);
    }

    std::cout<<"[ ";
    for (int i = 0; i < n; i++) {
        std::cout<<linkedList.get(i)<<", ";
    }
    std::cout<<"]\n";

    // std::cout<<linkedList.get(10);

    return 0;
}