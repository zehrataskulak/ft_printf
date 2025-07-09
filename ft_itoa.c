#include "ft_printf.h"

static char	*ft_strdup(const char *s)
{
	int		size;
	int		i;
	char	*p;

	size = 0;
	i = 0;
	while (s[size])
		size++;
	p = malloc((size + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static int	ft_digit(int n)
{
	int	digit;

	digit = 1;
	if (n < 0)
		digit++;
	while (n > 9 || n < -9)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

static void	ft_putdigit(char *num, int n, int digit, int isngtv)
{
	while (digit > 0)
	{
		num[digit - 1] = n % 10 + '0';
		n /= 10;
		digit--;
	}
	if (isngtv == 1)
		num[0] = '-';
}

char	*ft_itoa(int n)
{
	int		digit;
	int		isngtv;
	char	*num;

	if (n == -2147483648)
	{
		num = ft_strdup("-2147483648");
		return (num);
	}
	isngtv = 0;
	num = malloc (ft_digit(n) + 1);
	if (num == NULL)
		return (NULL);
	digit = ft_digit(n);
	num[digit] = '\0';
	if (n < 0)
	{
		n *= -1;
		isngtv = 1;
	}
	ft_putdigit(num, n, digit, isngtv);
	return (num);
}