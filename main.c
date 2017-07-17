#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include "libft/libft.h"

int		ls_sort_insert(t_list *prev, t_list *new)
{
	if (ft_strcmp(((struct dirent*)prev->content)->d_name, ((struct dirent*)new->content)->d_name))
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	void			*dir;
	struct	dirent	*data;
	t_list			*start;
	t_list			*tmp;

	start = NULL;
	if (ac != 2)
		return (0);
	dir = opendir(av[1]);
	if (!dir)
		return(printf("Fichier ou dossier inexistant\n"));
	while ((data = readdir(dir)))
	{
		ft_lstinsert_if_end(&start, ft_lstnew(data, sizeof(struct dirent)), &ls_sort_insert);
	}
	closedir(dir);
	tmp = start;
	while (tmp)
	{
		printf("%s\n", ((struct dirent*)(tmp->content))->d_name);
		tmp = tmp->next;
	}
	return (0);
}
