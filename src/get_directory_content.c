/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_directory_content.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 08:48:53 by jlagneau          #+#    #+#             */
/*   Updated: 2015/10/04 08:48:54 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#include <libft.h>
#include "ft_ls.h"

static void		is_hidden(char *name, t_list **file, char *path, int options)
{
	if (name[0] == '.' && options & ALL_OPTION_MASK)
		set_file(name, path, file);
	else if (name[0] != '.')
		set_file(name, path, file);
}

void			get_directory_content(t_list *dir, t_list **files, int options)
{
	DIR			*pDir;
	t_dir		*pDirent;
	char		*tmp;

	pDir = NULL;
	pDirent = NULL;
	if (!(tmp = set_file_path(NAME(dir), PATH(dir))))
		print_mem_error(errno);
	if ((pDir = opendir(tmp)))
	{
		while ((pDirent = readdir(pDir)))
		{
			if (pDirent)
				is_hidden(pDirent->d_name, files, tmp, options);
			else
				print_mem_error(errno);
		}
		ft_strdel(&tmp);
		sort(*files, options);
		closedir(pDir);
	}
	else
		print_opendir_error(tmp, errno);
}
