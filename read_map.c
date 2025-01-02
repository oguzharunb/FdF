#include "fcntl.h"
#include <unistd.h>
#include "libft.h"
#include <stdlib.h>
#include "fdf.h"

#include <stdio.h>
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
			return (free(map), write(STDERR_FILENO, "allocation error", 16), NULL);
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

unsigned long	*map_string_to_ulong_array(char *map_one_line)
{
	size_t			i;
	char			*point_array;
	size_t			final_len;
	unsigned long	final_array;
	
	i = 0;
	point_array = ft_split(map_one_line, ' ');
	if (!point_array)
		return (write(STDERR_FILENO, "allocation error", 16), NULL);
	final_len = ft_strlen(point_array);
	final_array = malloc(sizeof(unsigned long) * final_len);
	if (!final_array)
		return (write(STDERR_FILENO, "allocation error", 16), NULL);
	while (point_array[i])
	{
		
	}
}

unsigned long	**map_string_to_arr_2d(char *whole_file)
{
	char	**map_2d;
	int		i;
	map_2d = ft_split(str_map, '\n');
	if (!map_2d)
		return (write(STDERR_FILENO, "allocation error", 16), NULL);
	i = 0;
	while (map_2d[i])
	{
		
	}
}