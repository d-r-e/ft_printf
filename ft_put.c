/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 20:12:03 by darodrig          #+#    #+#             */
/*   Updated: 2019/12/17 11:50:03 by darodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_pf *pf)
{
	if (c == 0)
		write(1, "\0", 1);
	else
		write(1, &c, 1);
	pf->printed++;
}

void	ft_putstr(const char *str, t_pf *pf)
{
	while (*str)
	{
		ft_putchar(*str, pf);
		str++;
	}
}
