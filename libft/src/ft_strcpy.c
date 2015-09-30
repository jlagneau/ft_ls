/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 08:38:17 by jlagneau          #+#    #+#             */
/*   Updated: 2013/11/25 16:28:37 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mem.h>
#include <ft_str.h>

char	*ft_strcpy(char *s1, const char *s2)
{
	t_size	len;

	len = ft_strlen(s2);
	ft_bzero(s1, len + 1);
	ft_memcpy(s1, s2, len);
	return (s1);
}
