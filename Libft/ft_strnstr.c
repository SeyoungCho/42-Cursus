/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seycho <seycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:21:08 by seycho            #+#    #+#             */
/*   Updated: 2022/11/19 18:34:43 by seycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n_len;
	char	*h;

	i = 0;
	n_len = ft_strlen(needle);
	h = (char *)haystack;
	if (n_len == 0)
		return (h);
	if (h && len < n_len)
		return (0);
	while (i <= len - n_len)
	{
		if (h[i] == '\0')
			break ;
		if (ft_strncmp(&h[i], needle, n_len) == 0)
			return (&h[i]);
		i++;
	}
	return (0);
}
