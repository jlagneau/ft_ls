/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 08:49:24 by jlagneau          #+#    #+#             */
/*   Updated: 2015/10/04 08:49:24 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_ls.h"

static t_pair	*get_file_types(void)
{
	static t_pair file_types[8] = {
		{ S_IFBLK, 'b' },
		{ S_IFCHR, 'c' },
		{ S_IFDIR, 'd' },
		{ S_IFIFO, 'f' },
		{ S_IFLNK, 'l' },
		{ S_IFREG, '-' },
		{ S_IFSOCK, 's' },
		{ 0, 0 }
	};

	return (file_types);
}

static void		print_type_letter(int octal)
{
	int			i;
	t_pair		*file_types;

	i = 0;
	file_types = get_file_types();
	while (file_types[i].type)
	{
		if ((octal & S_IFMT) == file_types[i].type)
			ft_putchar(file_types[i].letter);
		i++;
	}
}

static void		print_mode_letter(char letter, int mode)
{
	if (mode)
		ft_putchar(letter);
	else
		ft_putchar('-');
}

void			print_mode(int octal)
{
	print_type_letter(octal);
	print_mode_letter('r', (octal & 0400) >> 8);
	print_mode_letter('w', (octal & 0200) >> 7);
	print_mode_letter('x', (octal & 0100) >> 6);
	print_mode_letter('r', (octal & 0040) >> 5);
	print_mode_letter('w', (octal & 0020) >> 4);
	print_mode_letter('x', (octal & 0010) >> 3);
	print_mode_letter('r', (octal & 0004) >> 2);
	print_mode_letter('w', (octal & 0002) >> 1);
	print_mode_letter('x', octal & 0001);
	ft_putchar(' ');
}
