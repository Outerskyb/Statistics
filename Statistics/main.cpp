#include <iostream>
#include "Data.h"
#include "util.h"
#include <random>

using namespace std;

int main()
{
    Data<double> s1;
    Data<double> s2;
    s1 << 70 << 92 << 80 << 74 << 65 << 83;
    s2 << 74 << 84 << 63 << 87 << 78 << 90;
    cov<double>(s1, s2);
}