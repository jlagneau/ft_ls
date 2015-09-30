/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 08:35:38 by jlagneau          #+#    #+#             */
/*   Updated: 2013/12/02 17:35:02 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_str.h>

static int		ft_exp_ten(int n)
{
	int			i;
	int			ret;

	i = 0;
	ret = 1;
	while (i++ < n)
		ret *= 10;
	return (ret);
}

static char		*ft_strip_front_spaces(char *s)
{
	while (ft_isspace(*s))
		s++;
	return (s);
}

static int		ft_strip_front_sign(char *s)
{
	if (*s == '-')
		return (-1);
	return (1);
}

int				ft_atoi(const char *str)
{
	int			op;
	int			ret;
	int			i;
	char		*s;

	s = (char *)str;
	op = 1;
	ret = 0;
	i = 0;
	s = ft_strip_front_spaces(s);
	if (*s == '-' || *s == '+')
	{
		op = ft_strip_front_sign(s);
		s++;
	}
	while (s[i] > 47 && s[i] < 58)
		i++;
	while (i-- > 0)
		ret += ((*(s++) - '0') * ft_exp_ten(i));
	return (ret * op);
}
