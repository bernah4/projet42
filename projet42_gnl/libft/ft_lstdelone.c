/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 12:24:50 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/15 14:24:26 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*adr;

	if (alst != NULL)
	{
		adr = *alst;
		if ((del) != NULL)
			(del)(adr->content, adr->content_size);
		free(adr);
		*alst = NULL;
	}
}
