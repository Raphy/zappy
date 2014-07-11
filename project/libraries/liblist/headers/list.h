/*
** list.h for liblist in /home/raphy/Epitech/Libraries/liblist/headers
**
** Made by raphael defreitas
** Login   <defrei_r@epitech.net>
**
** Started on  Thu Apr 17 18:53:27 2014 raphael defreitas
** Last update Fri Jul 11 17:00:56 2014 raphael defreitas
*/

#ifndef		LIST_H_
# define	LIST_H_

# include	<glib.h>
# include	<sys/types.h>

G_BEGIN_DECLS

# ifndef	RET_ERROR
#  define	RET_ERROR	-1
# endif /* !RET_ERROR */

# ifndef	RET_SUCCESS
#  define	RET_SUCCESS	0
# endif /* !RET_SUCCESS */

# ifndef	RET_FAILURE
#  define	RET_FAILURE	1
# endif /* !RET_FAILURE */

typedef	struct	s_iterator	t_iterator;

typedef	struct	s_item		t_item;

typedef	struct	s_list		t_list;

/*
** +----------+
** | Iterator |
** +----------+
*/
typedef	enum
  {
    IT_DATA,
    IT_ITEM
  }		t_it_type;

struct		s_iterator
{
  t_list	*list;
  t_item	*current;
  t_it_type	type;
};

t_iterator	*iterator_new(t_list *, t_it_type);
void		iterator_delete(t_iterator *);

int		iterator_ctor(t_iterator *, t_list *, t_it_type);
void		iterator_dtor(t_iterator *);

void		*iterator_current(t_iterator *);
void		iterator_next(t_iterator *);
void		iterator_prev(t_iterator *);
void		iterator_reset(t_iterator *);

/*
** +------+
** | Item |
** +------+
*/
struct		s_item
{
  void		*data;
  t_item	*prev;
  t_item	*next;
  void		(*data_free_fptr)();
};

t_item		*item_new(void *, void (*)());
void		item_delete(t_item *);

int		item_ctor(t_item *, void *, void (*)());
void		item_dtor(t_item *);

void		*item_data(t_item *);
t_item		*item_next(t_item *);
t_item		*item_prev(t_item *);

/*
** +------+
** | List |
** +------+
*/
struct		s_list
{
  t_item	*front;
  t_item	*back;
  size_t	length;
  void		(*data_free_fptr)();
};

t_list		*list_new(void (*)());
void		list_delete(t_list *);

int		list_ctor(t_list *, void (*)());
void		list_dtor(t_list *);

void		list_dump(t_list *);
void		*list_front(t_list *);
void		*list_back(t_list *);
size_t		list_length(t_list *);

int		list_push(t_list *, void *);
void		*list_pop(t_list *);
int		list_enqueue(t_list *, void *);
void		*list_dequeue(t_list *);
void		*list_unlink(t_list *, t_item *);
void		*list_find(t_list *, int (*)(), const void *, t_it_type);
void		list_clear(t_list *);
int		list_insert(t_list *, t_item *, void *);

G_END_DECLS

#endif /* !LIST_H_*/
