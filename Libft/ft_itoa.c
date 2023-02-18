/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seycho <seycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:06:04 by seycho            #+#    #+#             */
/*   Updated: 2022/11/22 15:57:26 by seycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_digit_num(long num)
{
	int	size;

	size = 0;
	if (num < 0)
	{
		num *= -1;
		size++;
	}
	if (num == 0)
		size++;
	while (num > 0)
	{
		num /= 10;
		size++;
	}
	return (size);
}

static void	ft_fill_str(char *str, int n, int len)
{
	int		i;
	int		start;
	long	nbr;

	i = len - 1;
	start = 0;
	nbr = (long)n;
	if (nbr < 0)
	{
		str[0] = '-';
		start = 1;
		nbr *= -1;
	}
	str[len] = '\0';
	while (i >= start)
	{
		str[i] = nbr % 10 + '0';
		nbr /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ret;

	len = ft_get_digit_num((long)n);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ft_fill_str(ret, n, len);
	return (ret);
}
