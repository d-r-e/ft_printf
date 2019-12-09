#include "ft_printf.h"

void	pf_init(t_pf *pf)
{
	pf->printed = 0;
	pf->zero = 0;
	pf->left = 0;
	pf->width = 0;
	pf->prec = 0;
}
