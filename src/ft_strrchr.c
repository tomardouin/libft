/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toardoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:53:37 by toardoui          #+#    #+#             */
/*   Updated: 2017/11/13 16:46:29 by toardoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*s2;

	i = 0;
	while (s[i])
		i++;
	s2 = (char*)s + i;
	while (*s2 != c)
	{
		if (s2 == s)
			return (NULL);
		s2--;
	}
	return (s2);
}
