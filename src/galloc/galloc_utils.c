#include "../../includes/galloc.h"

void	*add_galloc_arr(void **mem)
{
	int		i;

	i = -1;

	while (mem[++i])
	{
		//printf("%p\n", mem[i]);
		add_galloc(mem[i]);
	}
	//printf("%p\n", mem);
	add_galloc(mem);
	return (mem);
}

void	gfree_arr(void **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
	{
		if (arr[i])
			gfree(arr[i]);
	}
	if (arr)
		gfree(arr);
}

void	terminate_error(char *text_error)
{
	ft_putendl_fd(text_error, 2);
	terminate(1);
}
