/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:35:17 by darodrig          #+#    #+#             */
/*   Updated: 2019/12/13 18:33:04 by darodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_pointer(t_pf *pf, va_list arg)
{
	char	*spaces;

	pf->str = ft_strjoin("0x", ft_itoa_base((long)va_arg(arg, void*), 16));
	if (pf->prec == 0)
		ft_trunc(&pf->str, 2);
	spaces = ft_spaces(pf->width - ft_strlen(pf->str));
	if (pf->left == 1)
	{
		ft_putstr(pf->str, pf);
		ft_putstr(spaces, pf);
	}
	else
	{
		ft_putstr(spaces, pf);
		ft_putstr(pf->str, pf);
	}
	free(spaces);
	free(pf->str);
	pf_reset(pf);
}

void	ft_print_percent(t_pf *pf)
{
	char	*spaces;

	pf->str = ft_strdup("%");
	spaces = ft_spaces(pf->width - ft_strlen(pf->str));
	if (pf->zero == 1 && pf->left == 0)
	{
		ft_printchars(pf->width - 1, '0', pf);
		ft_putchar('%', pf);
	}
	else if (pf->left == 1)
	{
		ft_putstr(pf->str, pf);
		ft_putstr(spaces, pf);
	}
	else
	{
		ft_putstr(spaces, pf);
		ft_putstr(pf->str, pf);
	}
	free(spaces);
	free(pf->str);
}
