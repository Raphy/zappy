/*
** zappy_commands.h for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/headers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Fri Jun 27 17:17:13 2014 raphael defreitas
** Last update Sat Jul 12 16:32:42 2014 raphael defreitas
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

typedef	enum
{
  ORIENTATION_UNKNOWN,
  ORIENTATION_NORTH,
  ORIENTATION_EAST,
  ORIENTATION_SOUTH,
  ORIENTATION_WEST,
}		t_orientation;

typedef	enum
  {
    RESOURCE_FOOD,
    RESOURCE_LINEMATE,
    RESOURCE_DERAUMERE,
    RESOURCE_SIBUR,
    RESOURCE_MENDIANE,
    RESOURCE_PHIRAS,
    RESOURCE_THYSTAME,
  }		t_resource;

typedef	struct
{
  unsigned char	food;
  unsigned char	linemate;
  unsigned char	deraumere;
  unsigned char	sibur;
  unsigned char	mendiane;
  unsigned char	phiras;
  unsigned char	thystame;
}		t_items;

typedef	struct
{
  unsigned int	width;
  unsigned int	height;
}		t_msz;

typedef	struct
{
  t_position	position;
  t_items	items;
}		t_bct;

typedef	struct
{
  unsigned int	uid;
  t_position	position;
  t_orientation	orientation;
  unsigned char	level;
  char		*team_name;
}		t_pnw;

typedef	struct
{
  unsigned int	uid;
  t_position	position;
  t_orientation	orientation;
}		t_ppo;

typedef	struct
{
  unsigned int	uid;
  unsigned char	level;
}		t_plv;

typedef	struct
{
  unsigned int	uid;
  t_position	position;
  t_items	items;
}		t_pin;

typedef	struct
{
  unsigned int	uid;
  char		*message;
}		t_pbc;

typedef	struct
{
  t_position	position;
  unsigned char	level;
  unsigned int	nb_uids;
  unsigned int	*uids;
}		t_pic;

typedef	struct
{
  t_position	position;
  bool		result;
}		t_pie;

typedef	struct
{
  unsigned int	uid;
  t_resource	resource;
}		t_pdr;

typedef	struct
{
  unsigned int	uid;
  t_resource	resource;
}		t_pgt;

typedef	struct
{
  unsigned int	eid;
  unsigned int	uid;
  t_position	position;
}		t_enw;

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
void		zs_send_rmt_teams(t_zs *, t_zc *zc, const t_list *teams);

void		zs_send_cmd_msz(t_zs *, t_zc *zc, const t_msz *msz);
void		zs_send_cmd_bct(t_zs *, t_zc *zc, const t_bct *bct);
void		zs_send_cmd_tna(t_zs *, t_zc *zc, const char *tna);
void		zs_send_cmd_pnw(t_zs *, t_zc *zc, const t_pnw *pnw);
void		zs_send_cmd_pex(t_zs *, t_zc *zc, unsigned int uid);
void		zs_send_cmd_pbc(t_zs *, t_zc *zc, const t_pbc *pbc);
void		zs_send_cmd_pic(t_zs *, t_zc *zc, const t_pic *pic);
void		zs_send_cmd_pie(t_zs *, t_zc *zc, const t_pie *pie);
void		zs_send_cmd_pin(t_zs *, t_zc *zc, const t_pin *pin);
void		zs_send_cmd_plv(t_zs *, t_zc *zc, const t_plv *plv);
void		zs_send_cmd_ppo(t_zs *, t_zc *zc, const t_ppo *ppo);
void		zs_send_cmd_sgt(t_zs *, t_zc *zc, unsigned int time);
void		zs_send_cmd_pfk(t_zs *, t_zc *zc, unsigned int uid);
void		zs_send_cmd_pdr(t_zs *, t_zc *zc, const t_pdr *pdr);
void		zs_send_cmd_pdi(t_zs *, t_zc *zc, unsigned int uid);
void		zs_send_cmd_enw(t_zs *, t_zc *zc, const t_enw *enw);
void		zs_send_cmd_eht(t_zs *, t_zc *zc, unsigned int eid);
void		zs_send_cmd_ebo(t_zs *, t_zc *zc, unsigned int eid);
void		zs_send_cmd_edi(t_zs *, t_zc *zc, unsigned int eid);

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
void		zc_send_cmd_bct(t_zc *, const t_position *position);
void		zc_send_cmd_mct(t_zc *);
void		zc_send_cmd_tna(t_zc *);
void		zc_send_cmd_pin(t_zc *, unsigned int uid);
void		zc_send_cmd_plv(t_zc *, unsigned int uid);
void		zc_send_cmd_ppo(t_zc *, unsigned int uid);
void		zc_send_cmd_sgt(t_zc *);
void		zc_send_cmd_sst(t_zc *, unsigned int uid);

void		zc_send_rmt(t_zc *);
void		zc_send_rmt_pubkey(t_zc *);
void		zc_send_rmt_stop(t_zc *);
void		zc_send_rmt_teams(t_zc *);

#endif /* !ZAPPY_COMMANDS_H_*/
