/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 19:59:25 by jlagneau          #+#    #+#             */
/*   Updated: 2013/12/01 21:06:51 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mem.h>
#include <ft_list.h>

void	ft_lstdelone(t_list **alst, void (*del)(void *, t_size))
{
	if (alst == 0)
		return ;
	del((*alst)->content, (*alst)->content_size);
	ft_memdel((void**)alst);
	*alst = 0;
}
