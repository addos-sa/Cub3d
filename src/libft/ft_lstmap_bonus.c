/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:39:44 by addos-sa          #+#    #+#             */
/*   Updated: 2025/05/02 14:39:53 by addos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;
	void	*modified;

	if (!lst)
		return (NULL);
	new_lst = NULL;
	while (lst != NULL)
	{
		modified = f(lst->content);
		node = ft_lstnew(modified);
		if (!node)
		{
			del(modified);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, node);
		lst = lst ->next;
	}
	return (new_lst);
}
