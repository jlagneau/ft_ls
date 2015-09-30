/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 08:33:19 by jlagneau          #+#    #+#             */
/*   Updated: 2013/12/02 17:38:36 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_def.h>

void		*ft_memset(void *s, int c, t_size n)
{
	char	*tmp;

	tmp = s;
	while (n--)
		*tmp++ = (unsigned char)c;
	return (s);
}
