/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_link_dest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 08:49:19 by jlagneau          #+#    #+#             */
/*   Updated: 2015/10/04 08:49:20 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_ls.h"

void		print_link_dest(t_list *file)
{
	if (IS_LNK(file))
	{
		ft_putstr(" -> ");
		ft_putstr(LINK_DEST(file));
	}
}
