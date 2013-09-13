// C includes
#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#include <iostream>
#include <vector>

using namespace std;

// prototype for thread routine
void* print(void*);

// structure to hold data passed to a thread
typedef struct thdata_ {
    int number;
} thdata;

int
main(int argc, char **argv) {
    int option;

    // setup default arguments
    int num_threads = 10;

    // process command line options using getopt()
    // see "man 3 getopt"
    while ((option = getopt(argc,argv,"n:")) != -1) {
        switch (option) {
            case 'n':
                num_threads = atoi(optarg);
                break;
            default:
                cout << "server [-p port]" << endl;
                exit(EXIT_FAILURE);
        }
    }

    // initialize random seed:
    srand(time(NULL));

    // keep track of vectors
    std::vector<pthread_t*> threads;
    
    for (int i=0; i<num_threads; i++) {
        // setup thread data
        // notice how each thread needs its own memory!
        pthread_t* thread = new pthread_t;
        thdata* data = new thdata;
        data->number = i+1;

        // create thread
        pthread_create(thread, NULL, &print, (void *) data);
        threads.push_back(thread);
    }

    // wait for threads to terminate.
    for (int i=0; i<num_threads; i++) {
        pthread_join(*threads[i], NULL);
        delete threads[i];
    }
}

void* print(void* ptr) {
    thdata* data;
    data = (thdata*) ptr;

    // generate random number
    float r = (float)rand()/((float)RAND_MAX/5);
    
    // sleep
    sleep(r);
    
    cout << "Thread " << data->number << " says hello." << endl;

    delete data;
    
    pthread_exit(0);
}
