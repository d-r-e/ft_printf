/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <darodrig@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 17:03:22 by darodrig          #+#    #+#             */
/*   Updated: 2019/12/09 18:05:18 by darodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_getformat(const char *f, t_pf *pf)
{
	while (*f)
	{
		if (*f == '-')
		{
			pf->left = 1;
			f++;
		}
		else if (*f == '0')
		{
			pf->zero = 1;
			f++;
		}
		while (ft_isdigit(*f))
		{
			pf->width = pf->width * 10 + (*f - '0');
			f++;
		}
		if (*f++ == '.')
		{
			while (ft_isdigit(*f))
			{
				pf->prec = pf->prec * 10 + (*f - '0');
				f++;
			}
		}
	}
	printf("LEFT=%d\nZERO=%d\nWIDTH=%d\nPREC=%d\n",pf->left, pf->zero, pf->width, pf->prec);
}

/*
** Returns the index of the first occurrence of any character in set on the 
** string s.
*/

int	ft_indexof(const char *s, const char *set)
{
	int i;
	int j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (set[j])
		{
			if (set[j] == s[i])
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}
