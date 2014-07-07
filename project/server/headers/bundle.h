/*
** bundle.h for  in /home/svirch_n/zappy/project/server/headers
** 
** Made by nicolas svirchevsky
** Login   <svirch_n@epitech.net>
** 
** Started on  Mon Jul  7 16:23:08 2014 nicolas svirchevsky
** Last update Mon Jul  7 16:24:32 2014 nicolas svirchevsky
*/

#ifndef		BUNDLE_H
# define	BUNDLE_H

typedef struct s_server t_server;

typedef struct	s_bundle
{
  t_server	*server;
  t_player	*player;
}		t_bundle;

#endif		/* BUNDLE_H */
