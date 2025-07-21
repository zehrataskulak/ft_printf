/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztaskula <ztaskula@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 05:04:17 by zzehra            #+#    #+#             */
/*   Updated: 2025/07/21 12:36:20 by ztaskula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_find_type(char c, va_list lst);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
int		ft_put_hex(unsigned long num, int isupper);

#endif
