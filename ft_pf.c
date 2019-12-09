/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <darodrig@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 12:18:15 by darodrig          #+#    #+#             */
/*   Updated: 2019/12/09 12:19:03 by darodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_init(t_pf *pf)
{
	pf->printed = 0;
	pf->zero = 0;
	pf->left = 0;
	pf->width = 0;
	pf->prec = 0;
}

void	pf_reset(t_pf *pf)
{
	pf->zero = 0;
	pf->left = 0;
	pf->width = 0;
	pf->prec = 0;
}
