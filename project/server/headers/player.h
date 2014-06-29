/*
** player.h for zappy in /home/damien/zappy/project/server/headers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 11:57:43 2014 damien sauvalle
** Last update Sun Jun 29 18:02:16 2014 damien sauvalle
*/

#ifndef		PLAYER_H_
# define	PLAYER_H_

# include	"inventory.h"

typedef enum
  {
    N,
    S,
    E,
    W
  }	t_direction;

/*
** x & y 0 en haut a gauche ?
*/
typedef struct	s_coord
{
  int		x;
  int		y;
}		t_coord;

/*
** Raphy struct +++
*/
typedef struct	s_player
{
  unsigned int	*inventory;
  t_direction	direction;
  t_coord	coord;
  char		*team_name;
  int		level; /* level and view range*/
  unsigned int	life;
  /*  ? handler --> action ?*/
}		t_player;

/*
** Player
*/
int			player_ctor(t_player *);
void			player_dtor(t_player *);

/*
** Direction
*/
void			pl_set_direction(t_player *, t_direction);
t_direction		pl_get_direction(t_player *);

/*
** coord
*/
int			pl_coord_ctor(t_player *);
void			pl_coord_dtor(t_player *); /* Really util ?*/

void			pl_set_x(t_player *, int);
void			pl_set_y(t_player *, int);

int			pl_get_x(t_player *);
int			pl_get_y(t_player *);

/*
** Team Name
*/
int			pl_set_team_name(t_player *, char *); /* Here ? || ctor*/
char			*pl_get_team_name(t_player *);/* Really util ?*/

/*
** Level / Range view
*/
void			pl_set_level(t_player *, int);
int			pl_get_level(t_player *);

/*
** time life
*/
int			pl_set_life(t_player *);
unsigned int		pl_get_life(t_player *);

#endif /* !PLAYER_H_ */
