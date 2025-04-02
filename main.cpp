#include <iostream>

#include "ArrayList.hpp"

// C++20
int main() {
    std::cout<<"Hello\n";
    ArrayList arrayList = ArrayList<int>();
    int n = 100;
    clock_t start = clock();
    for (int i = 0; i < n; i++) {
        arrayList.push_back(i);
    }
    clock_t end = clock() - start;
    std::cout<<"Time elapsed: "<<(double)(end) / CLOCKS_PER_SEC<<"s\n";
    std::cout<<"[ ";
    for (int i = 0; i < n; i++) {
        std::cout<<arrayList.get(i)<<", ";
    }
    std::cout<<" ]";
}