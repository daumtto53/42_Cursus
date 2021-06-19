//------------------------------------------------------------------------
// Filename:
//     Lefty-righty.cpp
// PROGRAM DESCRIPTION
//     A program uses mutex to solve the dining philosophers problem.
//     This  program assumes some philosophers are lefties (i.e., picking
//     up his left chopstick first) and at least one righty (i.e., picking
//     up his right chopstick first).  Thus, if there are n lefty
//     philosophers, then 0 < 5 < n must hold.  Note that this version
//     will not cause deadlock.
//------------------------------------------------------------------------

#include <iostream>

#include "lefty_righty.h"

// extern global variables

extern Mutex *Chopstick[PHILOSOPHERS];

// -----------------------------------------------------------------------
// FUNCTION  Filler():
//    This function fills a strstream with spaces.
// -----------------------------------------------------------------------

strstream *Filler(int n)
{
     int  i;
     strstream *Space;

     Space = new strstream;
     for (i = 0; i < n; i++)
          (*Space) << ' ';
     (*Space) << '\0';
     return Space;
}

//------------------------------------------------------------------------
// Philosopher::Philosopher()
//     constructor
//------------------------------------------------------------------------

Philosopher::Philosopher(int Number, char id, int iter)
            : No(Number), Id(id), Iteration(iter)
{
     ThreadName.seekp(0, ios::beg);
     if (Id == 'L') {         // lefties have No followed No+1
          ThreadName << "Lefty" << Number + 1 << '\0';
          FirstChopstick  = No;
          SecondChopstick = (No + 1) % PHILOSOPHERS;
     }
     else {                   // righties have No+1 followed by No
          ThreadName << "Righty" << Number + 1 << '\0';
          FirstChopstick  =  (No + 1) % PHILOSOPHERS;
          SecondChopstick = No;
     }
}

//------------------------------------------------------------------------
// Philosopher::ThreadFunc()
//      implement the thread body of a Philosopher thread
//------------------------------------------------------------------------

void Philosopher::ThreadFunc()
{
     Thread::ThreadFunc();
     strstream *Space;
     int i;

     Space = Filler(No*2);
     for (i = 0; i < Iteration; i++) {
          Delay();
          Chopstick[FirstChopstick]->Lock();
          Chopstick[SecondChopstick]->Lock();     // gets two chopsticks
          cout << Space->str() << ThreadName.str() << " begin eating." << endl;
          Delay();
          cout << Space->str() << ThreadName.str() << " finish eating." << endl;
          Chopstick[FirstChopstick]->Unlock();    // release 2 chopstick
          Chopstick[SecondChopstick]->Unlock();
     }
     Exit(); // thread terminates
}

// end of lefty-righty.cpp file
