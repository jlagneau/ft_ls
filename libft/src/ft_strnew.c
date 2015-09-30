/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 08:30:44 by jlagneau          #+#    #+#             */
/*   Updated: 2013/12/02 17:40:39 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mem.h>

char	*ft_strnew(t_size size)
{
	char	*tmp;

	if (!(tmp = (char *)ft_memalloc(size + 1)))
		return (0);
	return (tmp);
}
