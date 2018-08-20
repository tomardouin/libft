/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syheliou <syheliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:34:43 by syheliou          #+#    #+#             */
/*   Updated: 2018/07/23 14:37:38 by toardoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;
	t_list	*next;

	tmp = *alst;
	while (tmp)
	{
		next = tmp;
		del(tmp->content, tmp->content_size);
		tmp->content_size = 0;
		free(tmp);
		tmp = next->next;
	}
	*alst = NULL;
	alst = NULL;
}
