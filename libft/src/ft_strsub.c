/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 09:08:36 by jlagneau          #+#    #+#             */
/*   Updated: 2013/11/25 15:39:03 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_str.h>

char	*ft_strsub(char const *s, unsigned int start, t_size len)
{
	char	*sub;
	t_size	i;

	if (s == 0)
		return (0);
	if (!(sub = ft_strnew(len)))
		return (0);
	i = 0;
	while (len--)
	{
		sub[i] = *(s + start + i);
		i++;
	}
	return (sub);
}
