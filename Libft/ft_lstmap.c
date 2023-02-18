/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seycho <seycho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 21:12:07 by seycho            #+#    #+#             */
/*   Updated: 2022/11/23 14:19:07 by seycho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void*(*f)(void *), void (*del)(void *))
{
	t_list	*cur;
	t_list	*new_lst;
	t_list	*new_node;
	void	*new_content;

	cur = lst;
	new_lst = 0;
	new_content = (void *)0;
	while (cur)
	{
		new_content = (*f)(cur->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			(*del)(new_content);
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, new_node);
		cur = cur->next;
	}
	return (new_lst);
}
