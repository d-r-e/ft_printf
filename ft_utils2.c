/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:58:00 by darodrig          #+#    #+#             */
/*   Updated: 2019/12/12 15:04:15 by darodrig         ###   ########.fr       */
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

void	ft_toupper(char **str)
{
	int i;

	i = 0;
	while (*str[i])
	{
		if (*str[i] >= 'a' && *str[i] <= 'z')
			*str[i] = *str[i] + ('A' - 'a');
		i++;
	}
	ft_printf("%s", *str);
}
