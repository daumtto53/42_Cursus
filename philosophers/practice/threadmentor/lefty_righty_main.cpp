//------------------------------------------------------------------------
// Filename:
//     Lefty-righty-main.cpp
// PROGRAM DESCRIPTION
//     This is the program that uses mutex to solve the dining philosophers
//     problem.  We assume that there are n lefty philosophers and 5 - n
//     righty philosophers, where n >=1 and 5-n >= 1, so that possible
//     deadlock can be prevented.
//------------------------------------------------------------------------

#include <iostream>
#include <stdlib.h>

#include "lefty_righty.h"

// global variables

Mutex *Chopstick[PHILOSOPHERS];

//------------------------------------------------------------------------
// main() function
//------------------------------------------------------------------------

int main(int argc, char *argv[])
{
     Philosopher *philosopher[PHILOSOPHERS];
     int i;
     int n;
     int Iteration;
     strstream name;

     if (argc != 3) {
          cout << "Usage " << argv[0] << " #-of-lefty " <<
                  " #-of-iterations." << endl;
          exit(-1);
     }
     else {
          n = abs(atoi(argv[1]));
          if (n >=  PHILOSOPHERS)  {  // make sure # of lefties are valid
               cout  <<  "The number of lefty philosophers MUST be less than "
                     << PHILOSOPHERS << endl;
               exit(-1);
          }
          Iteration = abs(atoi(argv[2]));
     }

     // initialize chopstick mutexs
     for (i = 0; i < PHILOSOPHERS; i++) {
          name.seekp(0, ios::beg);
          name << "ChopStick" << i << '\0';
          Chopstick[i] = new Mutex(name.str());
     }

     // fire up both righty and lefty philosophers threads
     for (i = 0; i < PHILOSOPHERS; i++) {
          if (i < n)  // it's a lefty philosopher
               philosopher[i] = new Philosopher(i, 'L', Iteration);
          else        // it's a righty philosopher
               philosopher[i] = new Philosopher(i, 'R', Iteration);
          philosopher[i]->Begin();
     }

     // wait for all philosopher threads
     for (i=0; i < PHILOSOPHERS; i++)
          philosopher[i]->Join();
     Exit();

     return 0;
}
