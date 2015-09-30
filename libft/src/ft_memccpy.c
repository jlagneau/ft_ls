/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 08:33:58 by jlagneau          #+#    #+#             */
/*   Updated: 2013/12/02 17:37:26 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_def.h>

void	*ft_memccpy(void *s1, const void *s2, int c, t_size n)
{
	unsigned char			*d;
	const unsigned char		*s;

	d = s1;
	s = s2;
	while (n--)
	{
		if (*s == (unsigned char)c)
		{
			*d++ = *s++;
			return (d);
		}
		*d++ = *s++;
	}
	return (0);
}
