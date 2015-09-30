/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 08:36:28 by jlagneau          #+#    #+#             */
/*   Updated: 2013/12/08 21:31:11 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list.h>

t_size	ft_lstlen(t_list *lst)
{
	t_size	i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	if (!lst)
		return (i);
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
