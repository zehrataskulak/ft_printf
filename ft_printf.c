/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztaskula <ztaskula@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 05:04:15 by zzehra            #+#    #+#             */
/*   Updated: 2025/07/20 18:18:50 by ztaskula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		total;
	va_list	lst;

	i = 0;
	total = 0;
	va_start(lst, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			total += ft_find_type(str[i], &lst);
		}
		else
			total += write(1, &str[i], 1);
		i++;
	}
	va_end(lst);
	return (total);
}
