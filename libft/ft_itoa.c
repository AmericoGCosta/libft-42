/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amgoncal <amgoncal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:50:09 by amgoncal          #+#    #+#             */
/*   Updated: 2023/06/19 17:50:10 by amgoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	digits_n(int n)
{
	int	dgts;

	dgts = 0;
	if (n <= 0)
		dgts++;
	while (n != 0)
	{
		n = n / 10;
		dgts++;
	}
	return (dgts);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;

	size = digits_n(n);
	str = malloc(sizeof(int) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		size--;
		str[size] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
