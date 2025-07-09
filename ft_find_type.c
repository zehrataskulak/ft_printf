#include "ft_printf.h"

static void ft_put_hex(unsigned long num, int isupper)
{
    char *hex;
    int i;

    if (isupper == 0)
        hex = "0123456789abcdef";
    else if (isupper == 1)
        hex = "0123456789ABCDEF";
    if (num >= 16)
        ft_put_hex(num / 16, isupper);
    i = num % 16;
    write(1, &hex[i], 1);
}

static void ft_find_type2(char c, va_list *lst)
{
    if(c == 'x')
    {
        unsigned int num;

        num = va_arg(*lst, unsigned int);
        ft_put_hex(num, 0);
    }
    else if(c == 'X')
    {
        unsigned int num;

        num = va_arg(*lst, unsigned int);
        ft_put_hex(num, 1);
    }
}

static void ft_find_type1(char c, va_list *lst)
{
    if(c == 'd' || c == 'i')
    {
        int nb;
        char *number;
        char *tmp;

        nb = va_arg(*lst, int);
        number = ft_itoa(nb);
        tmp = number;
        while(*tmp)
            write(1, tmp++, 1);
        free(number);
    }
    else if (c == 'u')
    {
        unsigned int nb;
        char *number;
        char *tmp;

        nb = va_arg(*lst, unsigned int);
        number = ft_uitoa(nb);
        tmp = number;
        while(*tmp)
            write(1, tmp++, 1);
        free(number);
    }
    else
        ft_find_type2(c, lst);
}

void ft_find_type(char c, va_list *lst)
{
    if(c == '%')
        write(1, "%", 1);
    else if(c == 'c')
    {
        char ca;
        ca = va_arg(*lst, int);
        write(1, &ca, 1);
    }
    else if(c == 's')
    {
        char *ca;
        ca = va_arg(*lst, char *);
        while(*ca)
        {
            write(1, ca, 1);
            ca++;
        }
    }
    else if(c == 'p')
    {
        void *p;
        unsigned long addr;
        p = va_arg(*lst, void *);
        addr = (unsigned long)p;
        write(1, "0x", 2);
        ft_put_hex(addr, 0);
    }
    else
        ft_find_type1(c, lst);
}