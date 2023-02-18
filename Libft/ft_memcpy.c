/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seycho <seycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:06:49 by seycho            #+#    #+#             */
/*   Updated: 2022/11/17 15:30:19 by seycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
