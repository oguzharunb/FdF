/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:28:22 by obastug           #+#    #+#             */
/*   Updated: 2024/10/09 13:29:04 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	register size_t	i;
	unsigned char	*tmp_s;
	unsigned char	tmp_c;

	tmp_s = (unsigned char *)s;
	tmp_c = (unsigned char)c;
	i = -1;
	while (++i < n)
	{
		if (tmp_s[i] == tmp_c)
			return (tmp_s + i);
	}
	return (NULL);
}
