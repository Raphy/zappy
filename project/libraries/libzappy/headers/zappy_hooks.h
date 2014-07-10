/*
** zappy_hooks.h for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/headers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Fri Jun 27 17:17:13 2014 raphael defreitas
** Last update Thu Jul 10 03:35:36 2014 raphael defreitas
*/

#ifndef		ZAPPY_HOOKS_H_
# define	ZAPPY_HOOKS_H_

/*
** +----------+
** | Required |
** +----------+
*/

# include	<glib.h>

/*
** +--------+
** | Server |
** +--------+
*/

typedef	void	(t_zsh_basic)(t_zs *zs, void *data);
typedef	void	(t_zsh_client_basic)(t_zs *zs, t_zc *zc, void *data);
typedef	void	(t_zsh_str_basic)(t_zs *zs, t_zc *zc, const char *str, void *d);
typedef	void	(t_zsh_uint_basic)(t_zs *zs, t_zc *zc, unsigned int nbr, void *d);

typedef	void	(t_zsh_errno)(t_zs *zs, int err, const char *msg, void *data);
void		zs_hook_errno(t_zs *, t_zsh_errno h, void *d);
typedef	void	(t_zsh_callback)(t_zs *zs, t_zht type, void *data);
void		zs_hook_callback(t_zs *, t_zsh_callback h, void *d);
void		zs_hook_timeout(t_zs *, t_zsh_basic h, void *d);
void		zs_hook_before_select(t_zs *zc, t_zsh_basic h, void *d);
void		zs_hook_after_select(t_zs *zc, t_zsh_basic h, void *d);
void		zs_hook_client_connected(t_zs *, t_zsh_client_basic h,
					 void *d);
void		zs_hook_client_disconnected(t_zs *,
					    t_zsh_client_basic h,
					    void *d);
typedef	void	(t_zsh_cmd_unknown)(t_zs *zs, t_zc *zc, const char *cmd,
				    void *data);
void		zs_hook_cmd_unknown(t_zc *zc, t_zsh_cmd_unknown h, void *d);

void		zs_hook_cmd_team_name(t_zc *zc, t_zsh_str_basic h, void *d);
void		zs_hook_cmd_forward(t_zs *, t_zsh_client_basic h, void *d);
void		zs_hook_cmd_left(t_zs *, t_zsh_client_basic h, void *d);
void		zs_hook_cmd_right(t_zs *, t_zsh_client_basic h, void *d);

void		zs_hook_cmd_graphic(t_zc *zc, t_zsh_client_basic h, void *d);
void		zs_hook_cmd_msz(t_zc *zc, t_zsh_client_basic h, void *d);
typedef	void	(t_zsh_cmd_bct)(t_zs *zs, t_zc *zc, t_position *pos, void *d);
void		zs_hook_cmd_bct(t_zc *zc, t_zsh_cmd_bct h, void *d);
void		zs_hook_cmd_mct(t_zc *zc, t_zsh_client_basic h, void *d);
void		zs_hook_cmd_tna(t_zc *zc, t_zsh_client_basic h, void *d);
void		zs_hook_cmd_ppo(t_zc *zc, t_zsh_uint_basic h, void *d);
void		zs_hook_cmd_plv(t_zc *zc, t_zsh_uint_basic h, void *d);
void		zs_hook_cmd_pin(t_zc *zc, t_zsh_uint_basic h, void *d);
void		zs_hook_cmd_sst(t_zc *zc, t_zsh_uint_basic h, void *d);
void		zs_hook_cmd_sgt(t_zc *zc, t_zsh_client_basic h, void *d);

void		zs_hook_cmd_rmt(t_zc *zc, t_zsh_client_basic h, void *d);
void		zs_hook_rmt_pubkey(t_zc *zc, t_zsh_str_basic, void *d);
void		zs_hook_rmt_stop(t_zc *zc, t_zsh_client_basic, void *d);
void		zs_hook_rmt_teams(t_zc *zc, t_zsh_client_basic, void *d);

/*
** +--------+
** | Client |
** +--------+
*/

typedef	void	(t_zch_basic)(t_zc *zc, void *data);
typedef	void	(t_zch_str_basic)(t_zc *zc, const char *, void *data);
typedef	void	(t_zch_uint_basic)(t_zc *zc, unsigned int, void *data);

typedef	void	(t_zch_errno)(t_zc *zc, int err, const char *msg, void *data);
void		zc_hook_errno(t_zc *, t_zch_errno h, void *d);
typedef	void	(t_zch_callback)(t_zc *zc, t_zht type, void *data);
void		zc_hook_callback(t_zc *, t_zch_callback h, void *d);
void		zc_hook_timeout(t_zc *, t_zch_basic h, void *d);
void		zc_hook_before_select(t_zc *, t_zch_basic h, void *d);
void		zc_hook_after_select(t_zc *, t_zch_basic h, void *d);
void		zc_hook_connected(t_zc *, t_zch_basic h, void *d);
void		zc_hook_disconnected(t_zc *, t_zch_basic h, void *d);
void		zc_hook_stdin(t_zc *, t_zch_str_basic h, void *d);
void		zc_hook_cmd_unknown(t_zc *, t_zch_str_basic h, void *d);

void		zc_hook_cmd_welcome(t_zc *, t_zch_basic h, void *d);
void		zc_hook_ok(t_zc *, t_zch_basic h, void *d);
void		zc_hook_ko(t_zc *, t_zch_basic h, void *d);

typedef	void	(t_zch_cmd_msz)(t_zc *zc, t_msz *msz, void *d);
void		zc_hook_cmd_msz(t_zc *, t_zch_cmd_msz h, void *d);
typedef	void	(t_zch_cmd_bct)(t_zc *zc, t_bct *bct, void *d);
void		zc_hook_cmd_bct(t_zc *, t_zch_cmd_bct h, void *d);
void		zc_hook_cmd_tna(t_zc *, t_zch_str_basic h, void *d);
typedef	void	(t_zch_cmd_pnw)(t_zc *zc, t_pnw *pnw, void *d);
void		zc_hook_cmd_pnw(t_zc *, t_zch_cmd_pnw h, void *d);
typedef	void	(t_zch_cmd_ppo)(t_zc *zc, t_ppo *ppo, void *d);
void		zc_hook_cmd_ppo(t_zc *, t_zch_cmd_ppo h, void *d);
typedef	void	(t_zch_cmd_plv)(t_zc *zc, t_plv *plv, void *d);
void		zc_hook_cmd_plv(t_zc *, t_zch_cmd_plv h, void *d);
typedef	void	(t_zch_cmd_pin)(t_zc *zc, t_pin *pin, void *d);
void		zc_hook_cmd_pin(t_zc *, t_zch_cmd_pin h, void *d);
void		zc_hook_cmd_pex(t_zc *, t_zch_uint_basic h, void *d);
typedef	void	(t_zch_cmd_pbc)(t_zc *zc, t_pbc *pbc, void *d);
void		zc_hook_cmd_pbc(t_zc *, t_zch_cmd_pbc h, void *d);


void		zc_hook_rmt_pubkey(t_zc *, t_zch_str_basic h, void *d);
void		zc_hook_rmt_authorized(t_zc *, t_zch_basic h, void *d);
void		zc_hook_rmt_unauthorized(t_zc *, t_zch_basic h, void *d);
void		zc_hook_rmt_teams(t_zc *, t_zch_str_basic h, void *d);



#endif /* !ZAPPY_HOOKS_H_*/
