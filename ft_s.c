/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:22:45 by darodrig          #+#    #+#             */
/*   Updated: 2019/12/10 19:14:16 by darodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_spaces(int n)
{
	char	*s;
	int		i;

	i = 0;
	if (!(s = malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (n > 0)
	{
		s[i] = ' ';
		i++;
		n--;
	}
	s[i] = '\0';
	return (s);
}

void	ft_trunc(char **s, size_t len)
{
	char	*tmp;

	tmp = ft_substr(*s, 0, len);
	free(*s);
	*s = tmp;
}

void	ft_enlarge(char **s, size_t len, t_pf *pf)
{
	chdar	*spaces;
	char	*new;

	if (len > ft_strlen(*s))
	{
		spaces = ft_spaces(len - ft_strlen(*s));
		if (pf->left == 0)
			new = ft_strjoin(spaces, *s);
		else
			new = ft_strjoin(*s, spaces);
		free(spaces);
		free(*s);
		*s = new;
	}
}

void	ft_print_string(t_pf *pf, va_list arg)
{
	pf->str = ft_strdup(va_arg(arg, char*));
	if (!pf->str)
		pf->str = ft_strdup("(null)");
	if (pf->prec != -1)
		ft_trunc(&pf->str, pf->prec);
	if (pf->width != -1)
		ft_enlarge(&pf->str, pf->width, pf);
	ft_putstr(pf->str, pf);
	free(pf->str);
}
