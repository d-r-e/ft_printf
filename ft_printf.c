/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <darodrig@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 12:18:04 by darodrig          #+#    #+#             */
/*   Updated: 2019/12/09 17:57:33 by darodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		else if (*(s + 1) == '%')
		{
			ft_putchar('%', pf);
			s++;
		}
		else
		{
			pf->format = ft_substr(s, 1, ft_indexof(s, "cpuidsxX") + 1);
			ft_getformat(pf->format, pf);
		}
		s++;
	}
	va_end(arg);
	return (pf->printed);
}
