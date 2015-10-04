/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 08:47:44 by jlagneau          #+#    #+#             */
/*   Updated: 2015/10/04 08:47:45 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_ls.h"

void 		print_link(t_list *file, t_padding *padding)
{
	t_size		pad;

	pad = padding->link - ft_nbrlen(LINK(file));
	while (pad--)
		ft_putchar(' ');
	ft_putnbr(LINK(file));
	ft_putchar(' ');
}
