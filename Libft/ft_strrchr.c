/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seycho <seycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:42:26 by seycho            #+#    #+#             */
/*   Updated: 2022/11/19 18:35:14 by seycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	idx;
	char	*p;

	p = (char *)s;
	idx = ft_strlen(s);
	while (idx > 0)
	{
		if (p[idx] == (char)c)
			return (&p[idx]);
		idx--;
	}
	if (p[idx] == (char)c)
		return (&p[idx]);
	else
		return (0);
}
