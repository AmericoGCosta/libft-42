/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amgoncal <amgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:49:39 by amgoncal          #+#    #+#             */
/*   Updated: 2023/06/19 17:49:40 by amgoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_checkchr(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*ns;

	if (!s1 || !set)
		return (NULL);
	while (s1)
	{
		if (ft_checkchr(*s1, set) == 1)
			s1++;
		else
			break ;
	}
	len = ft_strlen(s1);
	while (len != 0)
	{
		if (ft_checkchr(s1[len - 1], set) == 1)
			len--;
		else
			break ;
	}
	ns = malloc((len + 1) * (sizeof(char)));
	if (!ns)
		return (NULL);
	ft_strlcpy(ns, s1, len + 1);
	return (ns);
}
