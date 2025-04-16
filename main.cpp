#include <iostream>
#include <fstream>
#include <chrono>
#include "ArrayList.hpp"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.hpp"
#include "TestGenerator.hpp"
#include "Menu.h"

// typedef std::chrono::high_resolution_clock Clock;

int main() {
    srand(0);
    std::cout << "Program do testowania struktur danych - listy\n";
    std::cout << "=============================================\n\n";
    runMenu();
    return 0;
}
