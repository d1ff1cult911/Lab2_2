#include <iostream>
#include <vector>
#include "include/Histogram.h"
#include "include/AlphabetIndex.h"
#include "include/Search.h"
#include "include/Timer.h"
#include "include/Tests.h"

int main() {
    runTests();

    std::vector<Person> people = {
        {"Alice", 23}, {"Bob", 35}, {"Charlie", 29}, {"Dave", 41}
    };

    while (true) {
        std::cout << "\n1. Histogram\n2. Alphabet index\n3. Compare search\n0. Exit\n";
        int c;
        std::cin >> c;

        if (c == 0) break;

        if (c == 1) {
            auto h = Histogram::buildByAge(people, 0, 60, 10);
            for (auto& b : h)
                std::cout << b.first.first << "-" << b.first.second
                          << ": " << b.second << "\n";
        }

        if (c == 2) {
            std::cin.ignore();
            std::string text;
            std::cout << "Enter text:\n";
            std::getline(std::cin, text);

            auto idx = AlphabetIndex::build(text, 20);
            for (auto& p : idx)
                std::cout << p.first << " -> page " << p.second << "\n";
        }

        if (c == 3) {
            std::vector<int> data;
            for (int i = 0; i < 100000; i++)
                data.push_back(i * 2);

            int key = 199998;

            auto t1 = measure([&]() { Search::linear(data, key); });
            auto t2 = measure([&]() { Search::binary(data, key); });

            std::cout << "Linear: " << t1 << " us\n";
            std::cout << "Binary: " << t2 << " us\n";
        }
    }

    return 0;
}