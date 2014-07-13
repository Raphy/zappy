/*
** zc_cmd_pin.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 06:48:33 2014 raphael defreitas
** Last update Sun Jul 13 05:35:35 2014 raphael defreitas
*/

#define		_GNU_SOURCE
#include	<stdbool.h>
#include	<stdlib.h>
#include	<string.h>

#include	"my.h"
#include	"zappy.h"
#include	"_zappy.h"

static bool	fill(char **ptr, t_pin *pin)
{
  bool		has_error;

  has_error = false;
  pin->uid = zt_get_next_token(ptr, &has_error);
  pin->position.x = zt_get_next_token(ptr, &has_error);
  pin->position.y = zt_get_next_token(ptr, &has_error);
  pin->items.food = zt_get_next_token(ptr, &has_error);
  pin->items.linemate = zt_get_next_token(ptr, &has_error);
  pin->items.deraumere = zt_get_next_token(ptr, &has_error);
  pin->items.sibur = zt_get_next_token(ptr, &has_error);
  pin->items.mendiane = zt_get_next_token(ptr, &has_error);
  pin->items.phiras = zt_get_next_token(ptr, &has_error);
  pin->items.thystame = zt_get_next_token(ptr, &has_error);
  return (!has_error);
}

static bool	parse(const char *cmd, t_pin *pin)
{
  char		*tmp;
  char		*ptr;

  if ((tmp = strdup(cmd + 4)) == NULL)
    return (false);
  ptr = tmp;
  if (!fill(&ptr, pin))
    {
      free(tmp);
      return (false);
    }
  free(tmp);
  return (true);
}

bool		zc_cmd_pin(t_zc *this, const char *cmd)
{
  t_pin		pin;

  if (!my_match(cmd, "pin * * * * * * * * * *"))
    return (false);
  if (!parse(cmd, &pin))
    return (true);
  zc_handle_cmd_pin(this, &pin);
  return (true);
}
