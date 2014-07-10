/*
** server.h for zappy in /home/damien/zappy/project/server/headers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Thu Jul  3 23:21:49 2014 damien sauvalle
** Last update Thu Jul 10 17:27:25 2014 damien sauvalle
*/

#ifndef SERVER_H_
# define SERVER_H_

# include	"inventory.h"
# include	"list.h"
# include	"arg.h"
# include	"case.h"
# include       "event.h"
# include	"player.h"
# include	"zappy.h"

typedef struct	s_server
{
  t_case	**map;
  t_list        *players;
  t_list        *events;
  t_list	*eggs;
  t_list	*graphic;
  t_list	*remote;
  t_arg		*arg;
}		t_server;

typedef struct	s_graphic
{
  t_zc		*zc;
}		t_graphic;

typedef struct	s_remote
{
  t_zc		*zc;
}		t_remote;

int		graphic_ctor(t_graphic *, t_zc *);
t_graphic       *graphic_new(t_zc *);
void		graphic_delete(t_graphic *);
void		graphic_dtor(t_graphic *);

int		remote_ctor(t_remote *, t_zc *);
t_remote       *remote_new(t_zc *);
void		remote_delete(t_remote *);
void		remote_dtor(t_remote *);


int		server_ctor(t_server *, t_arg *);
void		server_dtor(t_server *);
void		dump_map(t_server *, t_arg *);

typedef void (*fill)(t_case **, t_arg *, int);

typedef struct	s_fill_map
{
  fill		fill;
}		t_fill_map;

void	add_player(t_server *, t_player *);
void	generate_ressource(t_server *);
void	fill_linemate(t_case **, t_arg *, int);
void	fill_deraumere(t_case **, t_arg *, int);
void	fill_sibur(t_case **, t_arg *, int);
void	fill_mendiane(t_case **, t_arg *, int);
void	fill_phiras(t_case **, t_arg *, int);
void	fill_thystane(t_case **, t_arg *, int);
void	fill_food(t_case **, t_arg *, int);

/*
** Fonction pour acceder au ressource d'une case definie
** Pour les joueurs Finder via Id
*/

#endif /* !SERVER_H_ */
