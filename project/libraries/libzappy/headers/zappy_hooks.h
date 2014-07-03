/*
** zappy_hooks.h for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/headers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Fri Jun 27 17:17:13 2014 raphael defreitas
** Last update Thu Jul  3 19:09:32 2014 raphael defreitas
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

/*
** When an error occurs.
** err		The errno value.
** msg		The custom message. It can be NULL if not provided.
*/
typedef	void	(t_zsh_errno)(t_zs *zs, int err, const char *msg, void *data);
void		zs_hook_errno(t_zs *, t_zsh_errno h, void *d);

/*
** When a hook is handled.
** type		The hook type of the previous hook handled.
*/
typedef	void	(t_zsh_callback)(t_zs *zs, t_zht type, void *data);
void		zs_hook_callback(t_zs *, t_zsh_callback h, void *d);

/*
** When the select returns after a timeout.
*/
void		zs_hook_timeout(t_zs *, t_zsh_basic h, void *d);

/*
** When a client is connected.
*/
void		zs_hook_client_connected(t_zs *, t_zsh_client_basic h,
					 void *d);

/*
** When a client is disconnected.
*/
void		zs_hook_client_disconnected(t_zs *,
					    t_zsh_client_basic h,
					    void *d);

/*
** When a command is unknown
** zc		The client which have sent the unknown command
** cmd		The unknown command received
*/
typedef	void	(t_zsh_cmd_unknown)(t_zs *zs, t_zc *zc, const char *cmd,
				    void *data);
void		zs_hook_cmd_unknown(t_zc *zc, t_zsh_cmd_unknown h, void *d);

/*
** When a client sends its team name (after "BIENVENUE\n" command)
** zc		The client which have sent the command
** team_name	The team name sent
*/
void		zs_hook_cmd_team_name(t_zc *zc, t_zsh_str_basic h, void *d);

/*
** When a client sends "GRAPHIC\n"
*/
void		zs_hook_cmd_graphic(t_zc *zc, t_zsh_client_basic h, void *d);

/*
** When a client sends "RMT\n"
*/
void		zs_hook_cmd_rmt(t_zc *zc, t_zsh_client_basic h, void *d);

/*
** When the remote sends its public key
*/
void		zs_hook_rmt_pubkey(t_zc *zc, t_zsh_str_basic, void *d);

/*
** When the remote sends stop
*/
void		zs_hook_rmt_stop(t_zc *zc, t_zsh_client_basic, void *d);

/*
** +--------+
** | Client |
** +--------+
*/

/*
** Basic handler
*/
typedef	void	(t_zch_basic)(t_zc *zc, void *data);

/*
** Basic string handler
** str		The string of the hook
*/
typedef	void	(t_zch_str_basic)(t_zc *zc, const char *str, void *data);

/*
** When an error occurs.
** err		The errno value.
** msg		The custom message. It can be NULL if not provided.
*/
typedef	void	(t_zch_errno)(t_zc *zc, int err, const char *msg, void *data);
void		zc_hook_errno(t_zc *, t_zch_errno h, void *d);

/*
** When a hook is handled.
** type		The hook type of the previous hook handled.
*/
typedef	void	(t_zch_callback)(t_zc *zc, t_zht type, void *data);
void		zc_hook_callback(t_zc *, t_zch_callback h, void *d);

/*
** When the select returns after a timeout.
*/
void		zc_hook_timeout(t_zc *, t_zch_basic h, void *d);

/*
** When the zappy client is connected to server
*/
void		zc_hook_connected(t_zc *, t_zch_basic h, void *d);

/*
** When the zappy client is disconnected of server
*/
void		zc_hook_disconnected(t_zc *, t_zch_basic h, void *d);

/*
** When the binary have something in STDIN
*/
void		zc_hook_stdin(t_zc *, t_zch_str_basic h, void *d);

/*
** When a command is unknown
*/
void		zc_hook_cmd_unknown(t_zc *, t_zch_str_basic h, void *d);

/*
** When the server sends "BIENVENUE\n".
*/
void		zc_hook_cmd_welcome(t_zc *, t_zch_basic h, void *d);

/*
** When the server sends "RMT PUBKEY <pubkey>\n".
*/
void		zc_hook_rmt_pubkey(t_zc *, t_zch_str_basic h, void *d);

#endif /* !ZAPPY_HOOKS_H_*/
