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
	t_pw	*ppassword;
	t_grp	*pgroup;

	ppassword = NULL;
	ppassword = getpwuid(UID(file));
	ft_putstr(ppassword->pw_name);
	pad = padding->user - ft_strlen(ppassword->pw_name);
	while (pad--)
		ft_putchar(' ');
	ft_putchar(' ');
	pgroup = NULL;
	pgroup = getgrgid(GID(file));
	ft_putstr(pgroup->gr_name);
	pad = padding->group - ft_strlen(pgroup->gr_name);
	while (pad--)
		ft_putchar(' ');
	ft_putchar(' ');
}
