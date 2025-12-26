/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaalali <raaalali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 22:03:02 by raaalali          #+#    #+#             */
/*   Updated: 2025/12/26 22:03:05 by raaalali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	line_len(char *str, size_t i)
{
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

static char	*shift_buffer(char *str)
{
	char	*new_str;
	size_t	i;

	if (!str)
		return (NULL);
	i = line_len(str, 0);
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	new_str = ft_strdup(str + i);
	free(str);
	return (new_str);
}

static char	*retreive_line(char *str)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (NULL);
	i = line_len(str, i);
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*fill_buffer(int fd, char *read_buffer)
{
	char	*heap_content;
	int		scaned_bytes;

	heap_content = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!heap_content)
		return (NULL);
	scaned_bytes = 1;
	while (!(ft_strchr(read_buffer, '\n')) && scaned_bytes != 0)
	{
		scaned_bytes = read(fd, heap_content, BUFFER_SIZE);
		if (scaned_bytes == -1)
		{
			read_buffer = free_all(heap_content, read_buffer);
			return (NULL);
		}
		heap_content[scaned_bytes] = '\0';
		read_buffer = ft_strjoin(read_buffer, heap_content);
		if (!read_buffer)
		{
			free(heap_content);
			return (NULL);
		}
	}
	free(heap_content);
	return (read_buffer);
}

char	*get_next_line(int fd)
{
	static char	*read_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	read_buffer = fill_buffer(fd, read_buffer);
	if (!read_buffer)
		return (NULL);
	line = retreive_line(read_buffer);
	read_buffer = shift_buffer(read_buffer);
	return (line);
}
