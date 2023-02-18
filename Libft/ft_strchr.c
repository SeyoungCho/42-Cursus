/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seycho <seycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:35:47 by seycho            #+#    #+#             */
/*   Updated: 2022/11/17 21:50:43 by seycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
