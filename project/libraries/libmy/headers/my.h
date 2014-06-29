/*
** libmy.h for libmy in /home/raphy/Development/Epitech/Libraries/libmy/Headers
**
** Made by Raphael De Freitas
** Login   <defrei_r@epitech.net>
**
** Started on  Sun Dec 15 23:20:11 2013 Raphael De Freitas
** Last update Sun Jun 29 17:13:17 2014 raphael defreitas
*/

#ifndef		MY_H_
# define	MY_H_

/*
** +----------+
** | Required |
** +----------+
*/

#include	<glib.h>
#include	<stdbool.h>

G_BEGIN_DECLS

/*
** +--------+
** | Macros |
** +--------+
*/

# ifndef	RET_ERROR
#  define	RET_ERROR	-1
# endif /* !RET_ERROR */

# ifndef	RET_SUCCESS
#  define	RET_SUCCESS	0
# endif /* !RET_SUCCESS */

# ifndef	RET_FAILURE
#  define	RET_FAILURE	1
# endif /* !RET_FAILURE */

/*
** +---------+
** | Strings |
** +---------+
*/

bool		my_str_is_numeric(const char *str);
bool		my_match(const char *str, const char *pattern);

G_END_DECLS

#endif /* !MY_H_ */
