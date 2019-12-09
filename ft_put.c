#include "ft_printf.h"

void	ft_putchar(char c, t_pf pf)
{
	write(1, &c, 1);
	pf->printed++;
}

void	ft_putstr(const char *str, t_pf pf)
{
	while (*str)
	{
		ft_putchar(*str, pf);
		str++;
	}
}
