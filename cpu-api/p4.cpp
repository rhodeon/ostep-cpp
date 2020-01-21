#include <iostream>     // std::cout, std::endl, std::cerr
#include <cstdlib>      // exit(), NULL
#include <unistd.h>     // fork(), getpid()
#include <sys/wait.h>   // wait()
#include <cstring>      // strdup()
#include <fcntl.h>      // open(), close()
#include <cassert>      // assert

int main(int argc, const char** argv) {
    int rc = fork();
    
    if (rc < 0) {
        // fork failed; exit
        std::cerr << "fork failed" << std::endl;
        exit(1);
    }

    else if (rc == 0) {
        // child: redirect standard output to a file
        close(STDOUT_FILENO);
        open("./p4.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);

        // now exec "wc"
        char *myargs[3];
        myargs[0] = strdup("wc"); 
        myargs[1] = strdup("p4.cpp");
        myargs[2] = NULL;
        execvp(myargs[0], myargs);
    }

    else {
        // parent goes down this path (original process)
        int wc = wait(NULL);
        assert(wc >= 0);
    }
    return 0;
}