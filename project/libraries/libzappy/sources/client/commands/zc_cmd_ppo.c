/*
** zc_cmd_ppo.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 06:48:33 2014 raphael defreitas
** Last update Sun Jul 13 05:36:50 2014 raphael defreitas
*/

#define		_GNU_SOURCE
#include	<stdbool.h>
#include	<stdlib.h>
#include	<string.h>

#include	"my.h"
#include	"zappy.h"
#include	"_zappy.h"

static bool	fill(char **ptr, t_ppo *ppo)
{
  bool		has_error;

  has_error = false;
  ppo->uid = zt_get_next_token(ptr, &has_error);
  ppo->position.x = zt_get_next_token(ptr, &has_error);
  ppo->position.y = zt_get_next_token(ptr, &has_error);
  ppo->orientation = zt_get_next_token(ptr, &has_error);
  return (!has_error);
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
    return (true);
  zc_handle_cmd_ppo(this, &ppo);
  return (true);
}
