/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 12:15:42 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/16 13:26:17 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ret;

	if (!(ret = (t_list *)malloc(sizeof(*ret) * 1)))
		return (NULL);
	if (content == NULL)
	{
		ret->content = NULL;
		ret->content_size = 0;
	}
	else
	{
		if (!(ret->content = ft_memalloc(content_size)))
		{
			ret->content = NULL;
			ret->content_size = 0;
			ret->next = NULL;
			return (ret);
		}
		ret->content = ft_memmove(ret->content, content, content_size);
		ret->content_size = content_size;
	}
	ret->next = NULL;
	return (ret);
}
