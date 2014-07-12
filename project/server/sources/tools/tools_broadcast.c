#include  <math.h>
#include  "tools_broadcast.h"

static const char broadcast_tab[3][3] = {
  {1, 2, 3},
  {4, 5, 6},
  {7, 8, 9}
};

int      tools_getPosition(int x1, int x2)
{
  return (x2 == x1 ? (CENTER) : ((x1 < x2) ? (LEFT) : (RIGHT)));
}

int      tools_getCase(int x1, int y1, int x2, int y2)
{
  return (broadcast_tab[tools_getPosition(y1, y2)][tools_getPosition(x1, x2)]);
}

int      tools_getDistance(int x1, int y1, int x2, int y2)
{
  return (sqrt(((x2 * x2) - (2 * x2 * x1) + (x1 * x1))
          + ((y2 * y2) - (2 * y2 * y1) + (y1 * y1))));
}
