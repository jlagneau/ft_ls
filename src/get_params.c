#include <stdlib.h>
#include <errno.h>
#include <libft.h>
#include "ft_ls.h"

static void				parse_params(char *av, char **params, t_bool is_param)
{
	static int			i = 0;

	if (av[0] != '-' || is_param == TRUE)
	{
		if (!(params[i] = ft_strnew(ft_strlen(av))))
			print_error(errno);
		ft_strcpy(params[i], av);
		i++;
	}
}

char					**get_params(int ac, char **av)
{
	int					i;
	t_bool				is_param;
	char				**params;

	i = 1;
	params = NULL;
	is_param = FALSE;
	if (ac == 1)
		return (NULL);
	if (!(params = (char**)ft_memalloc(ac * sizeof(char*))))
		print_error(errno);
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "--"))
		{
			i++;
			is_param = TRUE;
			continue ;
		}
		parse_params(av[i], params, is_param);
		i++;
	}
	return (params);
}
