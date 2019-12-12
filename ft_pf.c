/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:57:22 by darodrig          #+#    #+#             */
/*   Updated: 2019/12/12 18:28:46 by darodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_init(t_pf *pf)
{
	pf->printed = 0;
	pf->zero = 0;
	pf->left = 0;
	pf->width = -1;
	pf->prec = -1;
	pf->sign = 1;
	pf->nb = 0;
}

void	pf_reset(t_pf *pf)
{
	pf->zero = 0;
	pf->left = 0;
	pf->width = -1;
	pf->prec = -1;
	pf->sign = 1;
	pf->nb = 0;
}
