/*
** zc_cmd_bct.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 06:48:33 2014 raphael defreitas
** Last update Mon Jul  7 18:03:08 2014 raphael defreitas
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

static bool	fill(char **ptr, t_bct *bct)
{
  bool		has_error;

  has_error = false;
  bct->position.x = get_next_token(ptr, &has_error);
  bct->position.y = get_next_token(ptr, &has_error);
  bct->food = get_next_token(ptr, &has_error);
  bct->linemate = get_next_token(ptr, &has_error);
  bct->deraumere = get_next_token(ptr, &has_error);
  bct->sibur = get_next_token(ptr, &has_error);
  bct->mendiane = get_next_token(ptr, &has_error);
  bct->phiras = get_next_token(ptr, &has_error);
  bct->thystame = get_next_token(ptr, &has_error);
  return (has_error);
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
  return (true);
}

bool		zc_cmd_bct(t_zc *this, const char *cmd)
{
  t_bct		bct;

  if (!my_match(cmd, "bct * * * * * * * * *"))
    return (false);
  if (!parse(cmd, &bct))
    return (false);
  zc_handle_cmd_bct(this, &bct);
  return (true);
}
