#pragma once
#include <vector>

template<typename T>
class Stat
{
public:
    Stat();
    ~Stat();

public:
    void operator<<(T datum); 
private:
    std::vector<T> data;

};

