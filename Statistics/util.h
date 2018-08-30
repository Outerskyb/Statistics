#pragma once
#include "Data.h"
template <typename T>
T cov(Data<T>& d1, Data<T>& d2) {
    d1.deviation_init();
    d2.deviation_init();
    T dev_sum = 0;
    for (int i = 0; i < d1.Count(); i++) {
        T dev = d1.deviation();
        for (int j = 0; j < d2.Count(); j++) {
            dev_sum += dev*d2.deviation();
        }
    }
    return dev_sum / (d1.Count()*d2.Count());
}
template <typename T>
T correlation(Data<T> d1, Data<T> d2) {
    return cov<T>(d1, d2) / sqrt(d1.variance()*d2.variance());
}