/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 15:53:22 by darodrig          #+#    #+#             */
/*   Updated: 2019/12/10 15:57:09 by darodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_getformat(const char *f, t_pf *pf)
{
	while (*f)
	{
		if (*f == '-' && (pf->left = 1))
			f++;
		else if (*f == '0' && (pf->zero = 1))
			f++;
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
}

/*
** Returns the index of the first occurrence of any character in set on the
** string s.
*/

int		ft_indexof(const char *s, const char *set)
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

int		ft_bigger(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	ft_append(char **str, char c)
{
	char	*new;
	char	append[2];

	if (!str || !*str)
		return ;
	append[0] = c;
	append[1] = '\0';
	new = ft_strjoin(*str, append);
	if (*str)
		free(*str);
	*str = new;
}

void	ft_asterix(t_pf *pf, va_list arg)
{
	char	*new;
	char	*tmp;
	int		i;
	char	*nb;

	new = ft_strdup("");
	i = 0;
	while (*pf->str)
	{
		if (*pf->str == '*')
		{
			nb = ft_itoa(va_arg(arg, int));
			tmp = ft_strjoin(new, nb);
			free(new);
			new = tmp;
			free(nb);
		}
		else
			ft_append(&new, *pf->str);
		pf->str++;
	}
	pf->str = new;
}
