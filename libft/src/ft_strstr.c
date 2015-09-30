/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 08:39:35 by jlagneau          #+#    #+#             */
/*   Updated: 2013/12/02 17:41:59 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mem.h>
#include <ft_str.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*src;
	int		len;

	if (!*s1 && !*s2)
		return ((char *)s1);
	src = (char *)s1;
	len = ft_strlen(s2);
	while (*src)
	{
		if (ft_memcmp(src++, s2, len) == 0)
			return (src - 1);
	}
	return (0);
}
