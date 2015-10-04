/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_file_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 08:49:37 by jlagneau          #+#    #+#             */
/*   Updated: 2015/10/04 08:49:38 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include <libft.h>
#include "ft_ls.h"

char					*set_file_path(char *name, char *path)
{
	char				*tmp;
	char				*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	if (!path)
		return (ft_strdup(name));
	if (!ft_strcmp(path, "."))
		return (ft_strdup(name));
	if (!ft_strcmp(path, "/"))
		return (ft_strjoin("/", name));
	if (!(tmp = ft_strdup(path)))
		print_mem_error(errno);
	if (tmp[ft_strlen(tmp)] != '/')
	{
		tmp2 = ft_strjoin(tmp, "/");
		ft_strdel(&tmp);
		tmp = tmp2;
	}
	tmp2 = ft_strjoin(tmp, name);
	ft_strdel(&tmp);
	return (tmp2);
}
