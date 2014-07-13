/*
** player.h for zappy in /home/damien/zappy/project/server/headers
**
** Made by damien sauvalle
** Login   <sauval_d@epitech.net>
**
** Started on  Sun Jun 29 11:57:43 2014 damien sauvalle
** Last update Sun Jul 13 11:10:20 2014 damien sauvalle
*/

#ifndef		PLAYER_H_
# define	PLAYER_H_

# include	"zappy.h"
# include	"inventory.h"
# include	"server.h"

typedef enum
  {
    NORMAL,
    INCANTATION,
    FORK
  }	t_etat;

typedef struct	s_player
{
  t_items	inventory;
  t_orientation	direction;
  unsigned int	x;
  unsigned int	y;
  char		*team_name;
  unsigned char	level;
  unsigned int	life;
  unsigned char	etat;
  t_zc		*zc;
}		t_player;

/*
** Player
*/
int		player_ctor(t_player *, t_server *, t_zc *, const char *);
void		player_dtor(t_player *);
t_player	*player_new(t_server *,  t_zc *, const char *);
void		player_delete(t_player *);
bool		find_by_uid(t_player *, unsigned int *);

/*
 ** Do not change this structure without controlling its result in handler_incantation.c
 */
/* a mettre en t_   */
struct s_elevation_condition
{
    unsigned int  player_required;
    t_items items;
};

#endif /* !PLAYER_H_ */
