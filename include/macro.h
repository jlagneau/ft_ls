/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlagneau <jlagneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/06 14:44:28 by jlagneau          #+#    #+#             */
/*   Updated: 2015/10/06 14:44:31 by jlagneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H
# include <libft.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>

# define LONG_OPTION_MASK		1
# define RECURSIVE_OPTION_MASK	1 << 1
# define ALL_OPTION_MASK		1 << 2
# define REVERSE_OPTION_MASK	1 << 3
# define TIME_OPTION_MASK		1 << 4

# define CONTENT(elem)			((t_file*)elem->content)
# define NAME(elem)				CONTENT(elem)->name
# define PATH(elem)				CONTENT(elem)->path
# define LINK_DEST(elem)		CONTENT(elem)->link_dest
# define STAT(elem)				CONTENT(elem)->stat
# define MODE(elem)				STAT(elem)->st_mode
# define LINK(elem)				STAT(elem)->st_nlink
# define UID(elem)				STAT(elem)->st_uid
# define GID(elem)				STAT(elem)->st_gid
# define RDEV(elem)				STAT(elem)->st_rdev
# define SIZE(elem)				STAT(elem)->st_size
# define TIME(elem)				STAT(elem)->st_mtime
# define BLOCK(elem)			STAT(elem)->st_blocks
# define NTIME(elem)			STAT(elem)->st_mtimespec.tv_nsec
# define UTIME(elem)			TIME(elem) * 1000 + NTIME(elem) / 1000000
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
	char						*link_dest;
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

#endif
