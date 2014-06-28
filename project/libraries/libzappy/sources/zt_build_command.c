/*
** zt_build_command.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jun 28 22:34:06 2014 raphael defreitas
** Last update Sun Jun 29 00:36:39 2014 raphael defreitas
*/

#define		_GNU_SOURCE
#include	<stdlib.h>
#include	<string.h>

#include	"list.h"

static int	build_error(t_list *build, char *frag, char **cmd)
{
  free(*cmd);
  *cmd = NULL;
  list_push(build, frag);
  return (RET_FAILURE);
}

static void	clean_the_shit_my_nigger(char **cmd)
{
  size_t	len;

  if (*cmd == NULL)
    return ;
  len = strlen(*cmd);
  if (len == 0 || (*cmd)[0] == '\n' || (*cmd)[0] == '\0')
    {
      free(*cmd);
      *cmd = NULL;
    }
  else if ((*cmd)[len - 1] == '\n')
    (*cmd)[len - 1] = '\0';
}

static int	build_that_shit(t_list *build, char **cmd)
{
  char		*frag;

  while ((frag = list_pop(build)))
    {
      if (*cmd == NULL)
	{
	  if ((*cmd = strdup(frag)) == NULL)
	    return (build_error(build, frag, cmd));
	}
      else
	{
	  *cmd = realloc(*cmd, (strlen(*cmd) + strlen(frag) + 1) * sizeof(char));
	  if (*cmd == NULL)
	    return (build_error(build, frag, cmd));
	  if (strcat(*cmd, frag) == NULL)
	    return (build_error(build, frag, cmd));
	}
      free(frag);
    }
  clean_the_shit_my_nigger(cmd);
  return (RET_SUCCESS);
}

static void	restore(t_list *pckts, t_list *build)
{
  char		*frag;

  while ((frag = list_dequeue(build)))
    list_push(pckts, frag);
}

int		zt_build_command(t_list *pckts, char **cmd)
{
  char		*frag;
  t_list	build;
  int		ret;

  list_ctor(&build, NULL);
  while ((frag = list_pop(pckts)))
    {
      if ((list_enqueue(&build, frag) == RET_FAILURE))
	{
	  list_dtor(&build);
	  return (RET_FAILURE);
	}
      if (strchr(frag, '\n'))
	{
	  ret = build_that_shit(&build, cmd);
	  restore(pckts, &build);
	  list_dtor(&build);
	  return (ret);
	}
    }
  restore(pckts, &build);
  list_dtor(&build);
  return (RET_SUCCESS);
}
