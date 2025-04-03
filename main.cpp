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
    for (int i = 1; i < n + 1; i++) {
        linkedList.push_front(i);
    }
    linkedList.remove_back();
    linkedList.remove_front();
    linkedList.insert(1000, 2);
    linkedList.remove(3);

    std::cout<<"[ ";
    for (int i = 0; i < 9; i++) {
        std::cout<<linkedList.get(i)<<", ";
    }
    std::cout<<"]\n";

    // std::cout<<linkedList.get(10);

    return 0;
}