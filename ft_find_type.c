/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzehra <zzehra@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 05:04:09 by zzehra            #+#    #+#             */
/*   Updated: 2025/07/13 20:19:59 by ztaskula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_find_type4(char c, va_list *lst)
{
	int				count;
	unsigned int	num;

	count = 0;
	if (c == 'x')
	{
		num = va_arg(*lst, unsigned int);
		count += ft_put_hex(num, 0);
	}
	else if (c == 'X')
	{
		num = va_arg(*lst, unsigned int);
		count += ft_put_hex(num, 1);
	}
	return (count);
}

static int	ft_find_type3(char c, va_list *lst)
{
	int				count;
	unsigned int	nb;
	char			*number;
	char			*tmp;

	count = 0;
	if (c == 'u')
	{
		nb = va_arg(*lst, unsigned int);
		number = ft_uitoa(nb);
		tmp = number;
		while (*tmp)
			count += write(1, tmp++, 1);
		free(number);
	}
	else
		count += ft_find_type4(c, lst);
	return (count);
}

static int	ft_find_type2(char c, va_list *lst)
{
	int		count;
	int		nb;
	char	*number;
	char	*tmp;

	count = 0;
	if (c == 'd' || c == 'i')
	{
		nb = va_arg(*lst, int);
		number = ft_itoa(nb);
		tmp = number;
		while (*tmp)
			count += write(1, tmp++, 1);
		free(number);
	}
	else
		count += ft_find_type3(c, lst);
	return (count);
}

static int	ft_find_type1(char c, va_list *lst)
{
	int				count;
	unsigned long	addr;
	void			*p;

	count = 0;
	if (c == 'p')
	{
		p = va_arg(*lst, void *);
		addr = (unsigned long)p;
		if (addr == 0)
			return (write(1, "(nil)", 5));
		write(1, "0x", 2);
		count += 2;
		count += ft_put_hex(addr, 0);
	}
	else if (c == '%')
		count += write(1, "%", 1);
	else
		count += ft_find_type2(c, lst);
	return (count);
}

int	ft_find_type(char c, va_list *lst)
{
	int		count;
	char	ch;
	char	*str;

	count = 0;
	if (c == 'c')
	{
		ch = va_arg(*lst, int);
		count += write(1, &ch, 1);
	}
	else if (c == 's')
	{
		str = va_arg(*lst, char *);
		if (!str)
			return (write(1, "(null)", 6));
		while (*str)
		{
			count += write(1, str, 1);
			str++;
		}
	}
	else
		count += ft_find_type1(c, lst);
	return (count);
}
