#include "ft_printf.h"
#include <stdio.h>
// #include <unistd.h>
// #include <stdarg.h>

// void	ft_putchar(char c)
// {
// 	write (1, &c, 1);
// }

// void	ft_putstr(char *str)
// {
// 	while (*str)
// 	{
// 		ft_putchar(*str);
// 		str ++;
// 	}
// }

// void	ft_putnbr_base(unsigned long n, int base, int x)
// {
// 	if (n / base > 0)
// 	{
// 		ft_putnbr_base(n / base, base, x);
// 		ft_putnbr_base(n % base, base, x);
// 	}
// 	else
// 	{
// 		if (n >= 0 && n <= 9)
// 			ft_putchar(n + '0');
// 		else if (x > 0)
// 			ft_putchar('a' + n % 10);
// 		else
// 			ft_putchar('A' + n % 10);
// 	}
// }

// void	ft_putnbr(int n)
// {
// 	if (n < 0)
// 	{
// 		if (n == -2147483648)
// 		{
// 			ft_putstr("-2147483648");
// 			return ;
// 		}
// 		ft_putchar('-');
// 		n *= -1;
// 	}
// 	if (n / 10 > 0)
// 	{
// 		ft_putnbr(n / 10);
// 		ft_putnbr(n % 10);
// 	}
// 	else
// 		ft_putchar(n + '0');
// }

// void	ft_print_char(va_list pointer)
// {
// 	char	val;

// 	val = va_arg(pointer, int);
// 	ft_putchar(val);
// }

// void	ft_print_string(va_list pointer)
// {
// 	char	*str;

// 	str = va_arg(pointer, char *);
// 	ft_putstr(str);
// }

// void	ft_print_pointer(va_list pointer)
// {
// 	void	*ptr;

// 	ptr = va_arg(pointer, void *);
// 	ft_putstr("0x");
// 	ft_putnbr_base((long)ptr, 16, 1);
// }

// void	ft_print_nbr(va_list pointer)
// {
// 	int	nbr;

// 	nbr = va_arg(pointer, int);
// 	ft_putnbr(nbr);
// }

// void	ft_print_unbr(va_list pointer)
// {
// 	unsigned int	nbr;

// 	nbr = va_arg(pointer, unsigned int);
// 	ft_putnbr_base(nbr, 10, 0);
// }

// void	ft_print_hexnbr(va_list pointer, int x)
// {
// 	unsigned int	nbr;

// 	nbr = va_arg(pointer, unsigned int);
// 	ft_putnbr_base(nbr, 16, x);
// }
// void	ft_select_option(const char *format, va_list pointer)
// {
// 	if (*format == 'c')
// 		ft_print_char(pointer);
// 	else if (*format == 's')
// 		ft_print_string(pointer);
// 	else if (*format == 'p')
// 		ft_print_pointer(pointer);
// 	else if (*format == 'd' || *format == 'i')
// 		ft_print_nbr(pointer);
// 	else if (*format == 'u')
// 		ft_print_unbr(pointer);
// 	else if (*format == 'x')
// 		ft_print_hexnbr(pointer, 1);
// 	else if (*format == 'X')
// 		ft_print_hexnbr(pointer, 0);
// }

// int	ft_printf(const char *format, ...)
// {
// 	va_list	pointer;

// 	va_start(pointer, format);
// 	while (*format)
// 	{
// 		if (*format == '%')
// 		{
// 			format ++;
// 			ft_select_option(format, pointer);
// 			format ++;
// 			continue;
// 		}
// 		write (1, format, 1);
// 		format ++;
// 	}

// }

int main(void)
{
	void *a;
	char b = '8';
	a = &b;
	int len_1 = printf ("Moya %s nemnogo %s %x %% %123\n", "Dasha", "Ebanylas", 1012124234);
	int len_2 = ft_printf ("Moya %s nemnogo %s %x %% %123\n", "Dasha", "Ebanylas", 1012124234);
	printf("orig - %d\nmy - %d\n", len_1, len_2);
	return (0);
}