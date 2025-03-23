#include "../../includes/galloc.h"

void	*add_galloc_arr(void **mem)
{
	void	**temp_mem;

	temp_mem = mem;
	add_galloc(temp_mem);
	while (*temp_mem)
	{
		add_galloc(*temp_mem);
		temp_mem++;
	}
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
