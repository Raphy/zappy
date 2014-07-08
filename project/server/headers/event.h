/*
** event.h for zappy in /home/damien/zappy/project/server/headers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Tue Jul  8 14:47:15 2014 damien sauvalle
** Last update Tue Jul  8 14:47:17 2014 damien sauvalle
*/

#ifndef EVENT_H
# define	EVENT_H

# include       "player.h"
# include   <time.h>

typedef struct  s_event
{
  int end_time;
  void          (*action)();
  t_player      *player;
  void          *data;
}               t_event;

#endif	/* EVENT_H */
