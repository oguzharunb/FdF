/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:56:20 by obastug           #+#    #+#             */
/*   Updated: 2025/01/13 14:37:00 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcntl.h"
#include <unistd.h>
#include "libft.h"
#include <stdlib.h>
#include "fdf.h"
#include <limits.h>

char	*read_file(char *file_name)
{
	int		fd;
	char	*map;
	char	*buffer;
	int		ret;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (write(STDERR_FILENO, "file couldnt open", 17), NULL);
	ret = 1;
	map = NULL;
	while (ret)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (free(map), write(STDERR_FILENO, "allocation error",
					16), NULL);
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
			return (free(map), write(STDERR_FILENO, "read error", 10), NULL);
		buffer[ret] = '\0';
		map = ft_strjoin(map, buffer);
		if (!map)
			return (write(STDERR_FILENO, "allocation error", 16), NULL);
	}
	return (map);
}

// input format "<z:decimalint>,0x<color:hexint>"
// returns ULONG_MAX on error 
unsigned long	point_to_ulong(char *point)
{
	char			**point_attrs;
	int				z;
	unsigned int	color;
	unsigned long	ret;

	point_attrs = ft_split(point, ',');
	if (!point_attrs)
		return (ULONG_MAX);
	z = ft_atoi(point_attrs[0]);
	if (!*(point_attrs + 1))
		color = DEFAULT_COLOR;
	else
		color = ft_atoi_hex(point_attrs[1] + 2);
	ret = (((unsigned long)z) << 32) | (color);
	free_string_list(point_attrs);
	return (ret);
}

// returns NULL on error
unsigned long	*map_string_to_ulong_array(char *map_one_line)
{
	size_t			i;
	char			**point_array;
	size_t			final_len;
	unsigned long	*final_array;

	point_array = ft_split(map_one_line, ' ');
	if (!point_array)
		return (NULL);
	final_len = ft_ptrarrlen((unsigned long *)point_array);
	final_array = malloc(sizeof(unsigned long) * (final_len + 1));
	if (!final_array)
		return (free_string_list(point_array), NULL);
	i = 0;
	while (point_array[i])
	{
		final_array[i] = point_to_ulong(point_array[i]);
		i++;
	}
	final_array[final_len] = ULONG_MAX;
	return (free_string_list(point_array), final_array);
}

unsigned long	**map_string_to_arr_2d(char *whole_file)
{
	char			**map_2d_str;
	unsigned long	**map_2d_ul;
	int				i;
	size_t			line_count;

	map_2d_str = ft_split(whole_file, '\n');
	if (!map_2d_str)
		return (NULL);
	line_count = ft_ptrarrlen((unsigned long *)map_2d_str);
	map_2d_ul = malloc(sizeof(unsigned long *) * (line_count + 1));
	if (!map_2d_ul)
		return (free_string_list(map_2d_str), NULL);
	i = 0;
	while (map_2d_str[i])
	{
		map_2d_ul[i] = map_string_to_ulong_array(map_2d_str[i]);
		i++;
	}
	map_2d_ul[line_count] = '\0';
	return (free_string_list(map_2d_str), map_2d_ul);
}
