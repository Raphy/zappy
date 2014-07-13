/* 
 * File:   tools_broadcast.h
 * Author: svirch_n
 *
 * Created on July 12, 2014, 2:13 PM
 */

#ifndef TOOLS_BROADCAST_H
# define	TOOLS_BROADCAST_H

enum e_position
{
  LEFT = 0,
  CENTER = 1,
  RIGHT = 2
};

int      tools_get_position(int x1, int x2);
int      tools_get_case(int x1, int y1, int x2, int y2);
int      tools_get_distance(int x1, int y1, int x2, int y2);

#endif	/* TOOLS_BROADCAST_H */

