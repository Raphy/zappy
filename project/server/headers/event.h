/* 
 * File:   event.h
 * Author: svirch_n
 *
 * Created on 02 July 2014, 16:06
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

