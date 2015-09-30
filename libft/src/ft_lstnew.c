/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 18:50:05 by jlagneau          #+#    #+#             */
/*   Updated: 2013/12/02 17:36:22 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mem.h>
#include <ft_list.h>

t_list		*ft_lstnew(void const *content, t_size content_size)
{
	t_list	*ret;

	ret = 0;
	if (!(ret = (t_list *)ft_memalloc(sizeof(t_list))))
		return (0);
	if (content == 0)
	{
		ret->content = 0;
		ret->content_size = 0;
	}
	else
	{
		if (!(ret->content = (t_list *)ft_memalloc(content_size)))
		{
			ft_memdel((void **)&ret);
			return (0);
		}
		ret->content = ft_memcpy(ret->content, content, content_size);
		ret->content_size = content_size;
	}
	ret->next = 0;
	return (ret);
}
