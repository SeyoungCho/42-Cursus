/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seycho <seycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:29:40 by seycho            #+#    #+#             */
/*   Updated: 2022/11/19 21:43:33 by seycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	s1_len;
	size_t	s2_len;
	void	*tmp;

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
