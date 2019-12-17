/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 19:14:28 by darodrig          #+#    #+#             */
/*   Updated: 2019/12/17 16:15:26 by darodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_chardup(char c)
{
	char	*str;

	if (!c || !(str = malloc(sizeof(char) * 2)))
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

void	ft_print_char(t_pf *pf, va_list arg)
{
	char	c;
	char	*spaces;

	c = va_arg(arg, int);
	spaces = ft_spaces(pf->width - 1);
	if (pf->left == 1)
	{
		pf->printed++;
		write(1, &c, 1);
		ft_putstr(spaces, pf);
	}
	else
	{
		ft_putstr(spaces, pf);
		write(1, &c, 1);
		pf->printed++;
	}
	free(spaces);
	pf_reset(pf);
}
