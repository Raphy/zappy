/*
** zc_cmd_bct.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 06:48:33 2014 raphael defreitas
** Last update Sun Jul  6 09:52:06 2014 raphael defreitas
*/

#define		_GNU_SOURCE
#include	<stdbool.h>
#include	<string.h>

#include	"my.h"
#include	"zappy.h"
#include	"_zappy.h"

static bool	parse_position_food(char **ptr, t_bct *bct)
{
  char		*x;
  char		*y;
  char		*food;
  char		*delim;

  x = *ptr;
  y = strchr(x, ' ');
  x[y - x] = 0;
  y++;
  food = strchr(y, ' ');
  y[food - y] = 0;
  food++;
  delim = strchr(food, ' ');
  delim++;
  food[delim - food] = 0;
  if (!my_str_is_numeric(x) || !my_str_is_numeric(y) || !my_str_is_numeric(food))
    return (false);
  bct->position.x = strtoul(x, NULL, 0);
  bct->position.y = strtoul(y, NULL, 0);
  bct->food = strtoul(food, NULL, 0);
  *ptr = delim;
  return (true);
}

static bool	parse(const char *cmd, t_bct *bct)
{
  char		*tmp;
  char		*ptr;
  char		*linemate;
  char		*deraumere;
  char		*sibur;
  char		*mendiane;
  char		*phiras;
  char		*thystame;

  if ((tmp = strdup(cmd + 4)) == NULL)
    return (false);
  ptr = tmp;
  if (!parse_position_food(&ptr, bct))
    {
      free(tmp);
      return (false);
    }
  return (true);
}

bool		zc_cmd_bct(t_zc *this, const char *cmd)
{
  t_bct		bct;

  if (!my_match(cmd, "bct * * * * * * * * *"))
    return (false);
  if (!parse(cmd, &bct))
    return (false);
  printf("bct %u %u %u %u %u %u %u %u %u\n", bct.position.x, bct.position.y,
	 bct.food, bct.linemate, bct.deraumere, bct.sibur, bct.mendiane,
	 bct.phiras, bct.thystame);
  zc_handle_cmd_bct(this, bct);
  return (true);
}
