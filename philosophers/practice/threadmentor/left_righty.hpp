//------------------------------------------------------------------------
// Filename:
//   lefty-righty.h
// PROGRAM DESCRIPTION
//   1. Implementation of the left-handed and right-handed philosophers.
//   2. There are n lefty philosophers and 5 - n righty
//      philosophers, where n >=1 and 5-n >= 1.
//   3. n is taken from a command line argument. Philosopher names are
//      lefty0, left1, ..., righty0, right1, ...
//------------------------------------------------------------------------

#ifndef _PHILOSOPHER_H
#define _PHILOSOPHER_H

// header file

#include <thread>

// macro defines

#define PHILOSOPHERS     5

// class definition for philosopher

class Philosopher: public Thread
{
     public:
          Philosopher(int Number, char id, int iter);  // constructor
     private:
          char Id;     // either "lefty" or "righty" philosopher
          int  No;
          int  FirstChopstick,               // the 1st chopstick to pick up
               SecondChopstick;              // the 2nd to pick up
          int  Iteration;
          void ThreadFunc();
};

#endif
