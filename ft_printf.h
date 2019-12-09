/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <darodrig@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 12:16:24 by darodrig          #+#    #+#             */
/*   Updated: 2019/12/09 13:31:08 by darodrig         ###   ########.fr       */
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
	int	printed;
	int	zero;
	int	left;
	int	width;
	int	prec;
	char	*format;
	char	*str;
}		t_pf;

int	ft_strlen(const char *s);
int	ft_printf(const char *s, ...);
char	*ft_strjoin(const char *s1, const char *s2);
void	ft_putchar(char c, t_pf *pf);
void	ft_putstr(const char *str, t_pf *pf);
void	pf_init(t_pf *pf);
void	pf_reset(t_pf *pf);

#endif
