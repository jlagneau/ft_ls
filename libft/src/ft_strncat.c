/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 08:31:08 by jlagneau          #+#    #+#             */
/*   Updated: 2013/11/26 19:31:17 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_str.h>

char	*ft_strncat(char *s1, const char *s2, t_size n)
{
	char		*d;
	const char	*s;

	d = s1;
	s = s2;
	d += ft_strlen(d);
	while (n-- && *s)
		*d++ = *s++;
	*d = '\0';
	return (s1);
}
