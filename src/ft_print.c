#include "../ft_printf.h"
#include <stdio.h>

void	ft_print_string(va_list pointer, int *len)
{
	char	*str;

	str = va_arg(pointer, char *);
	if (str == 0)
	{
		ft_putstr("(null)", len);
		return ;
	}
	//*len += ft_strlen(str);
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
	//*len = *len + 2 + ft_nbrlen((unsigned long)ptr, 16);
	ft_putnbr_base((unsigned long)ptr, 16, 1, len);
}

void	ft_print_nbr(va_list pointer, int *len)
{
	int	nbr;

	nbr = va_arg(pointer, int);
	//*len += ft_nbrlen(nbr, 10);
	ft_putnbr(nbr, len);
}

void	ft_print_unbr(va_list pointer, int *len)
{
	unsigned int	nbr;

	nbr = va_arg(pointer, unsigned int);
	//*len += ft_nbrlen(nbr, 10);
	ft_putnbr_base(nbr, 10, 0, len);
}

void	ft_print_hexnbr(va_list pointer, int x, int *len)
{
	unsigned int	nbr;

	nbr = va_arg(pointer, unsigned int);
	//*len += ft_nbrlen(nbr, 16);
	ft_putnbr_base(nbr, 16, x, len);
}
