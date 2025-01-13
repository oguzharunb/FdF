/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:20:01 by obastug           #+#    #+#             */
/*   Updated: 2024/10/31 15:38:27 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *little, size_t len)
{
	register size_t	i;
	register size_t	j;
	size_t			little_len;
	char			*big;

	big = (char *)haystack;
	i = 0;
	little_len = ft_strlen(little);
	if (little_len == 0)
		return (big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j]
			&& little[j] && i + j < len)
			j++;
		if (j == little_len)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
