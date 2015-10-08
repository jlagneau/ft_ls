/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 08:47:26 by jlagneau          #+#    #+#             */
/*   Updated: 2015/10/04 08:47:27 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <sys/types.h>
#include "ft_ls.h"

void		print_size(t_list *file, t_padding *padding)
{
	t_size		pad;

	if (IS_CHR(file) || IS_BLK(file))
	{
		pad = padding->major - ft_nbrlen(major(RDEV(file)));
		while (pad--)
			ft_putchar(' ');
		ft_putnbr(major(RDEV(file)));
		ft_putstr(", ");
		pad = padding->minor - ft_nbrlen(minor(RDEV(file)));
		while (pad--)
			ft_putchar(' ');
		ft_putnbr(minor(RDEV(file)));
	}
	else
	{
		pad = padding->size - ft_nbrlen(SIZE(file));
		while (pad--)
			ft_putchar(' ');
		ft_putnbr(SIZE(file));
	}
	ft_putchar(' ');
}
