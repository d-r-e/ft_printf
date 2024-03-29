/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:43:55 by darodrig          #+#    #+#             */
/*   Updated: 2019/12/17 11:38:01 by darodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(t_pf *pf, va_list arg)
{
	char	format;

	format = pf->format[ft_strlen(pf->format) - 1];
	if (format == 's')
		ft_print_string(pf, arg);
	if (format == 'c')
		ft_print_char(pf, arg);
	if (format == 'p')
		ft_print_pointer(pf, arg);
	if (format == '%')
		ft_print_percent(pf);
	if (format == 'x' || format == 'X')
		ft_print_hexa(pf, arg);
	if (format == 'd' || format == 'i')
		ft_print_int(pf, arg);
	if (format == 'u')
		ft_print_unsigned(pf, arg);
	free(pf->format);
	pf_reset(pf);
}

int		ft_printf(const char *s, ...)
{
	va_list	arg;
	t_pf	*pf;

	if (ft_count_perc(s) < 0 || !(pf = malloc(sizeof(t_pf))))
		return (0);
	pf_init(pf);
	va_start(arg, s);
	while (*s != '\0')
	{
		if (*s != '%')
			ft_putchar(*s, pf);
		else
		{
			pf->format = ft_substr(s, 1, ft_indexof(s, "cpuidsxX%"));
			ft_asterix(pf, arg);
			ft_getformat(pf->format, pf);
			ft_format(pf, arg);
			s += ft_indexof(s, "cpuidsxX%");
		}
		s++;
	}
	va_end(arg);
	free(pf);
	return (pf->printed);
}
