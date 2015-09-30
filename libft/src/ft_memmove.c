/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 08:37:17 by jlagneau          #+#    #+#             */
/*   Updated: 2013/11/24 10:12:35 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mem.h>

void	*ft_memmove(void *s1, const void *s2, t_size n)
{
	char		*tmp;

	if (!(tmp = ft_memalloc(n)))
		return (0);
	ft_memcpy(tmp, s2, n);
	ft_memcpy(s1, tmp, n);
	ft_memdel((void**)&tmp);
	return (s1);
}
