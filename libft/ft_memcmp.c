/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:29:17 by obastug           #+#    #+#             */
/*   Updated: 2024/10/09 13:32:14 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *str1, const void *str2, size_t count)
{
	register const unsigned char	*s1;
	register const unsigned char	*s2;

	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	while (count > 0)
	{
		if (*s1++ != *s2++)
			return (s1[-1] - s2[-1]);
		count--;
	}
	return (0);
}
