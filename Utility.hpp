#pragma once

#include <chrono>
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

// oblicza czas wykonania podanej funkcji
template<typename Func>
long long measureTime(const Func& func) {
    auto t1 = Clock::now();
    func();
    auto t2 = Clock::now();
    return std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count();
}