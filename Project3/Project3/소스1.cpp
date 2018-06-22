#include <windows.h>
#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{


  LARGE_INTEGER ticksPerSecond;
  LARGE_INTEGER tick;   // A point in time
  LARGE_INTEGER time;   // For converting tick into real time




  // get the high resolution counter's accuracy
  QueryPerformanceFrequency(&ticksPerSecond); 

  // what time is it? (not the local time)
  QueryPerformanceCounter(&tick);

  //printf ("\n Ticks par seconde = %ld",ticksPerSecond.QuadPart);

  // convert the tick number into the number of seconds
  // since the system was started...
  time.QuadPart = tick.QuadPart/ticksPerSecond.QuadPart;


  //get the number of hours
  int hours = time.QuadPart/3600;

  //get the number of minutes
  time.QuadPart = time.QuadPart - (hours * 3600);
  int minutes = time.QuadPart/60;

  //get the number of seconds
  int seconds = time.QuadPart - (minutes * 60);

  double ticks_per_micro= (double)ticksPerSecond.QuadPart/1000000;
  //printf ("\n div = %f",ticks_per_micro);

  //get the number of Microseconds
  double microSecondes = (double)((tick.QuadPart % ticksPerSecond.QuadPart) / ticks_per_micro);

  printf ("\n The system was started %d:%d:%d::%.11f",hours, minutes, seconds, microSecondes);


  }