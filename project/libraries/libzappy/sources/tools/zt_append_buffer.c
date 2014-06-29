/*
** zt_append_buffer.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jun 28 23:07:16 2014 raphael defreitas
** Last update Sun Jun 29 00:39:38 2014 raphael defreitas
*/

#define		_GNU_SOURCE
#include	<stdlib.h>
#include	<string.h>

#include	"list.h"

static int	simple(t_list *pckts, const char *buf)
{
  char		*tmp;

  if ((tmp = strdup(buf)) == NULL ||
      list_enqueue(pckts, tmp) == RET_FAILURE)
    {
      free(tmp);
      return (RET_FAILURE);
    }
  return (RET_SUCCESS);
}

static int	splited(t_list *pckts, const char *buf, const char *split)
{
  char		*before;
  char		*after;

  before = NULL;
  after = NULL;
  if ((before = strdup(buf)) != NULL)
    before[split - buf + 1] = '\0';
  if (*(split + 1) != '\0')
    after = strdup(split + 1);
  if (before == NULL || (*(split + 1) != '\0' && after == NULL) ||
      list_enqueue(pckts, before) == RET_FAILURE ||
      (*(split + 1) != '\0' && list_enqueue(pckts, after) == RET_FAILURE))
    {
      free(before);
      free(after);
      return (RET_FAILURE);
    }
  return (RET_SUCCESS);
}

int		zt_append_buffer(t_list *pckts, const char *buf)
{
  char		*tmp;
  int		ret;

  if ((tmp = strchr(buf, '\n')) == NULL)
    ret = simple(pckts, buf);
  else
    ret = splited(pckts, buf, tmp);
  return (ret);
}
