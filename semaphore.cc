// Taken from Unix Network Programming: The Sockets Networking API, Volume 1,
// Third Edition, by W. Richard Stevens, Bill Fenner, and Andrew M. Rudoff

// Page 700

// This program demonstrates how to use a semaphore to solve the
// synchronization problem.

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <iostream>

using namespace std;

struct count {
    int counter;
    sem_t sem;
};

void *doit(void *);

int
main(int argc, char **argv)
{
    pthread_t tidA, tidB;
    // counter in shared memory
    struct count c;

    // initialize semaphore
    sem_init(&c.sem,0,1);

    c.counter = 0;
    srandom(1000);

    // create two threads
    pthread_create(&tidA, NULL, &doit, &c);
    pthread_create(&tidB, NULL, &doit, &c);

    // wait for both threads to terminate
    pthread_join(tidA, NULL);
    pthread_join(tidB, NULL);
  
    exit(0);
}

void *
doit(void *vptr)
{
    int i, val;
    long r;
    struct count* c;

    c = (struct count*) vptr;
    
    // Each thread fetches, prints, and increments the counter 100 times.
    // We use sleep to represent work being done in the meantime.
    for (i = 0; i < 100; i++) {
        sem_wait(&c->sem);
        val = c->counter;
        r = random() % 100;
        usleep(r);
        cout << pthread_self() << " " << val + 1 << endl;
        c->counter = val + 1;
        sem_post(&c->sem);
        r = random() % 100;
        usleep(r);
    }
}
