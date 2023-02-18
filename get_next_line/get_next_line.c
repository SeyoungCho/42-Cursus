/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seycho <seycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:48:21 by seycho            #+#    #+#             */
/*   Updated: 2023/02/18 17:41:16 by seycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*free_and_null(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
}

static ssize_t	ft_read_from_file(char **buf, int fd)
{
	ssize_t	read_bytes;

	read_bytes = read(fd, *buf, BUFFER_SIZE);
	if (read_bytes >= 0)
		(*buf)[read_bytes] = '\0';
	return (read_bytes);
}

static char	*ft_extract_line(char **storage, char *endl, char **buf)
{
	char	*ret;
	char	*tmp;
	size_t	line_size;

	free_and_null(buf);
	if (endl == 0)
	{
		ret = ft_strdup(*storage);
		if (!ret)
			return (NULL);
		free_and_null(storage);
		if (ft_strlen(ret) == 0)
			return (free_and_null(&ret));
		return (ret);
	}
	line_size = endl - *storage + 1;
	ret = (char *)malloc(sizeof(char) * (line_size) + 1);
	if (!ret)
		return (NULL);
	ret[line_size] = '\0';
	ret = ft_memcpy(ret, *storage, line_size);
	tmp = *storage;
	(*storage) = ft_strdup(endl + 1);
	free_and_null(&tmp);
	return (ret);
}

static char	*ft_join_buffer(char *storage, char *buf)
{
	char	*prev_storage;

	prev_storage = storage;
	storage = ft_strjoin(storage, buf);
	free_and_null(&prev_storage);
	if (!storage)
		return (NULL);
	return (storage);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*storage;
	ssize_t		read_bytes;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_bytes = ft_read_from_file(&buf, fd);
	while (read_bytes > 0)
	{
		storage = ft_join_buffer(storage, buf);
		if (ft_strchr(buf, '\n'))
			return (ft_extract_line(&storage, ft_strchr(storage, '\n'), &buf));
		read_bytes = ft_read_from_file(&buf, fd);
	}
	if (!storage || read_bytes < 0)
	{
		if (storage)
			free_and_null(&storage);
		return (free_and_null(&buf));
	}
	return (ft_extract_line(&storage, ft_strchr(storage, '\n'), &buf));
}
