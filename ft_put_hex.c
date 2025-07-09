#include "ft_printf.h"

int ft_put_hex(unsigned long num, int isupper)
{
    char *hex;
    int i;
    int count;
    
    count = 1;
    if (isupper == 0)
        hex = "0123456789abcdef";
    else if (isupper == 1)
        hex = "0123456789ABCDEF";
    if (num >= 16)
        count += ft_put_hex(num / 16, isupper);
    i = num % 16;
    write(1, &hex[i], 1);
    return (count);
}