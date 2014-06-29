/*
** errno_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:33:33 2014 raphael defreitas
** Last update Sun Jun 29 02:12:36 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<string.h>

#include	"zappy.h"

void		errno_handler(__attribute__((unused))t_zs *zs,
			      int err, const char *msg,
			      __attribute__((unused))void *data)
{
  fprintf(stderr, "[ERROR] ");
  if (err == 0 && msg == NULL)
    fprintf(stderr, "Unknown error");
  else if (err == 0 && msg != NULL)
    fprintf(stderr, "%s", msg);
  else if (err != 0 && msg == NULL)
    fprintf(stderr, "%s", strerror(err));
  else
    fprintf(stderr, "%s (%s)", strerror(err), msg);
  fprintf(stderr, " (code: %d)\n", err);
}
