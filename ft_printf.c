/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:43:55 by darodrig          #+#    #+#             */
/*   Updated: 2019/12/10 19:02:26 by darodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(t_pf *pf, va_list arg)
{
	ft_asterix(pf, arg);
	if (pf->format[ft_strlen(pf->format) - 1] == 's')
		ft_print_string(pf, arg);
	free(pf->format);
	pf_reset(pf);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	t_pf	*pf;

	if (!(pf = malloc(sizeof(t_pf))))
		return (0);
	pf_init(pf);
	va_start(arg, s);
	while (*s)
	{
		if (*s != '%')
			ft_putchar(*s, pf);
		else if (*(s + 1) == '%' && (s++))
			ft_putchar('%', pf);
		else
		{
			pf->format = ft_substr(s, 1, ft_indexof(s, "cpuidsxX"));
			ft_getformat(pf->format, pf);
			ft_format(pf, arg);
			s += ft_indexof(s, "cpuidsxX");
		}
		s++;
	}
	va_end(arg);
	return (pf->printed);
}
