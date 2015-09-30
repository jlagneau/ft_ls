/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 09:40:36 by jlagneau          #+#    #+#             */
/*   Updated: 2013/11/26 16:02:44 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_str.h>

static int		ft_iswhitespace(int c)
{
	if (c == 9 || c == 10 || c == 32)
		return (1);
	return (0);
}

static char		*ft_strip_front_spaces(char *s)
{
	while (ft_iswhitespace(*s))
		s++;
	return (s);
}

static char		*ft_strip_back_spaces(char *s)
{
	t_size		len;

	len = ft_strlen(s) - 1;
	while (ft_iswhitespace(s[len]))
		s[len--] = '\0';
	return (s);
}

char			*ft_strtrim(char const *s)
{
	char	*tmp;
	char	*cpy;
	char	*ret;

	if (!s)
		return (0);
	cpy = ft_strdup(s);
	tmp = cpy;
	tmp = ft_strip_front_spaces(tmp);
	tmp = ft_strip_back_spaces(tmp);
	ret = ft_strdup(tmp);
	ft_strdel(&cpy);
	return (ret);
}
