/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_total.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 13:29:36 by jlagneau          #+#    #+#             */
/*   Updated: 2015/10/04 13:29:37 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_ls.h"

void		print_total(t_list *files)
{
	t_list	*i;
	int		total;

	i = files;
	total = 0;
	while (i)
	{
		total += BLOCK(i);
		i = i->next;
	}
	ft_putstr("total ");
	ft_putnbr(total / 2);
	ft_putchar('\n');
}
