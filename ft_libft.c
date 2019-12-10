/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 20:12:35 by darodrig          #+#    #+#             */
/*   Updated: 2019/12/10 20:13:45 by darodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new;
	int		i;
	int		j;

	if (!(new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (len == 0 || start > ft_strlen(s))
	{
		if (!(sub = malloc(sizeof(char))))
			return (NULL);
		*sub = '\0';
		return (sub);
	}
	if (!(sub = malloc(len * sizeof(char) + (1 * sizeof(char)))))
		return (NULL);
	s += start;
	i = 0;
	while (i < len && s[i] != '\0')
	{
		sub[i] = s[i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
