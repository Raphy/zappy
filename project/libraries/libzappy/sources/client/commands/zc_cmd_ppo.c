/*
** zc_cmd_ppo.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 06:48:33 2014 raphael defreitas
** Last update Thu Jul 10 03:19:22 2014 raphael defreitas
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

static bool	fill(char **ptr, t_ppo *ppo)
{
  bool		has_error;

  has_error = false;
  ppo->uid = get_next_token(ptr, &has_error);
  ppo->position.x = get_next_token(ptr, &has_error);
  ppo->position.y = get_next_token(ptr, &has_error);
  ppo->orientation = get_next_token(ptr, &has_error);
  return (has_error);
}

static bool	parse(const char *cmd, t_ppo *ppo)
{
  char		*tmp;
  char		*ptr;

  if ((tmp = strdup(cmd + 4)) == NULL)
    return (false);
  ptr = tmp;
  if (!fill(&ptr, ppo))
    {
      free(tmp);
      return (false);
    }
  free(tmp);
  return (true);
}

bool		zc_cmd_ppo(t_zc *this, const char *cmd)
{
  t_ppo		ppo;

  if (!my_match(cmd, "ppo * * * *"))
    return (false);
  if (!parse(cmd, &ppo))
    return (false);
  zc_handle_cmd_ppo(this, &ppo);
  return (true);
}