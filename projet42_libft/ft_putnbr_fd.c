/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:23:17 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/09 14:38:01 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_fd(int n, int fd)
{
	long z;

	z = n;
	if (n < 0)
	{
		z = -z;
		ft_putchar_fd('-', fd);
	}
	if (z > 9)
	{
		ft_putnbr_fd(z / 10, fd);
		ft_putnbr_fd(z % 10, fd);
	}
	else
		ft_putchar_fd(z % 10 + '0', fd);
}
