#include        <stdlib.h>
#include                                           "tools_timespec.h"

/*
** time1 is:
** -1 = lower
** 0 = equal
** 1 = greater
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