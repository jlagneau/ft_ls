/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_recursive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 10:04:40 by jlagneau          #+#    #+#             */
/*   Updated: 2015/10/04 10:04:44 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "ft_ls.h"

static void		add_path(t_list *dir, t_list *path)
{
	t_list		*i;
	char		*tmp;

	i = dir;
	while (i)
	{
		tmp = PATH(i);
		PATH(i) = set_file_path(NAME(path), PATH(path));
		if (tmp)
			ft_strdel(&tmp);
		i = i->next;
	}
}

void			print_recursive(t_list *files, t_list *path, int c, int options)
{
	t_list		*dir;

	dir = NULL;
	get_directories(files, &dir);
	add_path(dir, path);
	sort(dir, options);
	if (dir)
		print_directories(dir, c, options);
}
