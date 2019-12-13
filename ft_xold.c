/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:14:36 by darodrig          #+#    #+#             */
/*   Updated: 2019/12/13 18:13:59 by darodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hexa(t_pf *pf, va_list arg)
{
	pf->str = ft_itoa_base(va_arg(arg, unsigned int), 16);
	if (pf->prec != -1)
	{
		ft_printchars(pf->prec - ft_strlen(pf->str), '0', pf);
		ft_putstr(pf->str, pf);
		free(pf->str);
		return ;
	}
	else if (pf->left == 1)
	{
		ft_putstr(pf->str, pf);
		if (pf->prec != -1)
			ft_printchars(pf->prec - ft_strlen(pf->str), '0', pf);
		else if (pf->width != -1)
			ft_printchars(pf->width - ft_strlen(pf->str), ' ', pf);
		free(pf->str);
		return ;
	}
	else
		ft_print_hexa2(pf);
}

void	ft_print_hexa2(t_pf *pf)
{
	char c;

	if (pf->zero == 1)
		c = '0';
	else
		c = ' ';
	if (pf->prec != -1)
		ft_printchars(pf->prec - ft_strlen(pf->str), c, pf);
	else if (pf->width != -1)
		ft_printchars(pf->width - ft_strlen(pf->str), c, pf);
	ft_putstr(pf->str, pf);
	free(pf->str);
}
