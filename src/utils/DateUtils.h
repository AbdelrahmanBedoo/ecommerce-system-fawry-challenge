#ifndef DATEUTILS_H
#define DATEUTILS_H
#include <bits/stdc++.h>
using namespace std;

inline time_t makeExpiry(int y, int m, int d) {
    tm tm{};
    tm.tm_year = y - 1900;
    tm.tm_mon  = m - 1;
    tm.tm_mday = d;
    return mktime(&tm);
}

#endif //DATEUTILS_H
