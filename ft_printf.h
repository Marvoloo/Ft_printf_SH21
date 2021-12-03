#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

char	*ft_fillstr(unsigned long nbr, int nbrLen, int base, int isLower);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *str, int *len);
void	ft_putnbr_base(unsigned long n, int base, int isLower, int *len);
void	ft_putnbr(int n, int *len);
void	ft_print_string(va_list pointer, int *len);
void	ft_print_pointer(va_list pointer, int *len);
void	ft_select_option(const char *format, va_list pointer, int *len);
int		ft_printf(const char *format, ...);

#endif