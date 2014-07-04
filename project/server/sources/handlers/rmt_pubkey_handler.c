/*
** rmt_pubkey_handler.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/server/sources/handlers
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:25:58 2014 raphael defreitas
** Last update Fri Jul  4 00:50:17 2014 raphael defreitas
*/

#include	<dirent.h>
#include	<stdbool.h>
#include	<stdio.h>
#include	<string.h>
#include	<sys/types.h>

#include	"my.h"
#include	"handlers.h"
#include	"zappy.h"

bool		authorized_key(const char *key)
{
  DIR		*dir;
  struct dirent	*file;
  char		*contents;
  char		*fname;

  if ((dir = opendir("./keys/authorized_keys")) == NULL)
    return (false);
  while ((file = readdir(dir)))
    {
      fname = file->d_name;
      if (fname[0] != '.')
	{
	  contents = my_get_file_contents(fname, "./keys/authorized_keys");
	  if (contents == NULL)
	    continue ;
	  if (strcmp(contents, key) == 0)
	    {
	      free(contents);
	      return (true);
	    }
	  free(contents);
	}
    }
  return (false);
}

void		rmt_pubkey_handler(__attribute__((unused))t_zs *zs,
				   t_zc *zc,
				   const char *pk,
				   __attribute__((unused))void *data)
{
  if (authorized_key(pk))
    {
      zs_hook_rmt_stop(zc, &rmt_stop_handler, data);
      zs_send_rmt_authorized(zs, zc);
    }
  else
    zs_send_rmt_unauthorized(zs, zc);
}
