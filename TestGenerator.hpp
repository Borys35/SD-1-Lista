#include <iostream>
#include <fstream>
#include <chrono>

#include "Utility.hpp"
#include "ArrayList.hpp"
#include "DoublyLinkedList.hpp"

typedef std::chrono::high_resolution_clock Clock;

void generateTests() {
    std::ofstream file;
    file.open("./data.txt", std::ios::out | std::ios::trunc);

    if (!file.is_open()) {
        std::cout<<"Plik nie moze zostac otworzony"<<std::endl;
        return;
    }

    std::cout<<"Generowanie testow\n";

    int sizes[8] = {5000, 8000, 10000, 16000, 20000, 40000, 60000, 100000};

    // naglowki dla tabeli
    file << "no.,size,operation,array list,doubly linked list\n";

    for (int i = 0; i < 8; i++) {
        int size = sizes[i];

        // ilosc testow na jedna operacje
        for (int j = 0; j < 100; j++) {
            file << j + 1 << "," << size << "," << "push_back" << ",";

            ArrayList arrayList = ArrayList<int>();
            DoublyLinkedList doublyLinkedList = DoublyLinkedList<int>();
            int *baseArray = new int[size];
            fillArray(baseArray, size);
            arrayToList(size, baseArray, [&](int value) { arrayList.push_back(value); });
            arrayToList(size, baseArray, [&](int value) { doublyLinkedList.push_back(value); });

            // auto t1 = Clock::now();
            // arrayList.push_back(500);
            // auto t2 = Clock::now();
            // long long duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
            long long duration = measureTime([&]() { arrayList.push_back(500); });
            file << duration << ",";

            // t1 = Clock::now();
            // doublyLinkedList.push_back(500);
            // t2 = Clock::now();
            // duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
            duration = measureTime([&]() { doublyLinkedList.push_back(500); });
            file << duration << "\n";

            delete [] baseArray;
        }
    }
}