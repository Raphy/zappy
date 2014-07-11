/*
** remote_errno_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/remote/sources/remote/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 20:02:10 2014 raphael defreitas
** Last update Sun Jun 29 20:18:21 2014 raphael defreitas
*/

#include	<stdio.h>
#include	<string.h>

#include	"zappy.h"

void		remote_errno_handler(__attribute__((unused))t_zc *zc,
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
