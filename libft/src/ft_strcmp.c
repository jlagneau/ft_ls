/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 08:32:06 by jlagneau          #+#    #+#             */
/*   Updated: 2013/12/02 17:39:14 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mem.h>
#include <ft_str.h>

int		ft_strcmp(const char *s1, const char *s2)
{
	if (ft_strlen(s1) == ft_strlen(s2))
		return ((int)ft_memcmp(s1, s2, ft_strlen(s1)));
	else if (ft_strlen(s1) > ft_strlen(s2))
		return ((int)ft_memcmp(s1, s2, ft_strlen(s1)));
	else
		return ((int)ft_memcmp(s1, s2, ft_strlen(s2)));
}
