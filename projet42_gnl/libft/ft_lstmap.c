/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 12:46:20 by hebernar          #+#    #+#             */
/*   Updated: 2018/12/13 15:40:48 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*elem;

	new = NULL;
	if (lst != NULL)
	{
		while (lst->next != NULL)
		{
			if ((f) != NULL)
			{
				elem = ft_lstnew(lst->content, lst->content_size);
				ft_lstlast(&new, (f)(elem));
			}
			lst = lst->next;
		}
		if ((f) != NULL)
		{
			elem = ft_lstnew(lst->content, lst->content_size);
			ft_lstlast(&new, (f)(elem));
		}
	}
	return (new);
}
