/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:22:40 by obastug           #+#    #+#             */
/*   Updated: 2024/10/09 13:23:13 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		ft_putstr_fd("addr: ", 1);
		ft_putptr_fd((unsigned long long)lst, 1);
		ft_putstr_fd(", content: ", 1);
		ft_putchar_fd(*(char *)lst->content, 1);
		ft_putchar_fd('\n', 1);
		lst = lst->next;
	}
}
