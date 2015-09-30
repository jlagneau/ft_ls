/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 08:36:28 by jlagneau          #+#    #+#             */
/*   Updated: 2013/12/08 21:31:11 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list.h>

void		ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (!*alst)
		*alst = new;
	else
	{
		tmp = ft_lstlast(*alst);
		tmp->next = new;
	}
}
