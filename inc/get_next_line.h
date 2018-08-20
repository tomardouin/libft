/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toardoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 12:12:46 by toardoui          #+#    #+#             */
/*   Updated: 2018/08/13 12:17:47 by toardoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 10
# define T_FILE_BUFF ((t_gnlfile *)(tmp->content))->buff
# define T_FILE_FD ((t_gnlfile *)(tmp->content))->fd

typedef struct		s_gnlfile
{
	int				fd;
	char			*buff;
}					t_gnlfile;

int					get_next_line(const int fd, char **line);

#endif
