/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 08:36:28 by jlagneau          #+#    #+#             */
/*   Updated: 2013/11/21 08:36:31 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mem.h>
#include <stdlib.h>

void	*ft_memalloc(t_size size)
{
	char	*tmp;

	if (size < 1)
		return (0);
	tmp = 0;
	if (!(tmp = malloc(size)))
		return (0);
	ft_bzero(tmp, size);
	return (tmp);
}
