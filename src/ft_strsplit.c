/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toardoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:49:55 by toardoui          #+#    #+#             */
/*   Updated: 2017/11/21 13:24:24 by toardoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		countwords(const char *s, char c)
{
	int			words;
	int			i;

	i = 0;
	words = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			words++;
		i++;
	}
	if (s[0] != '\0')
		words++;
	return (words);
}

static char		*letter(const char *s, char c, int *i)
{
	char		*temp;
	int			j;

	if (!(temp = (char*)malloc(sizeof(char) * (ft_strlen(s)))))
		return (NULL);
	j = 0;
	while (s[*i] != c && s[*i])
	{
		temp[j] = s[*i];
		j++;
		*i = *i + 1;
	}
	temp[j] = '\0';
	while (s[*i] == c && s[*i])
		*i = *i + 1;
	return (temp);
}

char			**ft_strsplit(const char *s, char c)
{
	int			i;
	int			j;
	int			words;
	char		**dest;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	words = countwords(s, c);
	if (!(dest = (char **)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	while (s[i] == c && s[i])
		i++;
	while (j < words && s[i])
	{
		dest[j] = letter(s, c, &i);
		j++;
	}
	dest[j] = NULL;
	return (dest);
}
