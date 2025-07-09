#include "ft_printf.h"

static int	ft_digit(unsigned int n)
{
	int	digit;

	digit = 1;
	while (n > 9)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

static void	ft_putdigit(char *num, unsigned int n, int digit)
{
	while (digit > 0)
	{
		num[digit - 1] = n % 10 + '0';
		n /= 10;
		digit--;
	}
}

char	*ft_uitoa(unsigned int n)
{
	int		digit;
	char	*num;

	num = malloc (ft_digit(n) + 1);
	if (num == NULL)
		return (NULL);
	digit = ft_digit(n);
	num[digit] = '\0';
	ft_putdigit(num, n, digit);
	return (num);
}