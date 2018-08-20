/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toardoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:17:11 by toardoui          #+#    #+#             */
/*   Updated: 2017/11/16 19:49:27 by toardoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	totallen(char *s)
{
	size_t		space;
	size_t		i;
	size_t		j;

	i = 0;
	j = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	space = i;
	if (s[i] != '\0')
	{
		i = j - 1;
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		{
			i--;
			space++;
		}
	}
	return (j - space);
}

char			*ft_strtrim(char const *s)
{
	char		*dest;
	size_t		i;
	size_t		j;
	size_t		len;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	len = totallen((char*)s);
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (j < len)
	{
		dest[j] = s[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
