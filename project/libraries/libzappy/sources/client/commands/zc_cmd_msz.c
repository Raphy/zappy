/*
** zc_cmd_msz.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Sun Jun 29 06:48:33 2014 raphael defreitas
** Last update Thu Jul 10 06:29:02 2014 raphael defreitas
*/

#define		_GNU_SOURCE
#include	<stdbool.h>
#include	<string.h>

#include	"my.h"
#include	"zappy.h"
#include	"_zappy.h"

static bool	parse(const char *cmd, t_msz *msz)
{
  char		*width;
  char		*height;

  if ((width = strdup(cmd + 4)) == NULL)
    return (false);
  height = strchr(width, ' ');
  width[height - width] = 0;
  height++;
  if (!my_str_is_numeric(width) || !my_str_is_numeric(height))
    {
      free(width);
      return (false);
    }
  msz->width = strtoul(width, NULL, 0);
  msz->height = strtoul(height, NULL, 0);
  free(width);
  return (true);
}

bool		zc_cmd_msz(t_zc *this, const char *cmd)
{
  t_msz		msz;

  if (!my_match(cmd, "msz * *"))
    return (false);
  if (!parse(cmd, &msz))
    return (false);
  zc_handle_cmd_msz(this, &msz);
  return (true);
}
