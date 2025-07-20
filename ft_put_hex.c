/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztaskula <ztaskula@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 05:04:20 by zzehra            #+#    #+#             */
/*   Updated: 2025/07/20 12:48:10 by ztaskula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex(unsigned long num, int isupper)
{
	int		i;
	int		count;
	char	*hex;

	count = 1;
	if (isupper == 0)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (num >= 16)
		count += ft_put_hex(num / 16, isupper);
	i = num % 16;
	write(1, &hex[i], 1);
	return (count);
}
