/*
** zc_cmd_pie.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 06:48:33 2014 raphael defreitas
** Last update Sun Jul 13 05:39:00 2014 raphael defreitas
*/

#define		_GNU_SOURCE
#include	<stdbool.h>
#include	<stdlib.h>
#include	<string.h>

#include	"my.h"
#include	"zappy.h"
#include	"_zappy.h"

static bool	fill(char **ptr, t_pie *pie)
{
  bool		has_error;
  unsigned int	result;
  has_error = false;
  pie->position.x = zt_get_next_token(ptr, &has_error);
  pie->position.y = zt_get_next_token(ptr, &has_error);
  result = zt_get_next_token(ptr, &has_error);
  pie->result = result == 0 ? false : true;
  return (!has_error);
}

static bool	parse(const char *cmd, t_pie *pie)
{
  char		*tmp;
  char		*ptr;

  if ((tmp = strdup(cmd + 4)) == NULL)
    return (false);
  ptr = tmp;
  if (!fill(&ptr, pie))
    {
      free(tmp);
      return (false);
    }
  free(tmp);
  return (true);
}

bool		zc_cmd_pie(t_zc *this, const char *cmd)
{
  t_pie		pie;

  if (!my_match(cmd, "pie * * *"))
    return (false);
  if (!parse(cmd, &pie))
    return (true);
  zc_handle_cmd_pie(this, &pie);
  return (true);
}
