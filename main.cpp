#include <iostream>
#include <fstream>
#include <chrono>

#include "ArrayList.hpp"
#include "DoublyLinkedList.hpp"

typedef std::chrono::high_resolution_clock Clock;

// tworzy tablice z bazowymi wartosciami (int)
void fillArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1001;
    }
}

// kopiuje tablice do danej listy przez dana funkcje "push" (int)
template<typename Func>
void arrayToList(int n, int arr[], const Func& push) {
    for (int i = 0; i < n; i++) {
        push(arr[i]);
    }
}

// C++20
int main() {
    srand(time(nullptr));

    std::ofstream file;
    file.open("./data.txt", std::ios::out | std::ios::trunc);

    if (!file.is_open()) {
        std::cout<<"Plik nie moze zostac otworzony"<<std::endl;
        return 3;
    }

    std::cout<<"Struktury Danych - Listy\n";

    DoublyLinkedList linkedList = DoublyLinkedList<int>();
    ArrayList arrayList = ArrayList<int>();

    int sizes[8] = {5000, 8000, 10000, 16000, 20000, 40000, 60000, 100000};

    int arraySize = 10;
    int *baseArray = new int[arraySize];
    fillArray(baseArray, arraySize);
    arrayToList(arraySize, baseArray, [&](int value) { linkedList.push_back(value); });
    arrayToList(arraySize, baseArray, [&](int value) { arrayList.push_back(value); });
    delete [] baseArray;

    // naglowki dla tabeli
    file << "no.,size,operation,array list,doubly linked list\n";

    for (int i = 0; i < 8; i++) {
        int size = sizes[i];

        // ilosc testow na jedna operacje
        for (int j = 0; j < 100; j++) {
            file << j + 1 << "," << size << "," << "push_back" << ",";
            auto t1 = Clock::now();
            arrayList.insert(500, 300);
            auto t2 = Clock::now();
            long long duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();

            file << duration << ",";

            // to samo dla innych typow list
            file << duration << "\n";
        }
    }

    // std::cout<<"[ ";
    // for (int i = 0; i < 10; i++) {
    //     std::cout<<linkedList.get(i)<<", ";
    // }
    // std::cout<<"]\n";
    //
    // std::cout<<"[ ";
    // for (int i = 0; i < 10; i++) {
    //     std::cout<<arrayList.get(i)<<", ";
    // }
    // std::cout<<"]\n";

    return 0;
}
