#include "../include/Histogram.h"

Histogram::Result Histogram::buildByAge(
    const std::vector<Person>& data,
    int minAge,
    int maxAge,
    int bucketSize
){
    Result result;
    for(int age = minAge; age < maxAge; age += bucketSize){
        result[{age, age + bucketSize - 1}] = 0;
    }

    for(const auto& person : data){
        for(auto& bucket:result){
            if(person.age >= bucket.first.first && person.age <= bucket.first.second){
                bucket.second++;
                break;
            }
        }
    }

    return result;
}