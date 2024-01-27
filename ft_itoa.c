/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euc <euc@student.42istanbul.com.tr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:16:09 by euc               #+#    #+#             */
/*   Updated: 2023/12/11 17:38:10 by euc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_digit(long int n)
{
	int	digit;

	digit = 0;
	if (n == 0)
		digit = 1;
	if (n < 0)
	{
		n *= -1;
		digit++;
	}
	while (n > 0)
	{
		n = n / 10;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	long int	nb;
	int			i;
	int			digit;
	char		*str;

	i = 0;
	nb = (long int)n;
	digit = ft_digit(nb);
	str = (char *)malloc(sizeof(char) * (digit + 1));
	if (!str)
		return (NULL);
	str[digit] = '\0';
	if (nb < 0)
	{
		str[i++] = '-';
		nb *= -1;
	}
	while (i <= --digit)
	{
		str[digit] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}
