/*
** zappy_commands.h for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/headers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Fri Jun 27 17:17:13 2014 raphael defreitas
** Last update Mon Jul  7 10:25:01 2014 raphael defreitas
*/

#ifndef		ZAPPY_COMMANDS_H_
# define	ZAPPY_COMMANDS_H_

/*
** +----------+
** | Required |
** +----------+
*/

# include	<glib.h>

/*
** +------------+
** | Structures |
** +------------+
*/

typedef	struct
{
  unsigned int	x;
  unsigned int	y;
}		t_position;

typedef	struct
{
  unsigned int	width;
  unsigned int	height;
}		t_msz;

typedef	struct
{
  t_position	position;
  unsigned char	food;
  unsigned char	linemate;
  unsigned char	deraumere;
  unsigned char	sibur;
  unsigned char	mendiane;
  unsigned char	phiras;
  unsigned char	thystame;
}		t_bct;

/*
** +--------+
** | Server |
** +--------+
*/

void		zs_send_welcome(t_zs *, t_zc *zc);
void		zs_send_ok(t_zs *, t_zc *zc);
void		zs_send_ko(t_zs *, t_zc *zc);

void		zs_send_rmt_pubkey(t_zs *, t_zc *zc);
void		zs_send_rmt_authorized(t_zs *, t_zc *zc);
void		zs_send_rmt_unauthorized(t_zs *, t_zc *zc);
void		zs_send_rmt_teams(t_zs *, t_zc *zc, t_list *teams);

void		zs_send_cmd_msz(t_zs *, t_zc *zc, t_msz msz);
void		zs_send_cmd_bct(t_zs *, t_zc *zc, t_bct bct);

/*
** +--------+
** | Client |
** +--------+
*/

void		zc_send_team_name(t_zc *, const char *team_name);
void		zc_send_cmd_forward(t_zc *);
void		zc_send_cmd_left(t_zc *);
void		zc_send_cmd_right(t_zc *);

void		zc_send_graphic(t_zc *);
void		zc_send_cmd_msz(t_zc *);
void		zc_send_cmd_bct(t_zc *, t_position position);
void		zc_send_cmd_mct(t_zc *);

void		zc_send_rmt(t_zc *);
void		zc_send_rmt_pubkey(t_zc *);
void		zc_send_rmt_stop(t_zc *);
void		zc_send_rmt_teams(t_zc *);



#endif /* !ZAPPY_COMMANDS_H_*/
