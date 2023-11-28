/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:22:03 by nvoltair          #+#    #+#             */
/*   Updated: 2023/11/28 17:05:23 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *form, ...)
{
	va_list		args;
	long long	i;
	int			len;

	i = 0;
	len = 0;
	va_start(args, form);
	while (form[i])
	{
		if (form[i] == '%' && form[i + 1])
		{
			len += check_what_it_is(((char *)form + i), args);
			i += 2;
		}
		else if (form[i] == '\\' && form[i + 1])
		{
			check_backslashes((char *)form + i);
			i += 2;
		}
		else if (form[i] != '%' && form[i] != '\\' && (len++ > -1))
			write(1, &form[i++], 1);
	}
	va_end (args);
	return (len);
}

int	check_what_it_is(char *form, va_list args)
{
	if (*(form + 1) == 'c')
		return (ft_putchar_fd(va_arg(args, int)));
	if (*(form + 1) == 's')
		return (ft_putstr_fd((va_arg(args, char *)), 1));
	if (*(form + 1) == 'p')
		return (ft_putnbr_base_p(va_arg(args, unsigned long long)));
	if (*(form + 1) == 'd' || *(form + 1) == 'i')
		return (nbrlen(va_arg(args, int)));
	if (*(form + 1) == 'u')
		return (nbrlen_unsigned(va_arg(args, unsigned int)));
	if (*(form + 1) == 'x')
		return (ft_putnbr_base(va_arg(args, int)));
	if (*(form + 1) == 'X')
		return (ft_putnbr_base_cap(va_arg(args, int)));
	if (*(form + 1) == '%')
		write(1, "%", 1);
	return (1);
}

void	check_backslashes(char *form)
{
	if (*(form + 1) == '\\')
		write(1, "\\", 1);
	if (*(form + 1) == 'n')
		write(1, "\n", 1);
	if (*(form + 1) == 't')
		write(1, "\t", 1);
	if (*(form + 1) == 'v')
		write(1, "\v", 1);
	if (*(form + 1) == 'f')
		write(1, "\f", 1);
	if (*(form + 1) == 'r')
		write(1, "\r", 1);
}

int	ft_putchar_fd(char c)
{
	write(1, &c, 1);
	return (1);
}

/*
int main() {
    int integerValue = 42;
    long long longrValue = __LONG_MAX__;
	long long *ptr = &longrValue;
    // float floatValue = 3.14;
    char charValue = 'A';
    char stringValue[] = "Hello, World!";
    unsigned int unsignedValue = -1;

    ft_printf("ft_Char:		_|%c\n", charValue);
    ft_printf("ft_String: 		_|%s\n", stringValue);
    ft_printf("ft_Hexadecimal void:	_|%p\n", ptr);
    ft_printf("ft_Decimal:	 	_|%d\n", integerValue);
    ft_printf("ft_Integer:		_|%i\n", integerValue);
    ft_printf("ft_Unsigned Int:	_|%u\n", unsignedValue);
    ft_printf("ft_Hexadecimal:		_|%x\n", integerValue);
	ft_printf("ft_Hexadecimal Cap:	_|%X\n", integerValue);
   ft_printf("%d\n\n", ft_printf("Ayo%p\n\n", &integerValue));
	
    printf("Char:			_|%c\n", charValue);
    printf("String: 		_|%s\n", stringValue);
    printf("Hexadecimal void:	_|%p\n", ptr);
    printf("Decimal:	 	_|%d\n", integerValue);
    printf("Integer:		_|%i\n", integerValue);
    printf("Unsigned Int:		_|%u\n", unsignedValue);
    printf("Hexadecimal:		_|%x\n", integerValue);
    printf("Hexadecimal Cap:	_|%X\n", integerValue);
    printf("%d\n\n", printf("Ayo%p\n\n", &integerValue));

    return 0;
}
*/