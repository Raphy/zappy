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
# include       "tools_timespec.h"

typedef struct  s_event
{
  void          (*action)();
  t_player      *player;
  void          *data;
  t_timespec    end_time;
}               t_event;

#endif	/* EVENT_H */
