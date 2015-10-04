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

#ifndef FT_LS
# define FT_LS
# include <libft.h>
# include <stdint.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>

# define LONG_OPTION_MASK		1
# define RECURSIVE_OPTION_MASK	1 << 1
# define ALL_OPTION_MASK		1 << 2
# define REVERSE_OPTION_MASK	1 << 3
# define TIME_OPTION_MASK		1 << 4

# define NAME(elem)				((t_file*)elem->content)->name
# define PATH(elem)				((t_file*)elem->content)->path
# define MODE(elem)				((t_file*)elem->content)->stat->st_mode
# define LINK(elem)				((t_file*)elem->content)->stat->st_nlink
# define UID(elem)				((t_file*)elem->content)->stat->st_uid
# define GID(elem)				((t_file*)elem->content)->stat->st_gid
# define RDEV(elem)				((t_file*)elem->content)->stat->st_rdev
# define SIZE(elem)				((t_file*)elem->content)->stat->st_size
# define TIME(elem)				((t_file*)elem->content)->stat->st_mtime
# define BLKSIZE(elem)			((t_file*)elem->content)->stat->st_blksize
# define NTIME(elem)			((t_file*)elem->content)->stat->st_mtim.tv_nsec
# if UINTPTR_MAX == 0xffffffff
#  define UTIME(elem)			TIME(elem)
# elif UINTPTR_MAX == 0xffffffffffffffff
#  define UTIME(elem)			TIME(elem) * 1000 + NTIME(elem) / 1000000
# endif
# define MINOR(elem)			((elem) & 0xFF)
# define MAJOR(elem)			((elem) >> 8)
# define FILE_TYPE(elem)		(MODE(elem) & S_IFMT)
# define IS_BLK(elem)			FILE_TYPE(elem) == S_IFBLK
# define IS_CHR(elem)			FILE_TYPE(elem) == S_IFCHR
# define IS_DIR(elem)			FILE_TYPE(elem) == S_IFDIR
# define IS_FIFO(elem)			FILE_TYPE(elem) == S_IFIFO
# define IS_LNK(elem)			FILE_TYPE(elem) == S_IFLNK
# define IS_REG(elem)			FILE_TYPE(elem) == S_IFREG
# define IS_SOCK(elem)			FILE_TYPE(elem) == S_IFSOCK

typedef struct dirent			t_dir;
typedef struct stat				t_stat;
typedef struct passwd			t_pw;
typedef struct group			t_grp;
typedef struct tm				t_time;

typedef struct					s_options
{
	int							mask;
	char						letter;
}								t_options;

typedef struct					s_file
{
	char						*name;
	char						*path;
	t_stat						*stat;
}								t_file;

typedef struct					s_pair
{
	int							type;
	char						letter;
}								t_pair;

typedef struct					s_padding
{
	t_size						link;
	t_size						user;
	t_size						group;
	t_size						size;
	t_size						minor;
	t_size						major;
}								t_padding;

void		init(int ac, char **av);
int			get_options(int ac, char **av);
t_list		*get_params(int ac, char **av);
void		get_files(t_list *params, t_list **files);
void		get_directories(t_list *params, t_list **directories);
void		get_directory_content(t_list *dir, t_list **files, int options);
char		*set_file_path(char *name, char *path);
void		set_file(char *name, char *path, t_list **files);
void		sort(t_list *file, int options);
void		print(t_list *file, int options);
void		print_long(t_list *file);
void		print_simple(t_list *file);
void		print_mode(int octal);
void 		print_link(t_list *file, t_padding *padding);
void		print_user_group(t_list *file, t_padding *padding);
void 		print_size(t_list *file, t_padding *padding);
void		print_date(t_list *file);
void		print_name(t_list *file);
void		print_link_dest(t_list *file);
void		print_error(int err);
void		padding(t_list *files, t_padding *padding);
void		print_stat_error(char *filename, int err);
void		free_file(void *file, t_size size);
int			strcmp_case_i(char *s1, char *s2);
t_size		ft_nbrlen(int n);

#endif
