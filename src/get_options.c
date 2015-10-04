/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 08:48:59 by jlagneau          #+#    #+#             */
/*   Updated: 2015/10/04 08:48:59 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_ls.h"

static t_options		*get_options_list(void)
{
	static t_options	opt[6] = {
		{ LONG_OPTION_MASK,      'l' },
		{ RECURSIVE_OPTION_MASK, 'R' },
		{ ALL_OPTION_MASK,       'a' },
		{ REVERSE_OPTION_MASK,   'r' },
		{ TIME_OPTION_MASK,      't' },
		{ 0,                    '\0' }
	};
	return (opt);
}

static int				set_options(char av, int options)
{
	int					i;
	t_options			*option_list;

	i = 0;
	option_list = get_options_list();
	while (option_list[i].letter)
	{
		if (av == option_list[i].letter)
		{
			if (!(options & option_list[i].mask))
				options ^= option_list[i].mask;
		}
		i++;
	}
	return (options);
}

static int				parse_options(char *av, int options)
{
	int					i;

	i = 0;
	if (av[i] == '-')
	{
		i = 1;
		while (av[i])
		{
			options = set_options(av[i], options);
			i++;
		}
	}
	return (options);
}

int						get_options(int ac, char **av)
{
	int					i;
	int					options;

	i = 0;
	options = 0;
	while (i < ac && ft_strcmp(av[i], "--"))
	{
		options = parse_options(av[i], options);
		i++;
	}
	return (options);
}
