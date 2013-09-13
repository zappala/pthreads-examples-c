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

