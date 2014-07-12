/*
** zc_cmd_pic.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 06:48:33 2014 raphael defreitas
** Last update Sat Jul 12 12:16:29 2014 raphael defreitas
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

static unsigned int	count_elems(char **ptr)
{
  unsigned int		c;
  unsigned int		i;

  c = 1;
  i = 0;
  while ((*ptr)[i])
    {
      if ((*ptr)[i] == ' ')
	c++;
      i++;
    }
  return (c);
}

static bool	fill(char **ptr, t_pic *pic)
{
  bool		has_error;
  unsigned int	i;
  unsigned int	uid;
  unsigned int	*uids;

  has_error = false;
  pic->position.x = get_next_token(ptr, &has_error);
  pic->position.y = get_next_token(ptr, &has_error);
  pic->level = get_next_token(ptr, &has_error);
  pic->nb_uids = count_elems(ptr);
  if ((uids = calloc(pic->nb_uids, sizeof(unsigned int))) == NULL)
    return (false);
  i = 0;
  while (!has_error && (uid = get_next_token(ptr, &has_error)) != 0)
    {
      uids[i] = uid;
      i++;
    }
  return (has_error);
}

static bool	parse(const char *cmd, t_pic *pic)
{
  char		*tmp;
  char		*ptr;

  if ((tmp = strdup(cmd + 4)) == NULL)
    return (false);
  ptr = tmp;
  if (!fill(&ptr, pic))
    {
      free(tmp);
      return (false);
    }
  free(tmp);
  return (true);
}

bool		zc_cmd_pic(t_zc *this, const char *cmd)
{
  t_pic		pic;

  if (!my_match(cmd, "pic * * * *"))
    return (false);
  pic.uids = NULL;
  if (!parse(cmd, &pic))
    return (true);
  zc_handle_cmd_pic(this, &pic);
  free(pic.uids);
  return (true);
}
