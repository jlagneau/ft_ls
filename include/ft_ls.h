
#ifndef FT_LS
# define FT_LS

# define LONG_OPTION_MASK           1
# define RECURSIVE_OPTION_MASK      1 << 1
# define ALL_OPTION_MASK            1 << 2
# define REVERSE_OPTION_MASK        1 << 3
# define TIME_OPTION_MASK           1 << 4

# define NAME(elem)                 elem->((t_file*)f)->name
# define STAT(elem)                 elem->((t_file*)f)->stat

typedef struct dirent t_dir;
typedef struct stat   t_stat;
typedef struct passwd t_pw;
typedef struct group  t_grp;
typedef struct tm     t_time;

typedef struct			s_options
{
	int					mask;
	char				letter;
}						t_options;

typedef struct			s_file
{
	char				*name;
	t_stat				*pStat;
}						t_file;

void		init(int ac, char **av);
int			get_options(int ac, char **av);
char		**get_params(int ac, char **av);
void		simple_list(char *directory);
void		print_error(int err);

#endif
