/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 08:46:54 by jlagneau          #+#    #+#             */
/*   Updated: 2015/10/04 08:47:03 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_ls.h"

static void			swap(t_list *file1, t_list *file2)
{
	t_file			*tmp;

	tmp = (t_file*)file1->content;
	file1->content = file2->content;
	file2->content = tmp;
}

static void			sort_time(t_list *file, int options)
{
	t_list			*tmp;
	t_size			size;

	size = ft_lstlen(file);
	size++;
	while (size--)
	{
		tmp = file;
		while (tmp->next)
		{
			if (options & REVERSE_OPTION_MASK)
			{
				if (TIME(tmp) > TIME(tmp->next))
					swap(tmp, tmp->next);
			}
			else
			{
				if (TIME(tmp) < TIME(tmp->next))
					swap(tmp, tmp->next);
			}
			tmp = tmp->next;
		}
	}
}

static void			sort_name(t_list *file, int options)
{
	t_list			*tmp;
	t_size			size;

	size = ft_lstlen(file);
	size++;
	while (size--)
	{
		tmp = file;
		while (tmp->next)
		{
			if (options & REVERSE_OPTION_MASK)
			{
				if (ft_strcmp(NAME(tmp), NAME(tmp->next)) < 0)
					swap(tmp, tmp->next);
			}
			else
			{
				if (ft_strcmp(NAME(tmp), NAME(tmp->next)) > 0)
					swap(tmp, tmp->next);
			}
			tmp = tmp->next;
		}
	}
}

void				sort(t_list *file, int options)
{
	if (!file || !file->next)
		return ;
	if (!(options & TIME_OPTION_MASK))
		sort_name(file, options);
	else
		sort_time(file, options);
}
