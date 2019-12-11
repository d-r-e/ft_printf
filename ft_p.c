/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 11:35:17 by darodrig          #+#    #+#             */
/*   Updated: 2019/12/11 11:59:01 by darodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_pointer(t_pf *pf, va_list arg)
{
	char	*spaces;

	pf->str = ft_strjoin("0x", ft_itoa_base((long)va_arg(arg, void*), 16));
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

void	ft_print_percent(t_pf *pf, va_list arg)
{
	(void)pf;
	(void)arg;
}
