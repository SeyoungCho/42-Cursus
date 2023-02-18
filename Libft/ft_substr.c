/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seycho <seycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:10:20 by seycho            #+#    #+#             */
/*   Updated: 2022/11/22 22:22:00 by seycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_smartalloc(size_t s_len, unsigned int start, size_t	len)
{
	unsigned int	min_len;
	char			*ret;

	min_len = len;
	if (start >= s_len)
	{
		ret = (char *)malloc(1);
		if (!ret)
			return (0);
		*ret = '\0';
		return (ret);
	}
	if ((s_len - start) < len)
		min_len = (s_len - start);
	ret = (char *)malloc(sizeof(char) * (min_len + 1));
	if (!ret)
		return (0);
	return (ret);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (len > s_len)
	{
		if (start < s_len)
			return (ft_strdup(s + start));
		else
			return (ft_calloc(1, 1));
	}
	ret = ft_smartalloc(s_len, start, len);
	if (!ret)
		return (0);
	i = 0;
	while (i < len && start + i < s_len)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
