/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asterix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 10:27:11 by darodrig          #+#    #+#             */
/*   Updated: 2019/12/17 10:38:34 by darodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	while (pf->format[i])
	{
		if (pf->format[i] == '*')
		{
			nb = ft_itoa(va_arg(arg, int));
			tmp = ft_strjoin(new, nb);
			free(new);
			new = tmp;
			free(nb);
		}
		else
			ft_append(&new, pf->format[i]);
		i++;
	}
	free(pf->format);
	pf->format = new;
}
