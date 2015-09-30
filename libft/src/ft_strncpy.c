/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 08:30:53 by jlagneau          #+#    #+#             */
/*   Updated: 2013/12/01 16:23:00 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mem.h>

char	*ft_strncpy(char *s1, const char *s2, t_size n)
{
	t_size	i;

	if (!s1 && !s2)
		return (0);
	i = 0;
	ft_bzero(s1, n);
	while (s2[i] && i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}
