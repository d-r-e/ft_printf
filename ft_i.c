/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:57:45 by darodrig          #+#    #+#             */
/*   Updated: 2019/12/13 15:31:41 by darodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_int(t_pf *pf, va_list arg)
{
	char	*tmp;

	pf->nb = va_arg(arg, int);
	if (pf->nb < 0 && (pf->sign = -1))
	{
		pf->nb = -pf->nb;
		pf->signstr = ft_strdup("-");
	}
	else
		pf->signstr = ft_strdup("");
	pf->str = ft_itoa(pf->nb);
	tmp = ft_strjoin(ft_zeros(pf->prec - ft_strlen(pf->str)), pf->str);
	free(pf->str);
	pf->str = tmp;
	if (pf->left == 1)
		ft_print_int1(pf);
	else
		ft_print_int2(pf);
	free(pf->str);
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

	if (pf->prec == 0)
		ft_trunc(&pf->str, pf->prec);
	tmp = ft_strjoin(ft_zeros(pf->prec - ft_strlen(pf->str)), pf->str);
	free(pf->str);
	pf->str = tmp;
	ft_putstr(pf->signstr, pf);
	ft_putstr(pf->str, pf);
	ft_printchars(pf->width - ft_strlen(pf->str) - ft_strlen(pf->signstr)\
		, ' ', pf);
}
