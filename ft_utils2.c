/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:58:00 by darodrig          #+#    #+#             */
/*   Updated: 2019/12/13 18:25:10 by darodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printchars(int n, char c, t_pf *pf)
{
	while (n > 0)
	{
		ft_putchar(c, pf);
		n--;
	}
}
