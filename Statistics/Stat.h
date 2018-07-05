#pragma once
#include <algorithm>
#include <vector>

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
    T mean();
    T variance();
    T deviation();
    T sdeviation();
    
private:
    size_t sdeviation_count;
    size_t deviation_count;
    std::vector<T> data;
    size_t count;
    T sum;
    T ssum;
};

