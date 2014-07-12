#include        <stdlib.h>
#include                                           "tools_timespec.h"

/*
** time1 is:
** -1 = lower than time2
** 0 = equal than time2
** 1 = greater than time2
*/

int             timespec_compare(t_timespec *time1, t_timespec *time2)
{
  if (time1 == NULL || time2 == NULL)
    return (0);
  if ((int)time1->tv_sec < (int)time2->tv_sec)
    return (-1);
  else if (time1->tv_sec > time2->tv_sec)
    return (1);
  else if (time1->tv_nsec < time2->tv_nsec)
    return (-1);
  else if (time1->tv_nsec > time2->tv_nsec)
    return (1);
  else
    return (0);
}

t_timespec      timespec_create(double seconds)
{
  t_timespec    result;
  
  result.tv_sec = seconds;
  result.tv_nsec = ((seconds - (double) result.tv_sec) * 1000000000.0);
  return (result);
}

double          timespec_double(t_timespec *time)
{
  return (time->tv_sec + (time->tv_nsec / 1000000000.0));
}

void            timespec_add(t_timespec *time1, t_timespec *time2)
{
  time1->tv_sec += time2->tv_sec;
  time1->tv_nsec += time2->tv_nsec;
  if (time1->tv_nsec >= 1000000000L)
  {
    time1->tv_sec++;
    time1->tv_nsec -= 1000000000L;
  }
}

void            timespec_add_double(t_timespec *time1, double time)
{
  time1->tv_sec += (int)time;
  time1->tv_nsec += (double)(time - (double)(int)time) * 1000000000.0;
  if (time1->tv_nsec >= 1000000000L)
  {
    time1->tv_sec++;
    time1->tv_nsec -= 1000000000L;
  }
}