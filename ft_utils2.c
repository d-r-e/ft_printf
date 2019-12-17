/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:58:00 by darodrig          #+#    #+#             */
/*   Updated: 2019/12/17 11:30:32 by darodrig         ###   ########.fr       */
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

int		ft_is_format(char c)
{
	if (c == 'c' || c == 'p' || c == 'u' || c == 'i' || c == 'd' ||
			c == 's' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

int		ft_count_perc(const char *s)
{
	int i;

	i = 0;
	while (*s != '\0')
	{
		if (*s == '%')
		{
			if (ft_strcmp(s, "%") == 0)
				return (-1);	
			if (!*(s + 1))
				return (-2);
			if (ft_indexof(s, "cpuidsxX%") == -1)
				return (-1);
			s += ft_indexof(s, "cpuidxX%") + 1;
		}
		if (*(s + 1))
			s++;
		else
			break ;
	}
	return (i);
}
