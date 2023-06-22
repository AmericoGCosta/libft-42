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

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	fi;
	size_t	li;
	char	*str;

	fi = 0;
	li = ft_strlen(s1) - 1;
	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, s1[fi]) && fi <= li)
		fi++;
	if (fi > li)
		return (ft_strdup(s1 + (li + 1)));
	while (ft_strchr(set, s1[li]) && li >= 0)
		li--;
	str = malloc(sizeof(char) * (li - fi + 2));
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[fi], li - fi + 2);
	return (str);
}
