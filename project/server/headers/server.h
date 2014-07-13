/*
** server.h for zappy in /home/damien/zappy/project/server/headers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Thu Jul  3 23:21:49 2014 damien sauvalle
** Last update Sun Jul 13 11:15:45 2014 damien sauvalle
*/

#ifndef SERVER_H_
# define SERVER_H_

# include	"inventory.h"
# include	"list.h"
# include	"arg.h"
# include	"case.h"
# include	"zappy.h"

# define	TO_MAP(value, max) ((max + value) % max)

typedef struct	s_server
{
  t_case	**map;
  t_list	*players;
  t_list	*events;
  t_list	*eggs;
  t_list	*graphic;
  t_list	*remote;
  t_arg		*arg;
  t_zs		*zs;
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
t_graphic	*graphic_new(t_zc *);
void		graphic_delete(t_graphic *);
void		graphic_dtor(t_graphic *);
int		remote_ctor(t_remote *, t_zc *);
t_remote	*remote_new(t_zc *);
void		remote_delete(t_remote *);
void		remote_dtor(t_remote *);
int		server_ctor(t_server *, t_arg *, t_zs *);
void		server_dtor(t_server *);

typedef void	(*fill)(t_case **, t_arg *, int);

typedef struct	s_fill_map
{
  fill		fill;
}		t_fill_map;

void	generate_ressource(t_server *);
void	fill_linemate(t_case **, t_arg *, int);
void	fill_deraumere(t_case **, t_arg *, int);
void	fill_sibur(t_case **, t_arg *, int);
void	fill_mendiane(t_case **, t_arg *, int);
void	fill_phiras(t_case **, t_arg *, int);
void	fill_thystane(t_case **, t_arg *, int);
void	fill_food(t_case **, t_arg *, int);

void	server_msz(t_zs *, t_zc *, void *);
void	server_bct(t_zs *, t_zc *, t_position *, void *);
void	server_mct(t_zs *, t_zc *, void *);
void	server_sgt(t_zs *, t_zc *, void *);
void	server_tna(t_zs *, t_zc *, void *);

void	server_ppo(t_zs *, t_zc *, unsigned int, void *);
void	server_plv(t_zs *, t_zc *, unsigned int, void *);
void	server_pin(t_zs *, t_zc *, unsigned int, void *);
void	server_sst(t_zs *, t_zc *, unsigned int, void *);
void	server_pnw(t_zs *, t_zc *, void *);

#endif /* !SERVER_H_ */
