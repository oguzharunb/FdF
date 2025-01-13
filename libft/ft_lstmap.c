/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:21:02 by obastug           #+#    #+#             */
/*   Updated: 2024/10/28 11:57:17 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list			*new_list;
	register t_list	*iter_src;
	register t_list	*iter_new;
	void			*content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	iter_src = lst;
	while (iter_src)
	{
		content = f(iter_src->content);
		iter_new = ft_lstnew(content);
		if (!iter_new)
		{
			if (content)
				del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, iter_new);
		iter_src = iter_src->next;
	}
	return (new_list);
}
