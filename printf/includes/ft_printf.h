/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcarry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 01:25:22 by lcarry            #+#    #+#             */
/*   Updated: 2021/01/27 01:25:26 by lcarry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_struct
{
	int				minus;
	int				zero;
	int				width;
	int				precision;
	int				type;
	int				length;
}					t_struct;
int					ft_printf(const char *format, ...);
int					ft_parse(const char *str, va_list ap);
int					ft_processor(t_struct format, va_list ap);
int					ft_parse_format(const char *str, int i, t_struct *format,
						va_list ap);
t_struct			ft_format_width(va_list ap, t_struct format);
int					ft_format_precision(const char *str, t_struct *format,
						va_list ap);
int					ft_format_valid(const char chr);
int					ft_putchar_r(char c);
t_struct			ft_structinit(void);
int					ft_format_width_dig(const char *str, t_struct *format);
char				*ft_itoa_un(unsigned int nb);
char				*ft_itoa_base(unsigned int nb, int base);
char				*ft_toupper_str(char *str);
int					ft_write_int(int num, t_struct format);
int					ft_write_unint(unsigned int unum, t_struct format);
int					ft_write_char(int chr, t_struct format);
int					ft_write_string(char *str, t_struct format);
int					ft_write_pointer(unsigned long long p, t_struct format);
int					ft_write_hex(unsigned int hex, t_struct format);
int					ft_write_percent(t_struct format);
int					ft_write_while(int i, char c);
int					ft_numlen(int nb);
int					ft_putnbr_r(int n, int fd, int tmp);
int					ft_putstr_r(char *s, int fd);
char				*ft_itoa_unll(unsigned long long nb, int base);

#endif
