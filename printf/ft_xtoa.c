/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:30:00 by hebernar          #+#    #+#             */
/*   Updated: 2019/01/15 15:34:50 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_sitoa_base(long long int val, t_pf *stct);
char	*ft_uitoa_base(unsigned long long int val, t_pf *stct);
char	*ft_ftoa_base(long double val, t_pf *stct);

