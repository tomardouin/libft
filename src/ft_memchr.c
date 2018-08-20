/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toardoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:50:21 by toardoui          #+#    #+#             */
/*   Updated: 2018/02/15 10:05:35 by toardoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	unsigned char	letter;
	size_t			i;

	i = 0;
	letter = (unsigned char)c;
	s2 = (unsigned char*)s;
	while (i < n)
	{
		if (s2[i] == letter)
			return ((void*)&(s2[i]));
		i++;
	}
	return (NULL);
}
