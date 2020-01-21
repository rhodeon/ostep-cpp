#include <unistd.h>     // getpid()
#include <iostream>     // std::cout, std::cerr
#include <cstdlib>      // atoi(), exit()
#include "common.h"     // Spin()

int main (int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "usage: mem <value>" << std::endl;
        exit(1); 
    }
    
    int *p;
    p = new int((sizeof(int)));
    assert(p != NULL); 

    std::cout << "(" << getpid() << ") address pointed to by p: " << p << std::endl;
    *p = atoi(argv[1]);     // assign value to addr stored in p

    while(1) {
        Spin(1);
        *p = *p + 1;
        std::cout << "(" << getpid() << ") value of p: " << *p << std::endl;
    }

    return 0;
}