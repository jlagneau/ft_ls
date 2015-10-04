/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 08:49:10 by jlagneau          #+#    #+#             */
/*   Updated: 2015/10/04 08:49:10 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_ls.h"

static t_size	max_link_len(t_list *files)
{
	t_list		*tmp;
	t_size		padding;

	tmp = files;
	padding = 0;
	while (tmp)
	{
		if (padding < ft_nbrlen(LINK(tmp)))
			padding = ft_nbrlen(LINK(tmp));
		tmp = tmp->next;
	}
	return (padding);
}

static t_size	max_user_len(t_list *files)
{
	t_list		*tmp;
	t_size		padding;
	t_pw		*pPassword;

	tmp = files;
	padding = 0;
	while (tmp)
	{
		pPassword = getpwuid(UID(tmp));
		if (padding < ft_strlen(pPassword->pw_name))
			padding = ft_strlen(pPassword->pw_name);
		tmp = tmp->next;
	}
	return (padding);
}

static t_size	max_group_len(t_list *files)
{
	t_list		*tmp;
	t_size		padding;
	t_grp		*pGroup;

	tmp = files;
	padding = 0;
	while (tmp)
	{
		pGroup = getgrgid(GID(tmp));
		if (padding < ft_strlen(pGroup->gr_name))
			padding = ft_strlen(pGroup->gr_name);
		tmp = tmp->next;
	}
	return (padding);
}

static void		max_size_len(t_list *files, t_padding *padding)
{
	t_list		*tmp;

	tmp = files;
	padding->size = 0;
	padding->minor = 0;
	padding->major = 0;
	while (tmp)
	{
		if (IS_CHR(tmp) || IS_BLK(tmp))
		{
			if (padding->minor < ft_nbrlen(MINOR(RDEV(tmp))))
				padding->minor = ft_nbrlen(MINOR(RDEV(tmp)));
			if (padding->major < ft_nbrlen(MAJOR(RDEV(tmp))))
				padding->major = ft_nbrlen(MAJOR(RDEV(tmp)));
			padding->size = padding->minor + padding->major + 2;
		}
		if (padding->size < ft_nbrlen(SIZE(tmp)))
			padding->size = ft_nbrlen(SIZE(tmp));
		tmp = tmp->next;
	}
}

void			padding(t_list *files, t_padding *padding)
{
	padding->link = max_link_len(files);
	padding->user = max_user_len(files);
	padding->group = max_group_len(files);
	max_size_len(files, padding);
}
