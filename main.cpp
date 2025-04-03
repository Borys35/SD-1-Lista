#include <iostream>
#include <fstream>
#include <chrono>
// #include <boost/chrono.hpp>

#include "ArrayList.hpp"
#include "DoublyLinkedList.hpp"
#include "TestGenerator.hpp"

typedef std::chrono::high_resolution_clock Clock;

// C++20
// TODO: zaimplementowac SinglyLinkedList
// TODO: rozszerzyc testy o wszystkie operacje i wszystkie typy list
// TODO: stworzyc interaktywne menu do wyboru dzialan (testy, pojedyncze akcje itd.)
int main() {
    srand(0);

    generateTests();

    return 0;
}
