/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toardoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:07:39 by toardoui          #+#    #+#             */
/*   Updated: 2017/11/16 13:40:05 by toardoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int				i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (s != NULL && f != NULL)
	{
		while (s[i])
		{
			f(j, &s[i]);
			i++;
			j++;
		}
	}
	return ;
}
