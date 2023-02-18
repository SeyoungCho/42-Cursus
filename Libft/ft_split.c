/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seycho <seycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:24:02 by seycho            #+#    #+#             */
/*   Updated: 2022/11/23 14:20:59 by seycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *str, size_t len, char c)
{
	int			cnt;
	size_t		i;
	size_t		start;

	start = 0;
	i = 0;
	cnt = 0;
	while (i < len)
	{
		while (i < len && str[i] == c)
			i++;
		start = i;
		while (i < len && str[i] != c)
			i++;
		if (i > start)
			cnt++;
		i++;
	}
	return (cnt);
}

static void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static int	ft_fill_token(char **tokens, char buf[], int str_idx)
{
	tokens[str_idx] = (char *)malloc(ft_strlen(buf) + 1);
	if (!tokens[str_idx])
	{
		while (*tokens)
		{
			free(*tokens);
			tokens++;
		}
		return (0);
	}
	ft_strcpy(tokens[str_idx], buf);
	return (1);
}

static int	ft_fill_strings(char const *str, char **tokens, char c, size_t len)
{
	size_t		i;
	int			str_idx;
	char		buf[16384];
	int			j;

	i = 0;
	str_idx = 0;
	while (i < len)
	{
		while (i < len && str[i] == c)
			i++;
		j = 0;
		while (i < len && str[i] != c)
			buf[j++] = str[i++];
		if (j > 0)
		{
			buf[j] = '\0';
			if (!ft_fill_token(tokens, buf, str_idx))
				return (0);
			str_idx++;
		}
	}
	return (1);
}

char	**ft_split(char const *s1, char c)
{
	int		word_cnt;
	char	**ret;

	word_cnt = ft_count_words(s1, ft_strlen(s1), c);
	ret = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (!ret)
		return ((char **) NULL);
	if (word_cnt == 0)
	{
		ret[0] = 0;
		return (ret);
	}
	ret[word_cnt] = 0;
	if (!ft_fill_strings(s1, ret, c, ft_strlen(s1)))
	{	
		free(ret);
		return ((char **) NULL);
	}
	return (ret);
}
