/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:57:22 by obastug           #+#    #+#             */
/*   Updated: 2024/10/24 15:18:50 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	get_digits(int n)
{
	register size_t	i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str_num;
	size_t		digits;
	long int	num;

	num = n;
	digits = 0;
	if (n < 0)
	{
		num *= -1;
		digits++;
	}
	digits += get_digits(n);
	str_num = (char *)malloc(sizeof(char) * (digits + 1));
	if (!str_num)
		return (NULL);
	*(str_num + digits) = 0;
	while (digits--)
	{
		*(str_num + digits) = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		*(str_num + 0) = '-';
	return (str_num);
}
