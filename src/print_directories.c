/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_directories.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 10:03:10 by jlagneau          #+#    #+#             */
/*   Updated: 2015/10/04 10:03:18 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include <libft.h>
#include "ft_ls.h"

static void		print_directory_name(t_list *dir, int *c)
{
	static int	i = 0;

	if (i == 0 || *c < 2)
	{
		(*c)++;
		i++;
	}
	else
		ft_putstr("\n");
	if (PATH(dir) && ft_strcmp(PATH(dir), "."))
	{
		ft_putstr(PATH(dir));
		ft_putchar('/');
	}
	ft_putstr(NAME(dir));
	ft_putendl(":");
}

void			print_directories(t_list *dir, int c, int options)
{
	t_list		*i;
	t_list		*content;

	content = NULL;
	i = dir;
	while (i)
	{
		get_directory_content(i, &content, options);
		sort(content, options);
		if (c > 1)
			print_directory_name(i, &c);
		if (options & LONG_OPTION_MASK)
			print_total(content);
		print(content, options);
		ft_lstdel(&content, &free_file);
		i = i->next;
	}
}
