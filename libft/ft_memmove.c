/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:30:19 by obastug           #+#    #+#             */
/*   Updated: 2024/10/28 11:16:14 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	register size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	if (dest >= src)
	{
		while (i < n)
		{
			((char *)dest)[n - i - 1] = ((const char *)src)[n - i - 1];
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			((char *)dest)[i] = ((const char *)src)[i];
			i++;
		}
	}
	return (dest);
}
