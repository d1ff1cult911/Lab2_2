#include "../include/Search.h"

int Search::linear(const std::vector<int>& data, int key){
    for(size_t i = 0;i<data.size();++i){
        if(data[i]==key){
            return i;
        }
    }
    return -1;
}
int Search::binary(const std::vector<int>& data,int key){
    int l = 0;
    int r = data.size() - 1;
    while (l <= r) {
        int m =(l+r) / 2;
        if (data[m] == key) {
            return m;
        }
        else if (data[m] < key) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return -1;
}
