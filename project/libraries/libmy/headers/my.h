/*
** libmy.h for libmy in /home/raphy/Development/Epitech/Libraries/libmy/Headers
**
** Made by Raphael De Freitas
** Login   <defrei_r@epitech.net>
**
** Started on  Sun Dec 15 23:20:11 2013 Raphael De Freitas
** Last update Thu Jul  3 23:39:16 2014 raphael defreitas
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
char		*my_get_file_contents(const char *filename, const char *dir);

G_END_DECLS

#endif /* !MY_H_ */
