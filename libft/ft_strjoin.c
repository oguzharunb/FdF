/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:02:55 by obastug           #+#    #+#             */
/*   Updated: 2025/01/13 12:53:20 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*s;

	if (!s1 || !s2)
	{
		if (!s1)
			return (s2);
		return (s1);
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1, s1_len + 1);
	ft_strlcpy((s + s1_len), s2, s2_len + 1);
	free(s1);
	free(s2);
	return (s);
}
