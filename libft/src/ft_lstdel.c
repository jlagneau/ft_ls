/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 21:11:12 by jlagneau          #+#    #+#             */
/*   Updated: 2013/12/01 21:15:17 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mem.h>
#include <ft_list.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, t_size))
{
	t_list *prev;

	if (!alst && !del)
		return ;
	while (*alst != 0)
	{
		del((*alst)->content, (*alst)->content_size);
		prev = *alst;
		*alst = (*alst)->next;
		ft_memdel((void**)prev);
	}
	*alst = 0;
}
