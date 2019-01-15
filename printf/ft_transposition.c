/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transposition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:28:45 by hebernar          #+#    #+#             */
/*   Updated: 2019/01/15 15:29:30 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_transpositon(t_pf *stct, void *elem)
{
	if (stct->spec == 'd' || stct->spec == 'i')
		return (ft_sitoa_base(ft_convert_signed(stct, elem), stct));
	if (stct->spec == 'o' || stct->spec == 'u' || stct->spec == 'x'
			|| stct->spec == 'X' || stct->spec == 'b')
		return (ft_uitoa_base(ft_convert_unsigned(stct, elem), stct));
	if (stct->spec == 'f')
		return (ft_ftoa_base(ft_convert_double(stct, elem), stct));
	if (stct->spec == 'c')
		return (ft_tochar(stct, elem));
	if (stct->spec == 's')
		return (ft_tostring(stct, elem));
	if (stct->spec == 'p')
		return (ft_adress(stct, elem));
}
