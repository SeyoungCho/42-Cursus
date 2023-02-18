/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seycho <seycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:34:31 by seycho            #+#    #+#             */
/*   Updated: 2022/11/22 17:43:40 by seycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(-n, fd);
		}
		else
		{
			if (n / 10 == 0)
			{
				n = n + '0';
				ft_putchar_fd(n, fd);
			}
			else
			{
				ft_putnbr_fd(n / 10, fd);
				ft_putnbr_fd(n % 10, fd);
			}
		}
	}
}
