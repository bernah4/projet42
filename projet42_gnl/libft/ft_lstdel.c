/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 12:30:41 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/16 13:43:53 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*adr;
	t_list	*tmp;

	tmp = NULL;
	if (alst != NULL)
	{
		adr = *alst;
		while (adr->next != NULL)
		{
			tmp = adr->next;
			ft_lstdelone(&adr, (del));
			adr = tmp;
		}
		ft_lstdelone(&adr, (del));
		*alst = NULL;
	}
}
