/*
** zc_cmd_pin.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 06:48:33 2014 raphael defreitas
** Last update Fri Jul 11 20:15:51 2014 raphael defreitas
*/

#define		_GNU_SOURCE
#include	<stdbool.h>
#include	<stdlib.h>
#include	<string.h>

#include	"my.h"
#include	"zappy.h"
#include	"_zappy.h"

static unsigned int get_next_token(char **ptr, bool *has_error)
{
  char		*tok;
  char		*end;
  unsigned int	res;

  if (*has_error)
    return (0);
  tok = *ptr;
  end = strchr(tok, ' ');
  if (end == NULL)
    {
      *has_error = true;
      return (0);
    }
  tok[end - tok] = 0;
  end++;
  *ptr = end;
  if (!my_str_is_numeric(tok))
    {
      *has_error = true;
      return (0);
    }
  res = strtoul(tok, NULL, 0);
  return (res);
}

static bool	fill(char **ptr, t_pin *pin)
{
  bool		has_error;

  has_error = false;
  pin->uid = get_next_token(ptr, &has_error);
  pin->position.x = get_next_token(ptr, &has_error);
  pin->position.y = get_next_token(ptr, &has_error);
  pin->items.food = get_next_token(ptr, &has_error);
  pin->items.linemate = get_next_token(ptr, &has_error);
  pin->items.deraumere = get_next_token(ptr, &has_error);
  pin->items.sibur = get_next_token(ptr, &has_error);
  pin->items.mendiane = get_next_token(ptr, &has_error);
  pin->items.phiras = get_next_token(ptr, &has_error);
  pin->items.thystame = get_next_token(ptr, &has_error);
  return (has_error);
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
