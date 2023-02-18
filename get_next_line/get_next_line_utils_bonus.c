/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seycho <seycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:26:53 by seycho            #+#    #+#             */
/*   Updated: 2023/02/18 17:01:19 by seycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] != '\0')
		len++;
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (!dst && !src)
	{
		return (0);
	}
	while (n > 0)
	{
		((unsigned char *)dst)[n - 1] = ((unsigned char *)src)[n - 1];
		n--;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	s1_len;
	size_t	s2_len;
	void	*tmp;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (s1_len + s2_len) + 1);
	if (!ret)
		return (0);
	tmp = ft_memcpy((void *)ret, (const void *)s1, s1_len);
	tmp = ft_memcpy((void *)ret + s1_len, (const void *)s2, s2_len);
	ret[s1_len + s2_len] = '\0';
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ret;

	ret = (char *)s;
	while (*ret)
	{
		if (*ret == (char)c)
			return (ret);
		ret++;
	}
	if ((char)c == '\0')
		return (ret);
	else
		return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*ret;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s1);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	while (i < len)
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
