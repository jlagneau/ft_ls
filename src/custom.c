/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 08:48:40 by jlagneau          #+#    #+#             */
/*   Updated: 2015/10/04 08:48:41 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_ls.h"

static char			custom_tolower(char c)
{
	if (c > 64 && c < 91)
		return (c + 32);
	return (c);
}

t_size				ft_nbrlen(int n)
{
	t_size			i;

	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int					strcmp_case_i(char *s1, char *s2)
{
	char			*tmp1;
	char			*tmp2;
	char			*tmps1;
	char			*tmps2;
	int				ret;

	tmps1 = ft_strmap(s1, &custom_tolower);
	tmps2 = ft_strmap(s2, &custom_tolower);
	tmp1 = tmps1;
	tmp2 = tmps2;
	while (tmp1)
		if (tmp1[0] == '.' && IS_DOT_FILE(tmp1))
			tmp1++;
		else
			break ;
	while (tmp2)
		if (tmp2[0] == '.' && IS_DOT_FILE(tmp2))
			tmp2++;
		else
			break ;
	ret = ft_strcmp(tmp1, tmp2);
	ft_strdel(&tmps1);
	ft_strdel(&tmps2);
	return (ret);
}
