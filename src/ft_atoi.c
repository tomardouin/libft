/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toardoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:13:06 by toardoui          #+#    #+#             */
/*   Updated: 2018/08/06 13:32:12 by toardoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	i;
	int	negative;
	int	nb;

	i = 0;
	negative = 0;
	nb = 0;
	while (str[i] == '\r' || str[i] == '\t' || str[i] == '\v' ||
			str[i] == '\n' || str[i] == '\f' || str[i] == '\0' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10;
		nb = nb + (str[i] - '0');
		i++;
	}
	if (negative == 1)
		nb = -nb;
	return (nb);
}
