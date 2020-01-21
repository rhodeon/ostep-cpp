#include <iostream>     // std::cerr, std::cout
#include <cstdlib>      // exit()
#include "common.h"     // Spin()

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "usage: cput<string>" << std::endl;
        exit(1);
    }

    char *str = argv[1];
    
    while (1) {
        std::cout << str << std::endl;
        Spin(1);
    }
    return 0;
}