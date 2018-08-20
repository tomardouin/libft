/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toardoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:14:05 by toardoui          #+#    #+#             */
/*   Updated: 2017/11/16 14:21:46 by toardoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int				i;
	unsigned int	j;
	char			*str;

	if (s == NULL || f == NULL)
		return (NULL);
	str = (char*)s;
	i = 0;
	j = 0;
	if (!(str = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[i])
	{
		str[i] = f(j, s[i]);
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
