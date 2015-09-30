/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 08:36:28 by jlagneau          #+#    #+#             */
/*   Updated: 2013/12/08 21:31:11 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_str.h>

char			*ft_strrealloc(char **s, t_size new_size)
{
	char		*tmp;

	if (!*s)
	{
		if (!(*s = ft_strnew(new_size)))
			return (0);
		return (*s);
	}
	if (!(tmp = ft_strnew(new_size)))
		return (0);
	tmp = (char *)ft_strncpy(tmp, *s, ft_strlen(*s));
	ft_strdel(s);
	*s = tmp;
	return (*s);
}
