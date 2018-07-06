#pragma once
#include <algorithm>
#include <vector>
#include <random>

template<typename T>
class Data
{
public:
    Data();
    Data(T* arr, size_t size);
    ~Data();

public:
    void operator<<(T datum);
    size_t Count() { return count; }

public:
    T pick();

public:
    T mean();
    double variance();
    double stdev();
    double coefOfVar();
    void deviation_init();
    T deviation();
    void sdeviation_init();
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


template<typename T>
Data<T>::Data() : deviation_count(0), sdeviation_count(0), mt(rd()), count(0), sum(0), ssum(0)
{

}

template<typename T>
Data<T>::Data(T * arr, size_t size) : deviation_count(0), sdeviation_count(0), mt(rd()), sum(0), ssum(0)
{
    std::copy(arr, arr + size, data.begin());
    count = data.size();
}


template<typename T>
void Data<T>::operator<<(T datum)
{
    sum += datum;
    ssum += datum * datum;
    data.push_back(datum);
    count++;
    deviation_count = 0;
}

template<typename T>
T Data<T>::pick()
{
    uniform_int_distribution<size_t> uniform(0, count);
    return data[uniform(mt)];
}


template<typename T>
T Data<T>::mean()
{
    return sum / data.size();
}

template<typename T>
double Data<T>::variance()
{
    //  assert(count != 1 && "at least two element required\n");
    if (count == 1) return -1;
    return (ssum - sum * sum / double(count - 1)) / double(count - 1);
}

template<typename T>
double Data<T>::stdev()
{
    return sqrt(variance());
}

template<typename T>
double Data<T>::coefOfVar()
{
    return stdev() / mean();
}

template<typename T>
inline void Data<T>::deviation_init()
{
    deviation_count = 0;
}

template<typename T>
T Data<T>::deviation()
{
    //마지막 넘어감
    if (deviation_count == data.size()) {
        deviation_count = 0;
        return;
    }

    Dataic T avr;
    if (deviation_count == 0) {
        avr = mean();
    }
    return data[deviation_count++] - avr;
}

template<typename T>
inline void Data<T>::sdeviation_init()
{
    sdeviation_count = 0;
}

template<typename T>
T Data<T>::sdeviation()
{
    sdeviation_count++;
    //마지막 넘어감
    if (sdeviation_count == data.size()) {
        sdeviation_count = 0;
        return -1;
    }

    static T avr;
    if (sdeviation_count == 0) {
        avr = mean();
    }
    return (data[sdeviation_count] - avr)*(data[sdeviation_count] - avr);
}

template<typename T>
Data<T>::~Data()
{

}
