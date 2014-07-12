/*
** _zappy.h for Zappy in /home/raphy/Epitech/Tech_2/zappy/project/libraries/libzappy/headers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Fri Jun 27 13:13:50 2014 raphael defreitas
** Last update Sat Jul 12 16:33:05 2014 raphael defreitas
*/

#ifndef		_ZAPPY_H_
# define	_ZAPPY_H_

/*
** +----------+
** | Required |
** +----------+
*/
# include	<glib.h>
# include	<openssl/rsa.h>
# include	<stdbool.h>

#include	"zappy.h"

G_BEGIN_DECLS

/*
** +--------+
** | Server |
** +--------+
*/

int		zs_ctor_cmd_fptrs(t_zs *);

void		zs_treat_fds(t_zs *);
void		zs_treat_zc(t_zs *, t_zc *);
void		zs_send(t_zs *, t_zc *, const char *);
void		zs_send_to_client(t_zs *, t_zc *, const char *);
void		zs_send_to_all(t_zs *, const char *);

/*
** Command dispatcher
*/
typedef	bool	(*t_zs_cmd)(t_zs *, t_zc *, const char *);
void		zs_dispatch_command(t_zs *, t_zc *, const char *);

bool		zs_cmd_team_name(t_zs *, t_zc *, const char *);
bool		zs_cmd_forward(t_zs *, t_zc *, const char *);
bool		zs_cmd_left(t_zs *, t_zc *, const char *);
bool		zs_cmd_right(t_zs *, t_zc *, const char *);

bool		zs_cmd_graphic(t_zs *, t_zc *, const char *);
bool		zs_cmd_msz(t_zs *, t_zc *, const char *);
bool		zs_cmd_bct(t_zs *, t_zc *, const char *);
bool		zs_cmd_mct(t_zs *, t_zc *, const char *);
bool		zs_cmd_tna(t_zs *, t_zc *, const char *);
bool		zs_cmd_ppo(t_zs *, t_zc *, const char *);
bool		zs_cmd_plv(t_zs *, t_zc *, const char *);
bool		zs_cmd_pin(t_zs *, t_zc *, const char *);
bool		zs_cmd_sst(t_zs *, t_zc *, const char *);
bool		zs_cmd_sgt(t_zs *, t_zc *, const char *);

bool		zs_cmd_rmt(t_zs *, t_zc *, const char *);
bool		zs_rmt_pubkey(t_zs *, t_zc *, const char *);
bool		zs_rmt_stop(t_zs *, t_zc *, const char *);
bool		zs_rmt_teams(t_zs *, t_zc *, const char *);

/*
** Event managing
*/
void		zs_hook(t_zs *, t_zht, void (*)(), void *);
void		zs_handle_errno(t_zs *, const char *);
void		zs_handle_callback(t_zs *, t_zht);
void		zs_handle_timeout(t_zs *);
void		zs_handle_before_select(t_zs *);
void		zs_handle_after_select(t_zs *);
void		zs_handle_client_connected(t_zs *, t_zc *);
void		zs_handle_client_disconnected(t_zs *, t_zc *);
void		zs_handle_cmd_unknown(t_zs *, t_zc *, const char *);

void		zs_handle_cmd_team_name(t_zs *, t_zc *, const char *);
void		zs_handle_cmd_forward(t_zs *, t_zc *);
void		zs_handle_cmd_left(t_zs *, t_zc *);
void		zs_handle_cmd_right(t_zs *, t_zc *);

void		zs_handle_cmd_graphic(t_zs *, t_zc *);
void		zs_handle_cmd_msz(t_zs *, t_zc *);
void		zs_handle_cmd_bct(t_zs *, t_zc *, t_position *);
void		zs_handle_cmd_mct(t_zs *, t_zc *);
void		zs_handle_cmd_tna(t_zs *, t_zc *);
void		zs_handle_cmd_ppo(t_zs *, t_zc *, unsigned int);
void		zs_handle_cmd_plv(t_zs *, t_zc *, unsigned int);
void		zs_handle_cmd_pin(t_zs *, t_zc *, unsigned int);
void		zs_handle_cmd_sgt(t_zs *, t_zc *);
void		zs_handle_cmd_sst(t_zs *, t_zc *, unsigned int);
void		zs_handle_cmd_pfk(t_zs *, t_zc *, unsigned int);

void		zs_handle_cmd_rmt(t_zs *, t_zc *);
void		zs_handle_rmt_pubkey(t_zs *, t_zc *, const char *);
void		zs_handle_rmt_stop(t_zs *, t_zc *);
void		zs_handle_rmt_teams(t_zs *, t_zc *);

/*
** +--------+
** | Client |
** +--------+
*/

int		zc_ctor_cmd_fptrs(t_zc *);

void		zc_treat_fds(t_zc *);
void		zc_treat(t_zc *);
void		zc_send(t_zc *, const char *);

/*
** Command dispatcher
*/
typedef	bool	(*t_zc_cmd)(t_zc *, const char *);
void		zc_dispatch_command(t_zc *, const char *);

bool		zc_cmd_welcome(t_zc *, const char *);
bool		zc_ok(t_zc *, const char *);
bool		zc_ko(t_zc *, const char *);

bool		zc_cmd_msz(t_zc *, const char *);
bool		zc_cmd_bct(t_zc *, const char *);
bool		zc_cmd_tna(t_zc *, const char *);
bool		zc_cmd_pnw(t_zc *, const char *);
bool		zc_cmd_ppo(t_zc *, const char *);
bool		zc_cmd_plv(t_zc *, const char *);
bool		zc_cmd_pin(t_zc *, const char *);
bool		zc_cmd_pex(t_zc *, const char *);
bool		zc_cmd_pbc(t_zc *, const char *);
bool		zc_cmd_pic(t_zc *, const char *);
bool		zc_cmd_pie(t_zc *, const char *);
bool		zc_cmd_pfk(t_zc *, const char *);
bool		zc_cmd_pdr(t_zc *, const char *);
bool		zc_cmd_pdi(t_zc *, const char *);
bool		zc_cmd_sgt(t_zc *, const char *);
bool		zc_cmd_enw(t_zc *, const char *);
bool		zc_cmd_eht(t_zc *, const char *);
bool		zc_cmd_ebo(t_zc *, const char *);
bool		zc_cmd_edi(t_zc *, const char *);

bool		zc_rmt_authorized(t_zc *, const char *);
bool		zc_rmt_unauthorized(t_zc *, const char *);
bool		zc_rmt_pubkey(t_zc *, const char *);
bool		zc_rmt_teams(t_zc *, const char *);

/*
** Event managing
*/
void		zc_hook(t_zc *, t_zht, void (*)(), void *);
void		zc_handle_errno(t_zc *, const char *);
void		zc_handle_callback(t_zc *, t_zht);
void		zc_handle_timeout(t_zc *);
void		zc_handle_before_select(t_zc *);
void		zc_handle_after_select(t_zc *);
void		zc_handle_connected(t_zc *);
void		zc_handle_disconnected(t_zc *);
void		zc_handle_stdin(t_zc *, const char *);
void		zc_handle_cmd_unknown(t_zc *, const char *);

void		zc_handle_cmd_welcome(t_zc *);
void		zc_handle_ok(t_zc *);
void		zc_handle_ko(t_zc *);

void		zc_handle_cmd_msz(t_zc *, t_msz *);
void		zc_handle_cmd_bct(t_zc *, t_bct *);
void		zc_handle_cmd_tna(t_zc *, const char *);
void		zc_handle_cmd_pnw(t_zc *, t_pnw *);
void		zc_handle_cmd_ppo(t_zc *, t_ppo *);
void		zc_handle_cmd_plv(t_zc *, t_plv *);
void		zc_handle_cmd_pin(t_zc *, t_pin *);
void		zc_handle_cmd_pex(t_zc *, unsigned int);
void		zc_handle_cmd_pbc(t_zc *, t_pbc *);
void		zc_handle_cmd_pic(t_zc *, t_pic *);
void		zc_handle_cmd_pie(t_zc *, t_pie *);
void		zc_handle_cmd_pfk(t_zc *, unsigned int);
void		zc_handle_cmd_pdr(t_zc *, t_pdr *);
void		zc_handle_cmd_pgt(t_zc *, t_pgt *);
void		zc_handle_cmd_pdi(t_zc *, unsigned int);
void		zc_handle_cmd_enw(t_zc *, t_enw *);
void		zc_handle_cmd_eht(t_zc *, unsigned int);
void		zc_handle_cmd_ebo(t_zc *, unsigned int);
void		zc_handle_cmd_edi(t_zc *, unsigned int);
void		zc_handle_cmd_sgt(t_zc *, unsigned int);

void		zc_handle_rmt_pubkey(t_zc *, const char *);
void		zc_handle_rmt_authorized(t_zc *);
void		zc_handle_rmt_unauthorized(t_zc *);
void		zc_handle_rmt_teams(t_zc *, const char *);

/*
** +-------+
** | Tools |
** +-------+
*/
int		zt_build_command(t_list *, char **);
int		zt_append_buffer(t_list *, const char *);
char		*zt_linearize_pubkey(const char *);
char		*zt_unlinearize_pubkey(const char *);

/*
** Plain -> Encryption -> Encoding | | Decoding -> Decryption -> Plain
*/
unsigned char	*zt_rsa_encrypt(RSA *, const char *, int *);
char		*zt_b64_encode(const unsigned char *, int);
unsigned char	*zt_b64_decode(const char *);
char		*zt_rsa_decrypt(RSA *, const unsigned char *, int);
int		zt_rmt_encrypt(RSA *, const char *, char **);
int		zt_rmt_decrypt(RSA *, const char *, char **);
bool		zt_get_rmt_cmd(RSA *, const char *, char **, int *);

G_END_DECLS

#endif /* !_ZAPPY_H_*/
