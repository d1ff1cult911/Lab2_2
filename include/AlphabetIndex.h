#pragma once
#include <string>
#include <map>

class AlphabetIndex {
public:
    using Index = std::map<std::string, int>;
    static Index build(
        const std::string& text,
        int pageSizeChars
    );

};