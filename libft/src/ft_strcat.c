/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 08:38:02 by jlagneau          #+#    #+#             */
/*   Updated: 2013/11/29 11:33:11 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_str.h>

char	*ft_strcat(char *s1, const char *s2)
{
	char		*d;
	const char	*s;

	d = s1;
	s = s2;
	d += ft_strlen(d);
	d = ft_strcpy(d, s);
	return (s1);
}
