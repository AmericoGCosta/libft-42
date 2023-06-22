/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amgoncal <amgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:26:09 by amgoncal          #+#    #+#             */
/*   Updated: 2023/06/22 17:26:11 by amgoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*h_node;
	t_list	*c_node;
	t_list	*temp;

	if (!lst || !f || !del)
		return (NULL);
	h_node = ft_lstnew(f(lst->content));
	if (h_node == NULL)
		return (NULL);
	temp = lst->next;
	while (temp != NULL)
	{
		c_node = ft_lstnew(f(temp->content));
		if (c_node == NULL)
		{
			ft_lstclear(&h_node, del);
			return (NULL);
		}
		ft_lstadd_back(&h_node, c_node);
		temp = temp->next;
	}
	return (h_node);
}
