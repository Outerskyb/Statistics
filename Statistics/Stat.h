#pragma once
#include <algorithm>
#include <vector>
#include <random>

template<typename T>
class Stat
{
public:
    Stat();
    Stat(T* arr,size_t size);
    ~Stat();

public:
    void operator<<(T datum); 

public:
    T pick();

public:
    T mean();
    double variance();
    double stdev();
    double coefOfVar();
    T deviation();
    T sdeviation();
    
private:
    std::random_device rd;
    std::mt19937_64 mt;

private:
    size_t sdeviation_count;
    size_t deviation_count;
    std::vector<T> data;
    size_t count;
    T sum;
    T ssum;
};

