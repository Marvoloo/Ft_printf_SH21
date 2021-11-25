#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

// size_t	ft_strlen(const char *c);
// int		ft_nbrlen(long nbr, int base);
void	ft_putchar(char c);
void	ft_putstr(char *str, int *len);
void	ft_putnbr_base(unsigned long n, int base, int x, int *len);
void	ft_putnbr(int n, int *len);
void	ft_print_char(va_list pointer, int *len);
void	ft_print_string(va_list pointer, int *len);
void	ft_print_pointer(va_list pointer, int *len);
void	ft_print_nbr(va_list pointer, int *len);
void	ft_print_unbr(va_list pointer, int *len);
void	ft_print_hexnbr(va_list pointer, int x, int *len);
void	ft_select_option(const char *format, va_list pointer, int *len);
int		ft_printf(const char *format, ...);
#endif