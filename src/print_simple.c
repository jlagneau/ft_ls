/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_simple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 08:49:28 by jlagneau          #+#    #+#             */
/*   Updated: 2015/10/04 08:49:29 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_ls.h"

void		print_simple(t_list *files)
{
	t_list	*tmp;

	tmp = files;
	while (tmp)
	{
		print_name(tmp);
		ft_putstr("  ");
		tmp = tmp->next;
	}
	ft_putchar('\n');
}
