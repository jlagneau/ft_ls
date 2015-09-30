/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 08:39:02 by jlagneau          #+#    #+#             */
/*   Updated: 2013/12/02 17:40:03 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_def.h>

int		ft_strncmp(const char *s1, const char *s2, t_size n)
{
	unsigned char	*src1;
	unsigned char	*src2;

	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	while (n--)
	{
		if (*src1 != *src2)
			return (*src1 - *src2);
		if (!*src1)
			break ;
		src1++;
		src2++;
	}
	return (0);
}
