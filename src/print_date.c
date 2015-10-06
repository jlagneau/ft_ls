/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_date.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 08:49:15 by jlagneau          #+#    #+#             */
/*   Updated: 2015/10/04 08:49:16 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <libft.h>
#include "ft_ls.h"

static char		*get_hour(char *datetime)
{
	char		*hour;

	hour = NULL;
	if (!(hour = ft_strnew(6)))
		print_mem_error(errno);
	hour = ft_strncpy(hour, datetime, 5);
	return (hour);
}

static char		*get_hour_or_year(t_list *file, char **parsed_date)
{
	time_t		rawtime;
	time_t		six_months;
	char		*ret;

	six_months = 15778463;
	time(&rawtime);
	if (rawtime - TIME(file) > six_months || TIME(file) - rawtime > six_months)
	{
		if (!(ret = ft_strnew(5)))
			print_mem_error(errno);
		ret = ft_strncpy(ret, parsed_date[4], 4);
		ret[4] = ret[3];
		ret[3] = ret[2];
		ret[2] = ret[1];
		ret[1] = ret[0];
		ret[0] = ' ';
	}
	else
		ret = get_hour(parsed_date[3]);
	return (ret);
}

static char		**get_parsed_date(t_list *file)
{
	char		*date;
	char		**parsed_date;

	date = NULL;
	parsed_date = NULL;
	if (!(date = ft_strnew(ft_strlen(ctime(&TIME(file))))))
		print_mem_error(errno);
	date = ft_strcpy(date, ctime(&TIME(file)));
	if (!(parsed_date = ft_strsplit(date, ' ')))
		print_mem_error(errno);
	ft_strdel(&date);
	return (parsed_date);
}

static void		free_parsed_date(char **parsed_date)
{
	int			i;

	i = 0;
	while (i < 5)
	{
		ft_strdel(&parsed_date[i]);
		i++;
	}
	ft_memdel((void**)parsed_date);
}

void			print_date(t_list *file)
{
	char		*last;
	char		**parsed_date;

	parsed_date = get_parsed_date(file);
	last = get_hour_or_year(file, parsed_date);
	ft_putstr(parsed_date[1]);
	ft_putchar(' ');
	if (ft_atoi(parsed_date[2]) < 10)
		ft_putchar(' ');
	ft_putstr(parsed_date[2]);
	ft_putchar(' ');
	ft_putstr(last);
	ft_putchar(' ');
	ft_strdel(&last);
	free_parsed_date(parsed_date);
}
