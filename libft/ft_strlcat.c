/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amgoncal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:00:17 by amgoncal          #+#    #+#             */
/*   Updated: 2023/04/18 16:00:19 by amgoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	l_src;
	size_t	l_dst;

	if (src)
		l_src = ft_strlen(src);
	else
		l_src = 0;
	if (dst)
		l_dst = ft_strlen(dst);
	else
		l_dst = 0;
	i = 0;
	j = l_dst;
	if (size == 0 || size < l_dst)
		return (l_src + size);
	while (src[i] != '\0' && j < (size - 1))
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (l_src + l_dst);
}
