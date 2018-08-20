/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toardoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:33:42 by toardoui          #+#    #+#             */
/*   Updated: 2017/11/16 16:47:13 by toardoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned char	letter;
	size_t			i;

	s1 = (unsigned char*)dst;
	s2 = (unsigned char*)src;
	letter = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		if (s2[i] == letter)
			return (s1 + i + 1);
		i++;
	}
	return (NULL);
}
