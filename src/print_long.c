/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 08:47:38 by jlagneau          #+#    #+#             */
/*   Updated: 2015/10/04 08:47:39 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <time.h>
#include <libft.h>
#include "ft_ls.h"

static void		print_file_long(t_list *file, t_padding *padding)
{
	print_mode(MODE(file));
	print_link(file, padding);
	print_user_group(file, padding);
	print_size(file, padding);
	print_date(file);
	print_name(file);
	print_link_dest(file);
	ft_putchar('\n');
}

void			print_long(t_list *files)
{
	t_list		*tmp;
	t_padding	pad;

	tmp = files;
	padding(files, &pad);
	while (tmp)
	{
		print_file_long(tmp, &pad);
		tmp = tmp->next;
	}
}
