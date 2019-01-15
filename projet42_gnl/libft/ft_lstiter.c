/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 12:39:36 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/16 13:49:50 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
		{
			if ((f) != NULL)
				(f)(lst);
			lst = lst->next;
		}
		if ((f) != NULL)
			(f)(lst);
	}
}
