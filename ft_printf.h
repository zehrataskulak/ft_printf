#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int ft_printf(const char *str, ...);
void ft_find_type(char c, va_list *lst);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);

#endif