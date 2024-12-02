#include <stdarg.h>
#include "ft_printf.h"

static int handle_conversion(va_list args, char specifier)
{
    switch (specifier)
    {
        case 'c': return ft_putchar_fd(va_arg(args, int), 1);
    /*    case 's': return ft_putstr_fd(va_arg(args, char *), 1);
        case 'd':
        case 'i': return ft_putnbr_fd(va_arg(args, int), 1);
        case 'u': return ft_putunbr_fd(va_arg(args, unsigned int), 1);
        case 'x': return ft_puthex_fd(va_arg(args, unsigned int), 1, 0);
        case 'X': return ft_puthex_fd(va_arg(args, unsigned int), 1, 1);
        case 'p': return ft_putpointer_fd(va_arg(args, void *), 1);
        case '%': return ft_putchar_fd('%', 1); */
        default: return 0; 
    }
}

int ft_printf(const char *str, ...)
{
    va_list args;
    int     i = 0;
    int     len = 0;

    va_start(args, str);
    while (str[i])
    {
        if (str[i] == '%' && str[i + 1])
        {
            len += handle_conversion(args, str[++i]); 
        }
        else
        {
            ft_putchar_fd(str[i], 1); 
            len++;
        }
        i++; 
    }
    va_end(args);
    return (len); 
}


int main (void)
{
    ft_printf("%c", 'c');
    return 0;
}