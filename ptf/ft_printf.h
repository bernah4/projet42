/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 10:38:42 by hebernar          #+#    #+#             */
/*   Updated: 2019/10/05 17:52:19 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"
# define BUFF_SIZE 1000

typedef	struct	s_pf{
	char	type;
	int		size;
	int		indicator;
	int		lenght;
	int		precis;
	int		base;
	int		max;
	int		sign;
	int		size_ret;
	int		size_indic;
	int		pos;
}				t_pf;

void			ft_init_stct(t_pf *stct);
void			ft_printf(char const *str, ...);
void			copy_buf(char *buf, char *str);
void			ft_flush_buf(char *buf);
void			ft_type(t_pf *stct, void *input, char *buf);
void			copy_buf_last(char *buf, char *str, t_pf *stct);
int				ft_valid_token(char *str, int pos, t_pf *stct, char *buf);
int				token_letter(char *str, int pos);
int				token_sign(char *str, int pos);
int				is_number(char *str, int pos);
int				parse_size(char *str, int pos, t_pf *stct);
int				parse_indicator(char *str, int pos, t_pf *stct);
int				parse_precision(char *str, int pos, t_pf *stct);
int				parse_length(char *str, int pos, t_pf *stct);
int				parse_type(char *str, int pos, t_pf *stct);
int				ft_imax(int a, int b);
char			*itoa_schar(char nb, t_pf *stct);
char			*itoa_sshort(short nb, t_pf *stct);
char			*itoa_sint(int nb, t_pf *stct);
char			*itoa_slong(long nb, t_pf *stct);
char			*itoa_slonglong(long long nb, t_pf *stct);
char			*itoa_uchar(unsigned char nb, t_pf *stct);
char			*itoa_ushort(unsigned short nb, t_pf *stct);
char			*itoa_uint(unsigned int nb, t_pf *stct);
char			*itoa_ulong(unsigned long nb, t_pf *stct);
char			*itoa_ulonglong(unsigned long long nb, t_pf *stct);

#endif
