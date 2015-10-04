/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 08:47:16 by jlagneau          #+#    #+#             */
/*   Updated: 2015/10/04 08:47:20 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <libft.h>
#include "ft_ls.h"

static void				set_path(char *filename, char *path, t_file *file_tmp)
{
	if (path)
		file_tmp->path = ft_strdup(path);
	else
	{
		if (filename[0] != '/')
			file_tmp->path = ft_strdup(".");
		else
			file_tmp->path = NULL;
	}
}

static int 				set_stat(t_file *file)
{
	char				*tmp;
	t_stat				*stat;

	stat = NULL;
	if (!(stat = (t_stat*)ft_memalloc(sizeof(t_stat))))
		print_error(errno);
	if (lstat((tmp = set_file_path(file->name, file->path)), stat) == -1)
	{
		ft_putendl_fd(tmp, 2);
		print_stat_error(file->name, errno);
		return (1);
	}
	ft_strdel(&tmp);
	file->stat = stat;
	return (0);
}

static void				set_name(char *filename, t_file *file_tmp)
{
	char				*tmp;

	tmp = NULL;
	if (!(tmp = ft_strnew(ft_strlen(filename))))
		print_error(errno);
	ft_strcpy(tmp, filename);
	file_tmp->name = tmp;
}

void					set_file(char *filename, char *path, t_list **files)
{
	t_file				*file_tmp;
	t_list				*files_tmp;

	file_tmp = NULL;
	if (!(file_tmp = (t_file*)ft_memalloc(sizeof(t_file))))
		print_error(errno);
	set_path(filename, path, file_tmp);
	set_name(filename, file_tmp);
	if (set_stat(file_tmp))
	{
		ft_strdel(&file_tmp->name);
		ft_memdel((void**)&file_tmp);
		return ;
	}
	if (*files == NULL)
		*files = ft_lstnew(file_tmp, sizeof(t_file));
	else
	{
		files_tmp = ft_lstnew(file_tmp, sizeof(t_file));
		ft_lstadd(files, files_tmp);
	}
}
