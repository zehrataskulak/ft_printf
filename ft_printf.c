#include "ft_printf.h"


int ft_printf(const char *str, ...)
{
    int i;
    va_list lst;
    int total;

    if(!str)
        return (0);
    i = 0;
    total = 0;
    va_start(lst, str);
    while (str[i])
    {
        if (str[i] == '%')
        {
            i++;
            if(str[i])
            {
                total += ft_find_type(str[i], &lst);
            }
        }
        else
        {
            write(1, &str[i], 1);
            total++;
        }
        i++;
    }
    va_end(lst);
    return (total);
}