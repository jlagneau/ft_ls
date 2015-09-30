/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 08:31:17 by jlagneau          #+#    #+#             */
/*   Updated: 2013/12/02 17:39:45 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_str.h>

t_size	ft_strlcat(char *dst, const char *src, t_size size)
{
	char	*d;
	char	*s;
	t_size	n;
	t_size	len_dst;

	n = size;
	d = dst;
	s = (char *)src;
	while (n-- != 0 && *d != '\0')
		d++;
	len_dst = d - dst;
	n = size - len_dst;
	if (n == 0)
		return (len_dst + ft_strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (len_dst + (s - src));
}
