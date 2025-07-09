#include "ft_printf.h"


int ft_printf(const char *str, ...)
{
    int i;
    va_list lst;

    i = 0;
    va_start(lst, str);
    while (str[i])
    {
        if (str[i] == '%')
        {
            i++;
            if(str[i])
            {
                ft_find_type(str[i], &lst);
            }
        }
        else
            write(1, &str[i], 1);
        i++;
    }
    va_end(lst);
    return (1);
}

#include <stdio.h>

/*int main()
{
    //ft_printf("selam%%%%");
    //ft_printf("\t");
    ft_printf("\t");
    ft_printf("selam%%");
    ft_printf("\n");
}*/