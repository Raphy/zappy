#include        <stdlib.h>
#include                                           "tools_timespec.h"

void            timespec_sub_double(t_timespec *time1, double time)
{
  time1->tv_sec -= (int)time;
  time1->tv_nsec -= (double)((double)(int)time) * 1000000000.0;
  if (time1->tv_nsec < 0)
  {
    time1->tv_sec--;
    time1->tv_nsec += 1000000000L;
  }
}

void            timespec_sub(t_timespec *time1, t_timespec *time2)
{
  time1->tv_sec -= time2->tv_sec;
  time1->tv_nsec -= time2->tv_nsec;
  if (time1->tv_nsec < 0)
  {
    time1->tv_sec--;
    time1->tv_nsec += 1000000000L;
  }
}
