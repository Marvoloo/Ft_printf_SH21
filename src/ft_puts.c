#include "../ft_printf.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str, int *len)
{
	while (*str)
	{
		*len += 1;
		ft_putchar(*str);
		str ++;
	}
}

void	ft_putnbr_base(unsigned long n, int base, int x, int *len)
{
	if (n / base > 0)
	{
		ft_putnbr_base(n / base, base, x, len);
		ft_putnbr_base(n % base, base, x, len);
	}
	else
	{
		if (n <= 9)
		{
			*len += 1;
			ft_putchar(n + '0');
		}
		else if (x > 0)
		{
			*len += 1;
			ft_putchar('a' + n % 10);
		}
		else
		{
			*len += 1;
			ft_putchar('A' + n % 10);
		}
	}
}

void	ft_putnbr(int n, int *len)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putstr("-2147483648", len);
			return ;
		}
		ft_putchar('-');
		*len += 1;
		n *= -1;
	}
	if (n / 10 > 0)
	{
		ft_putnbr(n / 10, len);
		ft_putnbr(n % 10, len);
	}
	else
	{
		ft_putchar(n + '0');
		*len += 1;
	}
}

// size_t	ft_strlen(const char *c)
// {
// 	size_t	len;

// 	len = 0;
// 	while (*c != '\0')
// 	{
// 		c ++;
// 		len ++;
// 	}
// 	return (len);
// }

// int	ft_nbrlen(long nbr, int base)
// {
// 	int	len;

// 	if (nbr > 0)
// 	len = 1;
// 	else
// 	{
// 		len = 2;
// 		nbr *= -1;
// 	}
// 	while (nbr / base > 0)
// 	{
// 		len ++;
// 		nbr = nbr / base;
// 	}
// 	return (len);
// }