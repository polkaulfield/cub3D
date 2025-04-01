
#include "../includes/errors.h"
#include "../includes/galloc.h"

void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	terminate(EXIT_FAILURE);
}
