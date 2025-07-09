#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int ft_printf(const char *str, ...);
int ft_find_type(char c, va_list *lst);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
int ft_put_hex(unsigned long num, int isupper);

#endif