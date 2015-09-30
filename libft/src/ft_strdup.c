/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 08:38:24 by jlagneau          #+#    #+#             */
/*   Updated: 2013/11/26 13:54:29 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mem.h>
#include <ft_str.h>

char	*ft_strdup(const char *s)
{
	char	*dest;
	t_size	len;

	dest = 0;
	len = ft_strlen(s);
	dest = ft_strnew(len);
	if (dest == 0)
		return (0);
	ft_memcpy(dest, s, len + 1);
	return (dest);
}
