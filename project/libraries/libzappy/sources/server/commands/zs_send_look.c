/*
** zs_send_look.c for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/sources
** 
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
** 
** Started on  Fri Jun 27 19:04:36 2014 raphael defreitas
** Last update Sun Jul 13 06:09:39 2014 Pelayo Parejo Pagador
*/

#include	<stdio.h>
#include	<stdlib.h>

#include	"zappy.h"
#include	"_zappy.h"

static void	send_case(t_zs *this, t_zc *zc, char look)
{
  char		buf[100];

  sprintf(buf, "%d %d %d %d %d %d %d %d,",
	  look & 1,
	  look & 2,
	  look & 4,
	  look & 8,
	  look & 16,
	  look & 32,
	  look & 64,
	  look & 128
	  );
  zs_send(this, zc, buf);
}

void		zs_send_look(t_zs *this, t_zc *zc,
			     char (*look)[81], unsigned int sight)
{
  unsigned int	i;

  if (this == NULL)
    return ;
  zs_send(this, zc, "{");
  i = 0;
  while (i < sight)
    {
      send_case(this, zc, (*look)[i]);
      i++;
    }
  zs_send(this, zc, "}\n");
}
