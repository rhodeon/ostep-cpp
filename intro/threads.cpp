#include <iostream>
#include <cstdlib>
#include <pthread.h>

volatile int counter = 0;
int loops;

void *worker(void *arg) {
    int i;
    for (i = 0; i < loops; i++) {
        counter++;
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "usage: threads <loops>" << std::endl;
        exit(1); 
    }

    loops = atoi(argv[1]);
    pthread_t p1;
    pthread_t p2;
    std::cout << "Initial value : " << counter << std::endl;

    pthread_create(&p1, NULL, worker, NULL);
    pthread_create(&p2, NULL, worker, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    std::cout << "Final value : " << counter << std::endl;

    return 0;
}