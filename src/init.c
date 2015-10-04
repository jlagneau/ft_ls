/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 08:49:05 by jlagneau          #+#    #+#             */
/*   Updated: 2015/10/04 08:49:06 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include <libft.h>
#include "ft_ls.h"

static void		print_params(t_list *params, int options)
{
	t_list		*files;
	t_list		*directories;
	int			i;

	files = NULL;
	get_files(params, &files);
	if (files)
	{
		i = 1;
		print(files, options);
	}
	ft_lstdel(&files, &free_file);
	directories = NULL;
	get_directories(params, &directories);
	if (directories)
	{
		i += ft_lstlen(directories);
		print_directories(directories, i, options);
	}
	ft_lstdel(&directories, &free_file);
}

void			init(int ac, char **av)
{
	int		options;
	t_list	*params;

	options = get_options(ac, av);
	params = get_params(ac, av);
	sort(params, options);
	print_params(params, options);
}
