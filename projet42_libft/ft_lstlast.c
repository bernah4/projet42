/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 13:44:50 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/16 15:04:41 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstlast(t_list **alst, t_list *new)
{
	t_list	*tmp;

	tmp = NULL;
	if (alst != NULL && new != NULL)
	{
		if (*alst != NULL)
		{
			tmp = *alst;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
		}
		else
			*alst = new;
	}
}
