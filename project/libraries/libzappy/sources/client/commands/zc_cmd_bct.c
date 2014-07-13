/*
** zc_cmd_bct.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 06:48:33 2014 raphael defreitas
** Last update Sun Jul 13 05:37:53 2014 raphael defreitas
*/

#define		_GNU_SOURCE
#include	<stdbool.h>
#include	<stdlib.h>
#include	<string.h>

#include	"my.h"
#include	"zappy.h"
#include	"_zappy.h"

static bool	fill(char **ptr, t_bct *bct)
{
  bool		has_error;

  has_error = false;
  bct->position.x = zt_get_next_token(ptr, &has_error);
  bct->position.y = zt_get_next_token(ptr, &has_error);
  bct->items.food = zt_get_next_token(ptr, &has_error);
  bct->items.linemate = zt_get_next_token(ptr, &has_error);
  bct->items.deraumere = zt_get_next_token(ptr, &has_error);
  bct->items.sibur = zt_get_next_token(ptr, &has_error);
  bct->items.mendiane = zt_get_next_token(ptr, &has_error);
  bct->items.phiras = zt_get_next_token(ptr, &has_error);
  bct->items.thystame = zt_get_next_token(ptr, &has_error);
  return (!has_error);
}

static bool	parse(const char *cmd, t_bct *bct)
{
  char		*tmp;
  char		*ptr;

  if ((tmp = strdup(cmd + 4)) == NULL)
    return (false);
  ptr = tmp;
  if (!fill(&ptr, bct))
    {
      free(tmp);
      return (false);
    }
  free(tmp);
  return (true);
}

bool		zc_cmd_bct(t_zc *this, const char *cmd)
{
  t_bct		bct;

  if (!my_match(cmd, "bct * * * * * * * * *"))
    return (false);
  if (!parse(cmd, &bct))
    return (true);
  zc_handle_cmd_bct(this, &bct);
  return (true);
}
