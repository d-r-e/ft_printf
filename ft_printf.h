/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:43:36 by darodrig          #+#    #+#             */
/*   Updated: 2019/12/10 18:27:26 by darodrig         ###   ########.fr       */
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
void			ft_asterix(t_pf *pf, va_list arg);
void			ft_printchars(int n, char c, t_pf *pf);
void			ft_trunc(char **s, size_t len);
void			ft_enlarge(char **s, size_t len, t_pf *pf);
void			ft_print_string(t_pf *pf, va_list arg);

#endif

