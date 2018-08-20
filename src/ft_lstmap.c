/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syheliou <syheliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:29:25 by syheliou          #+#    #+#             */
/*   Updated: 2018/07/23 14:37:55 by toardoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*out;
	t_list	*before;
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	before = NULL;
	while (lst)
	{
		if ((tmp = (t_list *)malloc(sizeof(t_list *))) == NULL)
			return (NULL);
		tmp = f(lst);
		tmp->next = NULL;
		if (before != NULL)
			before->next = tmp;
		else
			out = tmp;
		lst = lst->next;
		before = tmp;
	}
	return (out);
}
