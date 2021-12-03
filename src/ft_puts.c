#include "../ft_printf.h"

void	ft_putchar(char c, int *len)
{
	*len += 1;
	write (1, &c, 1);
}

void	ft_putstr(char *str, int *len)
{
	if (str == 0)
	{
		ft_putstr("(null)", len);
		return ;
	}
	while (*str)
	{
		ft_putchar(*str, len);
		str ++;
	}
}

char	*ft_fillstr(unsigned long nbr, int nbrLen, int base, int isLower)
{
	char	*str;

	str = (char *) malloc(sizeof(char) * (nbrLen + 1));
	if (str == 0)
		return 0;
	str[nbrLen --] = '\0';
	while (nbr / base > 0)
	{	
		if (nbr % base <= 9)
			str[nbrLen --] = nbr % base + '0';
		else if (isLower)
			str[nbrLen --] = (nbr % base) % 10 + 'a';
		else
			str[nbrLen --] = (nbr % base) % 10 + 'A';
		nbr /= base;
	}
	if (nbr % base <= 9)
		str[nbrLen --] = nbr % base + '0';
	else if (isLower)
		str[nbrLen --] = (nbr % base) % 10 + 'a';
	else
		str[nbrLen --] = (nbr % base) % 10 + 'A';
	return str;
}

void	ft_putnbr(int n, int *len)
{
	int		nbrLen;
	int		nbr;
	char	*str;

	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putstr("-2147483648", len);
			return ;
		}
 		ft_putchar('-', len);
 		n *= -1;
 	}
	nbr = n;
	nbrLen = 1;
	while (nbr / 10 > 0)
	{
		nbr /= 10;
		nbrLen ++;
	}
	str = ft_fillstr(n, nbrLen, 10, 0);
	ft_putstr(str, len);
	free(str);
}

void	ft_putnbr_base(unsigned long n, int base, int isLower, int *len)
{
	unsigned long	nbr;
	int				nbrLen;
	char			*str;

	nbr = n;
	nbrLen = 1;
	while (nbr / base > 0)
	{
		nbr /= base;
		nbrLen ++;
	}
	str = ft_fillstr(n, nbrLen, base, isLower);
	ft_putstr(str, len);
	free(str);
}
