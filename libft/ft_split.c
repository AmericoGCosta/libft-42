/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amgoncal <amgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:49:50 by amgoncal          #+#    #+#             */
/*   Updated: 2023/06/19 17:49:52 by amgoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	count(const char *str, char c)
{
	int	i;
	int	sw;

	i = 0;
	sw = 0;
	while (*str)
	{
		if (sw == 0 && *str != c)
		{
			i++;
			sw = 1;
		}
		else if (*str == c)
			sw = 0;
		str++;
	}
	return (i);
}

char	*words(const char *str, int first, int last)
{
	char	*w;
	int		i;

	i = 0;
	w = malloc((last - first + 1) * sizeof(char ));
	while (first < last)
		w[i++] = str[first++];
	w[i] = 0;
	return (w);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	int		first;
	size_t	last;
	char	**str;

	i = 0;
	first = -1;
	last = 0;
	str = malloc((count(s, c) + 1) * sizeof(char *));
	if (!s || !str)
		return (0);
	while (last <= ft_strlen(s))
	{
		if (s[last] != c && first < 0)
			first = last;
		else if ((s[last] == c || last == ft_strlen(s)) && first >= 0)
		{
			str[i++] = words(s, first, last);
			first = -1;
		}
		last++;
	}
	str[i] = '\0';
	return (str);
}
