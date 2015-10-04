/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_link_dest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 08:49:19 by jlagneau          #+#    #+#             */
/*   Updated: 2015/10/04 08:49:20 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <libft.h>
#include "ft_ls.h"

void		print_link_dest(t_list *file)
{
	char	*linkname;
	char	*file_path;
	int		r;

	linkname = NULL;
	if (IS_LNK(file))
	{
		if (!(linkname = ft_strnew(SIZE(file))))
			print_error(errno);
		file_path = set_file_path(NAME(file), PATH(file));
		if ((r = readlink(file_path, linkname, SIZE(file) + 1)) == -1)
			print_error(errno);
		ft_strdel(&file_path);
		linkname[r] = '\0';
		ft_putstr(" -> ");
		ft_putstr(linkname);
	}
}
