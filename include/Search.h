#pragma once
#include <vector>

class Search {
public:
    static int linear(
        const std::vector<int>& data,
        int key
    );

    static int binary(
        const std::vector<int>& data,
        int key
    );
};