/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:19:31 by jlagneau          #+#    #+#             */
/*   Updated: 2013/12/02 17:41:46 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mem.h>
#include <ft_str.h>

static char		*ft_strctrim(char const *s, char c)
{
	char	*src;
	char	*tmp;
	char	*ret;
	t_size	len;

	src = ft_strdup(s);
	tmp = src;
	while (*tmp == c)
		tmp++;
	len = ft_strlen(tmp) - 1;
	while (tmp[len] == c)
		tmp[len--] = '\0';
	ret = ft_strdup(tmp);
	ft_strdel(&src);
	return (ret);
}

static t_size	ft_strclen(char const *s, char c)
{
	t_size	len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

static int		ft_count_words(char const *s, char c)
{
	char const	*src;
	int			i;

	i = 0;
	src = s;
	while (*src)
	{
		if (*src == c)
		{
			while (*src == c && *src != '\0')
				src++;
		}
		else
		{
			while (*src != c && *src != '\0')
				src++;
			i++;
		}
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	*src_clean;
	char	*p;
	char	**ret;
	int		words;
	int		i;

	if (s == 0)
		return (0);
	i = 0;
	src_clean = ft_strctrim(s, c);
	p = src_clean;
	words = ft_count_words(src_clean, c);
	if (!(ret = (char **)ft_memalloc(sizeof(char *) * words + 1)))
		return (0);
	while (i < words)
	{
		while (*src_clean && *src_clean == c)
			src_clean++;
		ret[i] = ft_strsub(src_clean, 0, ft_strclen(src_clean, c));
		src_clean = src_clean + ft_strclen(src_clean, c);
		i++;
	}
	ret[words] = 0;
	ft_strdel(&p);
	return (ret);
}
