#ifndef                         TOOLS_TIMESPEC_H
#define                                             	TOOLS_TIMESPEC_H

# include        <sys/time.h>
# include        <time.h>

typedef struct timespec t_timespec;

int             timespec_compare(t_timespec *time1, t_timespec *time2);
t_timespec      timespec_create(double seconds);
void            timespec_add(t_timespec *time1, t_timespec *time2);
void            timespec_sub(t_timespec *time1, t_timespec *time2);
void            timespec_add_double(t_timespec *time1, double time);
void            timespec_sub_double(t_timespec *time1, double time);
double          timespec_double(t_timespec *time);

#endif	                        /* TOOLS_TIMESPEC_H */

