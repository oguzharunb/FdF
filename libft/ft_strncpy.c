/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:09:50 by obastug           #+#    #+#             */
/*   Updated: 2024/10/09 14:12:38 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strncpy(char *dst, const char *src, size_t dsize)
{
	register size_t	i;

	i = 0;
	while (i < dsize && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	while (i < dsize)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
