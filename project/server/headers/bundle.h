/*
** bundle.h for  in /home/svirch_n/zappy/project/server/headers
**
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
**
** Started on  Mon Jul  7 16:23:08 2014 nicolas svirchevsky
** Last update Sat Jul 12 01:23:11 2014 damien sauvalle
*/

#ifndef		BUNDLE_H
# define	BUNDLE_H

# include	"server.h"
# include	"player.h"

typedef struct	s_bundle
{
  t_server	*server;
  t_player	*player;
}		t_bundle;

#endif		/* BUNDLE_H */
