/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toardoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:23:38 by toardoui          #+#    #+#             */
/*   Updated: 2017/11/16 16:25:09 by toardoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s;
	size_t			i;

	s = (unsigned char*)b;
	i = 0;
	while (i < len)
	{
		s[i] = (char)c;
		i++;
	}
	return (b);
}
