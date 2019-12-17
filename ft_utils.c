/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:53:22 by darodrig          #+#    #+#             */
/*   Updated: 2019/12/17 15:52:22 by darodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_getformat(const char *f, t_pf *pf)
{
	while (*f)
	{
		while (*f == '-' || *f == '0')
		{
			if (*f == '-')
				pf->left = 1;
			if (*f == '0')
				pf->zero = 1;
			f++;
		}
		while (ft_isdigit(*f))
		{
			if (pf->width == -1)
				pf->width++;
			pf->width = pf->width * 10 + (*f - '0');
			f++;
		}
		if (*f++ == '.' && (pf->prec++))
		{
			if (*f == '-' && (pf->prec = -1))
				break ;
			while (ft_isdigit(*f))
				pf->prec = pf->prec * 10 + (*f++ - '0');
		}
	}
}

/*
** Returns the index of the first occurrence of any character in set on the
** string s.
*/

int		ft_indexof(const char *s, const char *set)
{
	int i;
	int j;

	i = 1;
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

int		ft_bigger(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

char	*ft_toupper(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] + ('A' - 'a');
		i++;
	}
	return (str);
}
