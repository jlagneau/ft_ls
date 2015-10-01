#include <stdlib.h>
#include <dirent.h>
#include <errno.h>
#include <libft.h>
#include "ft_ls.h"

void 		simple_list(char *directory)
{
	DIR *pDir;
	t_dir *pDirent;

	pDir = NULL;
	pDirent = NULL;
	if (!directory)
		pDir = opendir(".");
	else
		pDir = opendir(directory);
	if (pDir)
	{
		while ((pDirent = readdir(pDir)))
		{
			if (pDirent)
			{
				ft_putstr(pDirent->d_name);
				ft_putchar(' ');
			}
			else
				print_error(errno);
		}
	}
	else
		print_error(errno);
}
