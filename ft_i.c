/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:57:45 by darodrig          #+#    #+#             */
/*   Updated: 2019/12/17 11:00:48 by darodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_int(t_pf *pf, va_list arg)
{
	char	*tmp;
	char	*zeros;

	pf->nb = va_arg(arg, int);
	if (pf->nb < 0 && (pf->sign = -1))
	{
		pf->nb = -pf->nb;
		pf->signstr = ft_strdup("-");
	}
	else
		pf->signstr = ft_strdup("");
	pf->str = ft_utoa(pf->nb);
	zeros = ft_zeros(pf->prec - ft_strlen(pf->str));
	tmp = ft_strjoin(zeros, pf->str);
	free(pf->str);
	pf->str = tmp;
	if (pf->left == 1)
		ft_print_int1(pf);
	else
		ft_print_int2(pf);
	free(pf->str);
	free(zeros);
	free(pf->signstr);
}

void	ft_print_int2(t_pf *pf)
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

void	ft_print_int1(t_pf *pf)
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
