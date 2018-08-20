/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toardoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:41:51 by toardoui          #+#    #+#             */
/*   Updated: 2018/08/06 13:48:45 by toardoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		isneg(int *n, int *neg)
{
	if (*n < 0)
	{
		*n = *n * -1;
		*neg = 1;
	}
}

char			*ft_itoa(int n)
{
	int			neg;
	int			i;
	int			ntemp;
	char		*dest;

	neg = 0;
	i = 2;
	ntemp = n;
	isneg(&n, &neg);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	while (ntemp /= 10)
		i++;
	i = i + neg;
	if (!(dest = (char*)malloc(sizeof(char) * i)))
		return (NULL);
	dest[--i] = '\0';
	while (i--)
	{
		dest[i] = n % 10 + '0';
		n = n / 10;
	}
	if (neg == 1)
		dest[0] = '-';
	return (dest);
}
