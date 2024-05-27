/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumartin <aumartin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:51:29 by aumartin          #+#    #+#             */
/*   Updated: 2024/05/27 12:32:45 by aumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*current;
	t_list	*updated_lst;

	if (!lst || !f || !del)
		return (NULL);
	start = ft_lstnew(f(lst->content));
	current = start;
	while (lst->next)
	{
		lst = lst->next;
		updated_lst = ft_lstnew(f(lst->content));
		if (!updated_lst)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		current->next = updated_lst;
		current = updated_lst;
	}
	return (start);
}
