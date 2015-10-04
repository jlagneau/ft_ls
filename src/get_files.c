/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 08:48:21 by jlagneau          #+#    #+#             */
/*   Updated: 2015/10/04 08:48:23 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <libft.h>
#include "ft_ls.h"
//
// static void		is_hidden(char *name, t_list **file, int options)
// {
// 	if (name[0] == '.' && options & ALL_OPTION_MASK)
// 		set_file(name, file);
// 	else if (name[0] != '.')
// 		set_file(name, file);
// }
//
// static void		has_directory(t_list *file)
// {
// 	t_list		*tmp;
//
// 	tmp = file;
// 	while (tmp)
// 	{
// 		if (!ft_strcmp(NAME(tmp), ".") || !ft_strcmp(NAME(tmp), ".."))
// 		{
// 			tmp = tmp->next;
// 			continue ;
// 		}
// 		// if (IS_DIR(tmp))
// 		// 	recursive(tmp, path, options);
// 		tmp = tmp->next;
// 	}
// }
//
// void			get_directory_files_list(char *path, int options)
// {
// 	DIR			*pDir;
// 	t_dir		*pDirent;
// 	t_list		*file;
//
// 	file = NULL;
// 	pDir = NULL;
// 	pDirent = NULL;
// 	if ((pDir = opendir(path)))
// 	{
// 		while ((pDirent = readdir(pDir)))
// 		{
// 			if (pDirent)
// 				is_hidden(pDirent->d_name, &file, options);
// 			else
// 				print_error(errno);
// 		}
// 		sort(file, options);
// 		print(file, options);
// 		if (options & RECURSIVE_OPTION_MASK)
// 			has_directory(file);
// 		closedir(pDir);
// 	}
// 	else
// 		print_error(errno);
// }
//
// void			get_file(t_list *files, int options)
// {
// 	t_list		*tmp;
// 	t_size		size;
//
// 	tmp = files;
// 	size = ft_lstlen(files);
// 	while (tmp)
// 	{
// 		if (size > 1 || options & RECURSIVE_OPTION_MASK)
// 		{
// 			ft_putstr(NAME(tmp));
// 			ft_putendl(":");
// 		}
// 		get_directory_files_list(NAME(tmp), options);
// 		if (tmp->next)
// 			ft_putchar('\n');
// 		tmp = tmp->next;
// 	}
// }

void			get_files(t_list *params, t_list **files)
{
	t_list		*i;
	t_list		*tmp;

	tmp = NULL;
	i = params;
	while (i)
	{
		if (!(IS_DIR(i)))
		{
			if (*files == NULL)
			{
				if (!(*files = ft_lstnew(i->content, sizeof(t_file))))
					print_error(errno);
			}
			else
			{
				if (!(tmp = ft_lstnew(i->content, sizeof(t_file))))
					print_error(errno);
				ft_lstadd(files, tmp);
			}
		}
		i = i->next;
	}
}
