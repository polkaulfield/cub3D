#ifndef GALLOC_H
# define GALLOC_H

#include <stdlib.h>
#include <stdio.h>
#include "../libs/libft/libft.h"

typedef struct s_galloc
{
	void			*mem;
	struct s_galloc	*next;
	struct s_galloc	*start;
}  t_galloc;


t_galloc	*init_galloc(void);
void		terminate(int exit_value);
void		free_galloc(t_galloc *galloc);
void		*add_galloc(void *mem);
void		gfree(void *ptr);
void		*galloc(size_t size);
void		*add_galloc_arr(void **mem);
void		gfree_arr(void **arr);
void	terminate_error(char *text_error);

#endif
