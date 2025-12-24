#include "../include/Tests.h"
#include "../include/Histogram.h"
#include "../include/AlphabetIndex.h"
#include "../include/Search.h"
#include <cassert>
#include <iostream>

void runTests() {
    {
        std::vector<Person> p = {
            {"A", 10}, {"B", 15}, {"C", 21}
        };
        auto h = Histogram::buildByAge(p, 0, 30, 10);
        assert(h[std::make_pair(0,9)] == 0);
        assert(h[std::make_pair(10,19)] == 2);
        assert(h[std::make_pair(20,29)] == 1);
    }

    {
        std::string text = "alpha beta gamma alpha";
        auto idx = AlphabetIndex::build(text, 10);
        assert(idx["alpha"] == 1);
        assert(idx["beta"] == 1);
    }

    {
        std::vector<int> d = {1,2,3,4,5};
        assert(Search::linear(d, 4) == 3);
        assert(Search::binary(d, 5) == 4);
        assert(Search::binary(d, 10) == -1);
    }

    std::cout << "All tests passed\n";
}