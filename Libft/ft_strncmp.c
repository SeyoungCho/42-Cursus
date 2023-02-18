/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seycho <seycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:23:28 by seycho            #+#    #+#             */
/*   Updated: 2022/11/17 20:53:13 by seycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	if (n == 0)
		return (0);
	while (s1[idx] != '\0' && s2[idx] != '\0' && idx < n)
	{
		if (s1[idx] != s2[idx])
			break ;
		idx++;
	}
	if (idx == n)
		return (0);
	else
		return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
}
