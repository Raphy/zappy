/*
** tools_broadcast.h for zappy in /home/damien/zappy/project/server/headers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jul 13 11:16:04 2014 damien sauvalle
** Last update Sun Jul 13 11:16:33 2014 damien sauvalle
*/

#ifndef		TOOLS_BROADCAST_H
# define	TOOLS_BROADCAST_H

enum e_position
{
  LEFT = 0,
  CENTER = 1,
  RIGHT = 2
};

int	tools_get_position(int x1, int x2);
int	tools_get_case(int x1, int y1, int x2, int y2);
int	tools_get_distance(int x1, int y1, int x2, int y2);

#endif	/* !TOOLS_BROADCAST_H */
