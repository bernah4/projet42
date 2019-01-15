/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:16:34 by hebernar          #+#    #+#             */
/*   Updated: 2019/01/15 15:34:48 by hebernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>

typedef struct			s_pf{
	int		r_pos;
	int		valid;
	int		flag;
	int		width;
	int		precision;
	int		length;
	int		base;
	char	spec;
	char	*s_spec;
}						t_pf;

char					*ft_transposition(t_pf *stct, void *tmp);
char					*ft_fill_stct(char *str, int pos, t_pf *stct, void *e);
void					ft_init(t_pf *stct, int pos);
int						ft_not_spec(char c, char *buf);
int						ft_flag(char *str, t_pf *stct, int pos);
int						ft_width(char *str, t_pf *stct, int pos);
int						ft_precision(char *str, t_pf *stct, int pos);
int						ft_length(char *str, t_pf *stct, int pos);
void					ft_base(char *str, t_pf *stct, int pos);
long long int			ft_convert_signed(t_pf *stct, void *elem);
unsigned long long int	ft_convert_unsigned(t_pf *stct, void *elem);
long double				ft_convert_double(t_pf *stct, void *elem);
char					ft_val_tochar(void *elem);
unsigned char			ft_val_touchar(void *elem);
int						ft_val_toint(void *elem);
unsigned int			ft_val_touint(void *elem);
short int				ft_val_toshortint(void *elem);
unsigned short int		ft_val_toushortint(void *elem);
long int				ft_val_tolongint(void *elem);
unsigned long int		ft_val_toulongint(void *elem);
long long int			ft_val_tolonglongint(void *elem);
unsigned long long int	ft_val_toulonglongint(void *elem);
double					ft_val_todouble(void *elem);
long double				ft_val_tolongdouble(void *elem);
char					*ft_sitoa_base(long long int val, t_pf *stct);
char					*ft_uitoa_base(unsigned long long int val, t_pf *stct);
char					*ft_ftoa_base(long double val, t_pf *stct);
#endif
