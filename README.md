# pthreads examples in C/C++

Simple examples that show how to use the pthreads library in
C/C++. Use

> make

to compile all the code using the supplied `Makefile`. Use

> make clean

to remove object files and

> make realclean

to remove object files and compiled programs.

# Example

The file `example.cc` shows a basic example of how to create a set of
threads to do some computation and then wait for them to finish. Each
thread sleeps a random period of time and then prints out a short
message.

**Caution**: This code does not use any synchronizaiton, so the print
statements from each thread may be jumbled. See subsequent code for
how to do this properly.

# Problem

The file `problem.cc` shows a basic problem that exists when threads
share memory but are not synchronized. Each time you run this code,
the threads should count to a total of 200, but they have different
answer each time.

# Semaphore

The file `semaphore.cc` shows how to use a semaphore to synchronize
access to shared memory.

# Mutex

The file `mutex.cc` shows how to use a mutex to synchronize access to
shared memory.
