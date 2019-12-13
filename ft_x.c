/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:20:40 by darodrig          #+#    #+#             */
/*   Updated: 2019/12/13 18:23:10 by darodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hexa(t_pf *pf, va_list arg)
{
	char	*tmp;

	pf->nb = va_arg(arg, unsigned int);
	pf->signstr = ft_strdup("");
	pf->str = ft_itoa_base(pf->nb, 16);
	if (pf->format[ft_strlen(pf->format) - 1] == 'X')
		pf->str = ft_toupper(pf->str);
	tmp = ft_strjoin(ft_zeros(pf->prec - ft_strlen(pf->str)), pf->str);
	free(pf->str);
	pf->str = tmp;
	if (pf->left == 1)
		ft_print_hex1(pf);
	else
		ft_print_hex2(pf);
	free(pf->str);
	free(pf->signstr);
}

void	ft_print_hex2(t_pf *pf)
{
	if (pf->zero == 1 && pf->prec == -1)
	{
		ft_putstr(pf->signstr, pf);
		ft_printchars(pf->width - ft_strlen(pf->str) - \
				ft_strlen(pf->signstr), '0', pf);
		ft_putstr(pf->str, pf);
	}
	else
	{
		if (pf->prec == 0)
			ft_trunc(&pf->str, pf->prec);
		ft_printchars(pf->width - ft_strlen(pf->str) - \
				ft_strlen(pf->signstr), ' ', pf);
		ft_putstr(pf->signstr, pf);
		ft_putstr(pf->str, pf);
	}
}

void	ft_print_hex1(t_pf *pf)
{
	char	*tmp;
	char	*zeros;

	if (pf->prec == 0)
		ft_trunc(&pf->str, pf->prec);
	zeros = ft_zeros(pf->prec - ft_strlen(pf->str));
	tmp = ft_strjoin(zeros, pf->str);
	free(zeros);
	free(pf->str);
	pf->str = tmp;
	ft_putstr(pf->signstr, pf);
	ft_putstr(pf->str, pf);
	ft_printchars(pf->width - ft_strlen(pf->str) - ft_strlen(pf->signstr)\
		, ' ', pf);
}
