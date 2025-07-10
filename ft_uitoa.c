/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzehra <zzehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 05:04:22 by zzehra            #+#    #+#             */
/*   Updated: 2025/07/10 05:04:23 by zzehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_digit(unsigned int n)
{
	int	digit;

	digit = 1;
	while (n > 9)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

static void	ft_putdigit(char *num, unsigned int n, int digit)
{
	while (digit > 0)
	{
		num[digit - 1] = n % 10 + '0';
		n /= 10;
		digit--;
	}
}

char	*ft_uitoa(unsigned int n)
{
	int		digit;
	char	*num;

	num = malloc (ft_digit(n) + 1);
	if (num == NULL)
		return (NULL);
	digit = ft_digit(n);
	num[digit] = '\0';
	ft_putdigit(num, n, digit);
	return (num);
}
