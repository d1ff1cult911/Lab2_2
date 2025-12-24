#pragma once
#include <vector>
#include "Person.h"
#include <map>
class Histogram {
public:
    using Bucket = std::pair<int, int>;
    using Result = std::map<Bucket, int>;

    static Result buildByAge(
        const std::vector<Person>& data,
        int minAge,
        int maxAge,
        int bucketSize
    );
};