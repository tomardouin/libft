/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toardoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 14:25:32 by toardoui          #+#    #+#             */
/*   Updated: 2018/08/13 12:17:13 by toardoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

t_gnlfile			*ft_newfile(int fd)
{
	t_gnlfile		*file;

	if (!(file = ft_memalloc(sizeof(t_gnlfile *))))
		return (NULL);
	file->fd = fd;
	if (!(file->buff = ft_strnew(0)))
	{
		ft_memdel((void **)&file);
		return (NULL);
	}
	return (file);
}

t_list				*ft_lstsearch(t_list **lst, int fd)
{
	t_list			*tmp;

	tmp = *lst;
	while (tmp != NULL)
	{
		if (T_FILE_FD == fd)
		{
			if (!(T_FILE_BUFF))
				T_FILE_BUFF = ft_strnew(0);
			return (tmp);
		}
		tmp = tmp->next;
	}
	if (!(tmp = ft_lstnew(NULL, sizeof(t_gnlfile *))))
		return (NULL);
	tmp->content = ft_newfile(fd);
	ft_lstadd(lst, tmp);
	return (tmp);
}

int					final_return(char **s, int n_lus)
{
	int				i;
	char			*temp;

	if (n_lus == 0 && **s == 0)
	{
		ft_strdel(s);
		return (0);
	}
	if (ft_strpos(*s, '\n') == (int)ft_strlen(*s))
		i = 0;
	else
		i = 1;
	temp = *s;
	*s = ft_strsub(temp, ft_strpos(temp, '\n') + i, (int)ft_strlen(temp));
	ft_strdel(&temp);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_list	*lst = NULL;
	t_list			*tmp;
	char			*buff;
	int				n_lus;
	char			*temp;

	if (BUFF_SIZE <= 0 || fd < 0 || (n_lus = read(fd, "", 0)) == -1)
		return (-1);
	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (!(tmp = ft_lstsearch(&lst, fd)))
		return (-1);
	while (!ft_strchr(T_FILE_BUFF, '\n') &&
		(n_lus = read(fd, buff, BUFF_SIZE) > 0))
	{
		temp = T_FILE_BUFF;
		T_FILE_BUFF = ft_strjoin(T_FILE_BUFF, buff);
		ft_strdel(&temp);
		ft_strclr(buff);
	}
	ft_strdel(&buff);
	*line = ft_strsub(T_FILE_BUFF, 0, ft_strpos(T_FILE_BUFF, '\n'));
	return (final_return(&T_FILE_BUFF, n_lus));
}
