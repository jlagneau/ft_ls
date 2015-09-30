/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 08:30:35 by jlagneau          #+#    #+#             */
/*   Updated: 2013/12/02 17:41:19 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_str.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*src;

	src = (char *)s + ft_strlen(s);
	while (*src != (char)c)
	{
		if (src == s)
			return (0);
		src--;
	}
	return (src);
}
