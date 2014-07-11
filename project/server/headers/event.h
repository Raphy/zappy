/*
** event.h for zappy in /home/damien/zappy/project/server/headers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Tue Jul  8 14:47:15 2014 damien sauvalle
** Last update Sat Jul 12 01:33:15 2014 damien sauvalle
*/

#ifndef EVENT_H
# define	EVENT_H

#include        "bundle.h"
# include       "player.h"
# include       "tools_timespec.h"

# ifndef	RET_ERROR
#  define	RET_ERROR	-1
# endif /* !RET_ERROR */

# ifndef	RET_SUCCESS
#  define	RET_SUCCESS	0
# endif /* !RET_SUCCESS */

# ifndef	RET_FAILURE
#  define	RET_FAILURE	1
# endif /* !RET_FAILURE */

typedef struct  s_event
{
  void          (*action)();
  t_player      *player;
  void          *data;
  t_timespec    end_time;
  unsigned int  cycle;
}               t_event;

typedef struct  s_bundle_event
{
  void          (*action)();
  t_player      *player;
  void          *data;
  t_timespec    end_time;
  unsigned int  cycle;
}               t_bundle_event;

typedef struct  s_scratch_event
{
  void          (*action)();
  unsigned int  cycle;
}               t_scratch_event;

t_event         *event_new(t_bundle_event *);
void            event_delete(t_event *);
int             event_ctor(t_event *, t_bundle_event *);
int             event_dtor(t_event *);
int             event_create_from_scratch(t_scratch_event *, t_bundle *data);

#endif	/* EVENT_H */
