/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seycho <seycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:25:45 by seycho            #+#    #+#             */
/*   Updated: 2023/02/17 21:42:29 by seycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	free_and_null(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

static void	*free_and_return(char **ptr)
{
	if (*ptr)
		free_and_null(ptr);
	return (NULL);
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
			return (free_and_return(&ret));
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

static char	*ft_join_buffer(char *storage, char *buf, size_t size)
{
	char	*tmp;
	char	*prev_storage;

	tmp = (char *)malloc(sizeof(char) * size + 1);
	if (!tmp)
		return (NULL);
	tmp[size] = '\0';
	tmp = ft_memcpy(tmp, buf, size);
	prev_storage = storage;
	storage = ft_strjoin(storage, tmp);
	free_and_null(&prev_storage);
	if (!storage)
		return (NULL);
	free_and_null(&tmp);
	return (storage);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*storage[OPEN_MAX];
	ssize_t		read_bytes;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf && fd < 0)
		return (NULL);
	read_bytes = read(fd, buf, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		storage[fd] = ft_join_buffer(storage[fd], buf, (size_t)read_bytes);
		if (ft_strchr(storage[fd], '\n'))
			return (ft_extract_line(&storage[fd], \
			ft_strchr(storage[fd], '\n'), &buf));
		read_bytes = read(fd, buf, BUFFER_SIZE);
	}
	if (!storage[fd] || read_bytes < 0)
	{
		if (storage[fd])
			free_and_null(&storage[fd]);
		return (free_and_return(&buf));
	}
	return (ft_extract_line(&storage[fd], ft_strchr(storage[fd], '\n'), &buf));
}
