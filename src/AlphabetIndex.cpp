#include "../include/AlphabetIndex.h"
#include <sstream>

AlphabetIndex::Index AlphabetIndex::build(
    const std::string& text,
    int pageSizeChars
){
    Index index;
    int currentPage = 1;
    int currentSize = 0;
    std::istringstream iss(text);
    std::string word;
    while (iss >> word) {
        if (currentSize + (int)word.length()*1 > pageSizeChars) {
            currentPage++;
            currentSize = 0;
        }
        currentSize += word.length() + 1;
        if(!index.count(word)){
            index[word] = currentPage;
        }
    }
    return index;
}