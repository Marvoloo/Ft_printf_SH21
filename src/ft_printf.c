#include "../ft_printf.h"

void	ft_print_char(va_list pointer, int *len)
{
	char	val;

	val = va_arg(pointer, int);
	*len += 1;
	ft_putchar(val);
}

void	ft_select_option(const char *format, va_list pointer, int *len)
{
	if (*format == 'c')
		ft_print_char(pointer, len);
	else if (*format == 's')
		ft_print_string(pointer, len);
	else if (*format == 'p')
		ft_print_pointer(pointer, len);
	else if (*format == 'd' || *format == 'i')
		ft_print_nbr(pointer, len);
	else if (*format == 'u')
		ft_print_unbr(pointer, len);
	else if (*format == 'x')
		ft_print_hexnbr(pointer, 1, len);
	else if (*format == 'X')
		ft_print_hexnbr(pointer, 0, len);
	else if (*format == '%')
		ft_putstr("%", len);
	else 
	{
		ft_putchar('%');
		ft_putchar(*format);
		*len += 2;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	pointer;
	int	len;

	len = 0;
	va_start(pointer, format);
	while (*format)
	{
		if (*format == '%')
		{
			format ++;
			ft_select_option(format, pointer, &len);
			format ++;
			continue;
		}
		write (1, format, 1);
		format ++;
		len ++;
	}
	va_end(pointer);
	return (len);
}
