/*
** zt_build_command.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sat Jun 28 22:34:06 2014 raphael defreitas
** Last update Thu Jul 10 07:19:51 2014 raphael defreitas
*/

#define		_GNU_SOURCE
#include	<stdbool.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

#include	"list.h"

static int	split(t_list *pckts, t_list *frags, char *frag)
{
  char		*delim;
  char		*to_save;
  char		*to_build;

  delim = strchr(frag, '\n');
  to_save = NULL;
  to_build = NULL;
  if ((to_build = strndup(frag, delim - frag + 1)) == NULL ||
      (*(delim + 1) != 0 && (to_save = strdup(delim + 1)) == NULL) ||
      (to_save != NULL && list_push(pckts, to_save) == RET_FAILURE) ||
      list_enqueue(frags, to_build) == RET_FAILURE)
    {
      free(frag);
      free(to_save);
      free(to_build);
      return (RET_FAILURE);
    }
  free(frag);
  return (RET_SUCCESS);
}

static int	clean_return(char *frag, char **cmd)
{
  free(frag);
  free(*cmd);
  *cmd = NULL;
  return (RET_FAILURE);
}

static int	build(t_list *frags, char **cmd)
{
  char		*frag;

  *cmd = NULL;
  while ((frag = list_pop(frags)))
    {
      if (*cmd == NULL)
	{
	  if ((*cmd = strdup(frag)) == NULL)
	    return (clean_return(frag, cmd));
	}
      else
	{
	  if ((*cmd = realloc(*cmd, (strlen(*cmd) + strlen(frag) + 1))) == NULL)
	    return (clean_return(frag, cmd));
	  if (strcat(*cmd, frag) == NULL)
	    return (clean_return(frag, cmd));
	}
      free(frag);
    }
  (*cmd)[strlen(*cmd) - 1] = 0;
  return (RET_SUCCESS);
}

int		zt_build_command(t_list *pckts, char **cmd)
{
  t_list	frags;
  char		*frag;
  bool		failure;

  failure = false;
  list_ctor(&frags, &free);
  while (!failure && (frag = list_pop(pckts)))
    {
      if (strchr(frag, '\n'))
	{
	  if (split(pckts, &frags, frag) == RET_FAILURE ||
	      build(&frags, cmd) == RET_FAILURE)
	    failure = true;
	  break;
	}
      else if (list_enqueue(&frags, frag) == RET_FAILURE)
	failure = true;
    }
  while ((frag = list_dequeue(&frags)))
    list_push(pckts, frag);
  list_dtor(&frags);
  return (failure ? RET_FAILURE : RET_SUCCESS);
}
