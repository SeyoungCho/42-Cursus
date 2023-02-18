/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seycho <seycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:53:40 by seycho            #+#    #+#             */
/*   Updated: 2022/11/19 18:14:56 by seycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\f' \
	|| c == '\r' || c == ' ' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				sign;
	unsigned char	*s;
	int				res;

	sign = 1;
	s = (unsigned char *)str;
	res = 0;
	while (ft_isspace(*s))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		res = res * 10 + (*s - '0');
		s++;
	}
	return (sign * res);
}
