#ifndef                         TOOLS_TIMESPEC_H
#define                                             	TOOLS_TIMESPEC_H

# include        <sys/time.h>
# include        <time.h>

typedef struct timespec t_timespec;

int             timespec_compare(t_timespec *time1, t_timespec *time2);
t_timespec      timespec_create(double seconds);

#endif	                        /* TOOLS_TIMESPEC_H */

