/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seycho <seycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:47:10 by seycho            #+#    #+#             */
/*   Updated: 2022/11/19 22:24:02 by seycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	f_idx;	
	size_t	b_idx;

	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	f_idx = 0;
	b_idx = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[f_idx]))
		f_idx++;
	while (ft_strchr(set, s1[b_idx]))
		b_idx--;
	if (f_idx <= b_idx)
		return (ft_substr(s1, f_idx, b_idx - f_idx + 1));
	else
		return (ft_strdup(""));
}
/*
int main()
{
	char *ret = ft_strtrim("   abc   ", " ");
	printf("%s\n", ret);
	return 0;
}*/