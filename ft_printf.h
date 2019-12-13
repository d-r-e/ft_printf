/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:43:36 by darodrig          #+#    #+#             */
/*   Updated: 2019/12/13 18:22:19 by darodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct	s_pf
{
	int		printed;
	int		zero;
	int		left;
	int		width;
	int		prec;
	char	*format;
	char	*str;
	int		sign;
	long	nb;
	char	*signstr;
}				t_pf;

size_t			ft_strlen(const char *s);
int				ft_printf(const char *s, ...);
char			*ft_strjoin(const char *s1, const char *s2);
void			ft_putchar(char c, t_pf *pf);
void			ft_putstr(const char *str, t_pf *pf);
void			pf_init(t_pf *pf);
void			pf_reset(t_pf *pf);
char			*ft_substr(const char *s, unsigned int start, size_t len);
int				ft_indexof(const char *s, const char *set);
int				ft_isdigit(int c);
void			ft_getformat(const char *f, t_pf *pf);
char			*ft_itoa_base(long long nbr, int base);
char			*ft_strdup(const char *s1);
char			*ft_itoa(int nbr);
char			*ft_utoa(unsigned int nbr);
void			ft_append(char **str, char c);
char			*ft_toupper(char *str);
void			ft_printchars(int n, char c, t_pf *pf);
void			ft_trunc(char **s, size_t len);
void			ft_enlarge(char **s, size_t len, t_pf *pf);
void			ft_print_string(t_pf *pf, va_list arg);
char			*ft_chardup(char c);
void			ft_print_char(t_pf *pf, va_list arg);
char			*ft_spaces(int n);
char			*ft_zeros(int n);
void			ft_print_pointer(t_pf *pf, va_list arg);
void			ft_print_percent(t_pf *pf);
void			ft_print_int(t_pf *pf, va_list arg);
void			ft_print_hexa(t_pf *pf, va_list arg);
void			ft_print_hex2(t_pf *pf);
void			ft_print_hex1(t_pf *pf);
int				ft_strcmp(const char *s1, const char *s2);
void			ft_print_int(t_pf *pf, va_list arg);
void			ft_print_int1(t_pf *pf);
void			ft_print_int2(t_pf *pf);
void			ft_print_unsigned(t_pf *pf, va_list arg);
void			ft_print_uns1(t_pf *pf);
void			ft_print_uns2(t_pf *pf);
#endif
