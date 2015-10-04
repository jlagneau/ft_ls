/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_user_group.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 08:49:32 by jlagneau          #+#    #+#             */
/*   Updated: 2015/10/04 08:49:33 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "ft_ls.h"

void		print_user_group(t_list *file, t_padding *padding)
{
	t_size	pad;
	t_pw	*pPassword;
	t_grp	*pGroup;

	pPassword = NULL;
	pPassword = getpwuid(UID(file));
	ft_putstr(pPassword->pw_name);
	pad = padding->user - ft_strlen(pPassword->pw_name);
	while (pad--)
		ft_putchar(' ');
	ft_putchar(' ');
	pGroup = NULL;
	pGroup = getgrgid(GID(file));
	ft_putstr(pGroup->gr_name);
	pad = padding->group - ft_strlen(pGroup->gr_name);
	while (pad--)
		ft_putchar(' ');
	ft_putchar(' ');
}
