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
#include <unistd.h>
#include <errno.h>
#include <libft.h>
#include "ft_ls.h"

static void				set_link_dest(t_file *file_tmp)
{
	char	*linkname;
	char	*file_path;
	int		r;

	linkname = NULL;
	if (!(linkname = ft_strnew(file_tmp->stat->st_size)))
		print_mem_error(errno);
	file_path = set_file_path(file_tmp->name, file_tmp->path);
	if ((r = readlink(file_path, linkname, file_tmp->stat->st_size + 1)) == -1)
		print_link_error(file_path, errno);
	ft_strdel(&file_path);
	linkname[r] = '\0';
	file_tmp->link_dest = linkname;
}

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

static int				set_stat(t_file *file)
{
	char				*tmp;
	t_stat				*stat;

	stat = NULL;
	if (!(stat = (t_stat*)ft_memalloc(sizeof(t_stat))))
		print_mem_error(errno);
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
	if (!(tmp = ft_strdup(filename)))
		print_mem_error(errno);
	file_tmp->name = tmp;
}

void					set_file(char *filename, char *path, t_list **files)
{
	t_file				*file_tmp;
	t_list				*files_tmp;

	file_tmp = NULL;
	if (!(file_tmp = (t_file*)ft_memalloc(sizeof(t_file))))
		print_mem_error(errno);
	set_path(filename, path, file_tmp);
	set_name(filename, file_tmp);
	if (set_stat(file_tmp))
	{
		ft_strdel(&file_tmp->name);
		ft_memdel((void**)&file_tmp);
		return ;
	}
	if ((file_tmp->stat->st_mode & S_IFMT) == S_IFLNK)
		set_link_dest(file_tmp);
	if (*files == NULL)
		*files = ft_lstnew(file_tmp, sizeof(t_file));
	else
	{
		files_tmp = ft_lstnew(file_tmp, sizeof(t_file));
		ft_lstadd(files, files_tmp);
	}
}
