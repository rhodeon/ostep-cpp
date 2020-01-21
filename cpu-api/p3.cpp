#include <iostream>     // std::cout, std::endl, std::cerr
#include <cstdlib>      // exit(), NULL
#include <unistd.h>     // fork(), getpid()
#include <sys/wait.h>   // wait()
#include <cstring>      // strdup()

int main(int argc, const char** argv) {
    std::cout << "hello world (pid:" << (int) getpid() << ")" << std::endl;
    int rc = fork();
    
    if (rc < 0) {
        // fork failed; exit
        std::cerr << "fork failed" << std::endl;
        exit(1);
    }

    else if (rc == 0) {
        // child (new process)
        std::cout << "hello I am child (pid:" << (int) getpid() << ")" << std::endl;
        char *myargs[3];
        myargs[0] = strdup("wc"); 
        myargs[1] = strdup("p3.cpp");
        myargs[2] = NULL;

        execvp(myargs[0], myargs);
        std::cout << "this shouldn't print out" << std::endl;
    }

    else {
        // parent goes down this path (original process)
        int wc = wait(NULL);
        std::cout << "hello, I am parent of " << rc << " (wc:" << wc << ")" << "(pid:" << (int) getpid() << ")" << std::endl;
    }
    return 0;
}