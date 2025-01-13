/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:38:39 by obastug           #+#    #+#             */
/*   Updated: 2024/10/09 13:38:56 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr_fd(unsigned long long n, int fd)
{
	if (n > 15)
	{
		ft_putptr_fd(n / 16, fd);
		ft_putptr_fd(n % 16, fd);
	}
	else
	{
		ft_putchar_fd("0123456789abcdef"[n], fd);
	}
}
