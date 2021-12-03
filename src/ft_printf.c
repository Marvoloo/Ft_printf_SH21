#include "../ft_printf.h"

void	ft_print_string(va_list pointer, int *len)
{
	char	*str;

	str = va_arg(pointer, char *);
	if (str == 0)
	{
		ft_putstr("(null)", len);
		return ;
	}
	ft_putstr(str, len);
}

void	ft_print_pointer(va_list pointer, int *len)
{
	void	*ptr;

	ptr = va_arg(pointer, void *);
	if (ptr == 0)
	{
		ft_putstr("(nil)", len);
		return ;
	}
	ft_putstr("0x", len);
	ft_putnbr_base((unsigned long)ptr, 16, 1, len);
}

void	ft_select_option(const char *format, va_list pointer, int *len)
{
	if (*format == 'c')
		ft_putchar(va_arg(pointer, int), len);
	else if (*format == 's')
		ft_print_string(pointer, len);
	else if (*format == 'p')
		ft_print_pointer(pointer, len);
	else if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(pointer, int), len);
	else if (*format == 'u')
		ft_putnbr_base(va_arg(pointer, unsigned int), 10, 0, len);
	else if (*format == 'x')
		ft_putnbr_base(va_arg(pointer, unsigned int), 16, 1, len);
	else if (*format == 'X')
		ft_putnbr_base(va_arg(pointer, unsigned int), 16, 0, len);
	else if (*format == '%')
		ft_putstr("%", len);
	else 
	{
		ft_putchar('%', len);
		ft_putchar(*format, len);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	pointer;
	int		len;

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
