/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:04:53 by jlagneau          #+#    #+#             */
/*   Updated: 2013/11/25 14:14:51 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_str.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	int		i;

	if (s == 0 && f == 0)
		return (0);
	i = 0;
	ret = ft_strnew(ft_strlen(s));
	while (s[i])
	{
		ret[i] = f(s[i]);
		i++;
	}
	return (ret);
}
