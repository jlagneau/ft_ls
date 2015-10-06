/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/04 08:49:52 by jlagneau          #+#    #+#             */
/*   Updated: 2015/10/04 08:49:53 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <libft.h>
# include "macro.h"

void		init(int ac, char **av);
int			get_options(int ac, char **av);
t_list		*get_params(int ac, char **av);
void		get_files(t_list *params, t_list **files);
void		get_directories(t_list *params, t_list **directories);
void		get_directory_content(t_list *dir, t_list **files, int options);
void		print_directories(t_list *dir, int c, int options);
void		print_recursive(t_list *files, t_list *path, int c, int options);
char		*set_file_path(char *name, char *path);
void		set_file(char *name, char *path, t_list **files);
void		sort(t_list *file, int options);
void		print(t_list *file, int options);
void		print_long(t_list *file);
void		print_simple(t_list *file);
void		print_total(t_list *files);
void		print_mode(int octal);
void		print_link(t_list *file, t_padding *padding);
void		print_user_group(t_list *file, t_padding *padding);
void		print_size(t_list *file, t_padding *padding);
void		print_date(t_list *file);
void		print_name(t_list *file);
void		print_link_dest(t_list *file);
void		padding(t_list *files, t_padding *padding);
void		print_mem_error(int err);
void		print_opendir_error(char *directory, int err);
void		print_stat_error(char *filename, int err);
void		print_link_error(char *link, int err);
void		free_file(void *file, t_size size);
int			strcmp_case_i(char *s1, char *s2);
t_size		ft_nbrlen(int n);

#endif
