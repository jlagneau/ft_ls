/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 08:34:28 by jlagneau          #+#    #+#             */
/*   Updated: 2013/12/02 16:22:17 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_str.h>

static int	ft_nbrlen(int n)
{
	int		i;
	int		nb;

	i = 0;
	nb = n;
	if (n == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return ((n < 0) ? i + 1 : i);
}

char		*ft_itoa(int n)
{
	int		nvalue;
	int		nbrlen;
	char	*tmp;

	nvalue = n;
	nbrlen = ft_nbrlen(n);
	tmp = ft_strnew(nbrlen);
	while (nbrlen--)
	{
		tmp[nbrlen] = (n < 0) ? (n % 10) * -1 + 48 : (n % 10) + 48;
		n /= 10;
	}
	if (nvalue < 0)
		tmp[0] = '-';
	return (tmp);
}
