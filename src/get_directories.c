/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_directories.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 08:48:26 by jlagneau          #+#    #+#             */
/*   Updated: 2015/10/04 08:48:27 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <libft.h>
#include "ft_ls.h"

void			get_directories(t_list *params, t_list **directories)
{
	t_list		*i;
	t_list		*tmp;

	tmp = NULL;
	i = params;
	while (i)
	{
		if (IS_DIR(i))
		{
			if (*directories == NULL)
			{
				if (!(*directories = ft_lstnew(i->content, sizeof(t_file))))
					print_error(errno);
			}
			else
			{
				if (!(tmp = ft_lstnew(i->content, sizeof(t_file))))
					print_error(errno);
				ft_lstadd(directories, tmp);
			}
		}
		i = i->next;
	}
}
