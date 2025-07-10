/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzehra <zzehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 05:04:15 by zzehra            #+#    #+#             */
/*   Updated: 2025/07/10 05:04:45 by zzehra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		total;
	va_list	lst;

	if (!str)
		return (0);
	i = 0;
	total = 0;
	va_start(lst, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			total += ft_find_type(str[i], &lst);
		}
		else
			total += write(1, &str[i], 1);
		i++;
	}
	if (total < 0)
		return (-1);
	va_end(lst);
	return (total);
}
