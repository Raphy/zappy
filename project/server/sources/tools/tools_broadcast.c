#include  <math.h>
#include  "tools_broadcast.h"

static const char broadcast_tab[3][3] = {
  {2, 1, 8},
  {3, 0, 7},
  {4, 5, 6}
};

enum e_corner
  {
    MIDDLE = 0,
    UPLEFT = 1,
    UPRIGHT = 2,
    DOWNRIGHT = 3,
    DOWNLEFT = 4
  };

int      tools_get_position(int x1, int x2)
{
  return (x2 == x1 ? (CENTER) : ((x1 < x2) ? (LEFT) : (RIGHT)));
}

int      tools_get_case(int x1, int y1, int x2, int y2)
{
  return (broadcast_tab[tools_get_position(y1, y2)][tools_get_position(x1, x2)]);
}

int      tools_get_distance(int x1, int y1, int x2, int y2)
{
  return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
