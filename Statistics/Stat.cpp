#include "Stat.h"


template<typename T>
Stat<T>::Stat() : deviation_count(0),sdeviation_count(0)
{

}

template<typename T>
Stat<T>::Stat(T * arr, size_t size) : deviation_count(0), sdeviation_count(0)
{
    std::copy(arr, arr + size, data.begin());
}


template<typename T>
void Stat<T>::operator<<(T datum)
{
    sum  += datum;
    ssum += datum * datum;
    data.push_back(datum);
    
    deviation_count = 0;
}


template<typename T>
T Stat<T>::mean()
{
    return sum / data.size();
}

template<typename T>
double Stat<T>::variance()
{
    assert(count != 1 && "at least two element required\n");
    if (count == 1) return;
    return (ssum - sum * sum / double(count - 1)) / double(count - 1);
}

template<typename T>
T Stat<T>::deviation()
{
    //마지막 넘어감
    if (deviation_count == data.size()) {
        deviation_count = 0;
        return;
    }

    static T avr;
    if (deviation_count) {
        avr = mean();
    }
    return data[deviation_count++] - avr;
}

template<typename T>
T Stat<T>::sdeviation()
{
    //마지막 넘어감
    if (sdeviation_count == data.size()) {
        sdeviation_count = 0;
        return;
    }

    static T avr;
    if (sdeviation_count) {
        avr = mean();
    }
    return data[sdeviation_count++] - avr;
    return T();
}

template<typename T>
Stat<T>::~Stat()
{

}
