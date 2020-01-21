#ifndef __common_h__
#define __common_h__

#include <sys/time.h>   // timeval, gettimeofday()
#include <cassert>      // assert
#include <cstddef>      // NULL

double GetTime() {
    struct timeval t;
    int rc = gettimeofday(&t, NULL);
    assert(rc == 0);
    return (double) t.tv_sec + (double) t.tv_usec/1e6;      // make microsecond negligible
}

void Spin(int howlong) {
    double t = GetTime();
    while ((GetTime() - t) < (double) howlong)
	; // do nothing in loop
}

#endif // __common_h__
