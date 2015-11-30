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
#include <errno.h>
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

static void		get_directories_rec(t_list *params, t_list **directories)
{
	t_list		*i;
	t_list		*tmp;

	tmp = NULL;
	i = params;
	while (i)
	{
		if (IS_DIR(i) && IS_DOT_FILE(NAME(i)))
		{
			if (*directories == NULL)
			{
				if (!(*directories = ft_lstnew(i->content, sizeof(t_file))))
					print_mem_error(errno);
			}
			else
			{
				if (!(tmp = ft_lstnew(i->content, sizeof(t_file))))
					print_mem_error(errno);
				ft_lstadd(directories, tmp);
			}
		}
		i = i->next;
	}
}

void			print_recursive(t_list *files, t_list *path, int c, int options)
{
	t_list		*dir;

	dir = NULL;
	get_directories_rec(files, &dir);
	add_path(dir, path);
	sort(dir, options);
	if (dir)
		print_directories(dir, c, options);
}
