/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 08:29:44 by jlagneau          #+#    #+#             */
/*   Updated: 2014/05/13 13:09:06 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H
# include <ft_def.h>

typedef struct		s_list
{
	void			*content;
	t_size			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, t_size content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, t_size));
void				ft_lstdel(t_list **alst, void (*del)(void *, t_size));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_size				ft_lstlen(t_list *list);
void				ft_lstaddend(t_list **alst, t_list *new);
t_list				*ft_lstlast(t_list *alst);

#endif
