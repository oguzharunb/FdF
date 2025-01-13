/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@42kocaeli.com.tr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:46:47 by obastug           #+#    #+#             */
/*   Updated: 2024/10/31 15:38:08 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	register int	i;
	register long	ret;
	char			sign;

	ret = 0;
	i = 0;
	sign = 1;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == '\n' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		ret = (ret * 10) + (nptr[i] - '0');
		i++;
	}
	return ((int)ret * sign);
}
