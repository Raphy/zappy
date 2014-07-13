/*
** tools_timespec.h for zappy in /home/damien/zappy/project/server/headers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jul 13 11:16:53 2014 damien sauvalle
** Last update Sun Jul 13 11:17:50 2014 damien sauvalle
*/

#ifndef		TOOLS_TIMESPEC_H
#define		TOOLS_TIMESPEC_H

# include	<sys/time.h>
# include	<time.h>

typedef struct	timespec t_timespec;

int		timespec_compare(t_timespec *time1, t_timespec *time2);
t_timespec	timespec_create(double seconds);
void		timespec_add(t_timespec *time1, t_timespec *time2);
void		timespec_sub(t_timespec *time1, t_timespec *time2);
void		timespec_add_double(t_timespec *time1, double time);
void		timespec_sub_double(t_timespec *time1, double time);
t_timespec	timespec_create_sub(t_timespec *time1, t_timespec *time2);
double		timespec_double(t_timespec *time);

#endif	/* !TOOLS_TIMESPEC_H */
