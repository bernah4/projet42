/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:00:28 by hebernar          #+#    #+#             */
/*   Updated: 2018/11/07 16:11:07 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int tot;

	tot = 1;
	if (nb < 0 || nb > 12)
		return (0);
	while (nb > 1)
	{
		tot = tot * nb;
		nb--;
	}
	return (tot);
}
