/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 10:38:42 by hebernar          #+#    #+#             */
/*   Updated: 2019/09/29 16:26:10 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# define BUFF_SIZE 1000

typedef	struct	s_pf{
	char	type;
	int		size;
	int		indicator;
	int		lenght;
	int		precis;
	int		base;
	int		max;
	int		size_ret;
	int		size_indic;
	int		last_pos;
}				t_pf;

void			ft_init_stct(t_pf *stct);
int				ft_valid_token(char *str, int pos, t_pf *stct, char *buf);
int				token_letter(char *str, int pos);
int				token_sign(char *str, int pos);
int				is_number(char *str, int pos);
int				parse_size(char *str, int pos, t_pf *stct);
int				parse_indicator(char *str, int pos, t_pf *stct);
int				parse_precision(char *str, int pos, t_pf *stct);
int				parse_length(char *str, int pos, t_pf *stct);
int				parse_type(char *str, int pos, t_pf *stct);

#endif
