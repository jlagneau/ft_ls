/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 08:47:32 by jlagneau          #+#    #+#             */
/*   Updated: 2015/10/04 08:47:33 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_ls.h"

void		print_name(t_list *file)
{
	if (IS_DIR(file))
		ft_putstr("\033[1;34m");
	else if (IS_LNK(file))
		ft_putstr("\033[36m");
	else if (IS_CHR(file))
		ft_putstr("\033[1;33m");
	else if (IS_FIFO(file))
		ft_putstr("\033[33m");
	else if (IS_SOCK(file))
		ft_putstr("\033[35m");
	ft_putstr(NAME(file));
	ft_putstr("\033[0m");
}
