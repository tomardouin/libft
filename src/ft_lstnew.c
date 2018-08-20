/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syheliou <syheliou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:26:29 by syheliou          #+#    #+#             */
/*   Updated: 2018/07/23 14:38:06 by toardoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*first_elem;

	if ((first_elem = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL || content_size == 0)
	{
		first_elem->content_size = 0;
		first_elem->content = NULL;
		first_elem->next = NULL;
		return (first_elem);
	}
	else
	{
		if ((first_elem->content =
				(t_list *)malloc(sizeof(size_t) * content_size)) == NULL)
			return (NULL);
		ft_memcpy(first_elem->content, content, content_size);
		first_elem->next = NULL;
		first_elem->content_size = content_size;
	}
	return (first_elem);
}
