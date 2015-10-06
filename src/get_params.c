/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 08:48:01 by jlagneau          #+#    #+#             */
/*   Updated: 2015/10/04 08:48:02 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "ft_ls.h"

t_list					*get_params(int ac, char **av)
{
	int					i;
	t_bool				is_param;
	t_list				*params;

	i = 1;
	params = NULL;
	is_param = FALSE;
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "--"))
		{
			i++;
			is_param = TRUE;
			continue ;
		}
		if (av[i][0] != '-' || is_param == TRUE)
			set_file(av[i], NULL, &params);
		i++;
	}
	if (!params)
		set_file(".", NULL, &params);
	return (params);
}
