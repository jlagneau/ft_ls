#include <stdlib.h>
#include <string.h>
#include <libft.h>

void	print_error(int err)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putendl_fd(strerror(err), 2);
	exit(1);
}
