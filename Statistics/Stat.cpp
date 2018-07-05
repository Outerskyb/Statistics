#include "Stat.h"


template<typename T>
Stat<T>::Stat()
{

}

template<typename T>
void Stat<T>::operator<<(T datum){
    data.push_back(datum);
}

template<typename T>
Stat<T>::~Stat()
{

}
