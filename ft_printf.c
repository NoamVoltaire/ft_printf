/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:22:03 by nvoltair          #+#    #+#             */
/*   Updated: 2023/11/27 22:12:46 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "some_header_for_printf.h"
#include "ft_printf.h"
// #include "ft_putnbr_base.c"
#include <stdarg.h>
#include <stdio.h>

// int	ft_printf(const char *form, ...)
// {
// 	va_list	args;
// 	int		i;

// 	i = 0;
// 	va_start(args, form);
// 	while (form[i])
// 	{
// 		if (form[i] == '%')
// 		{
// 			check_what_it_is(((char *)form + i), args);
// 			i += 2;
// 		}
// 		else if (form[i] == '\\')
// 		{
// 			check_backslashes((char *)form + i);
// 			i += 2;
// 		}
// 		else
// 		{
// 			write(1, &form[i], 1);
// 			i++;
// 		}
// 	}
// 	return (i - 1);
	//write whatever tf there is the 1st-str until %is met
		// check what it is, and write accordingly,
		//then go back to wrting after %%
		//back to step one
	// '\' is for weird character
int	ft_printf(const char *form, ...)
{
	va_list	args;
	int		i;
	int		len;

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
		else if (form[i] != '%' && form[i] != '\\')
		{
			write(1, &form[i], 1);
			i++;
			len++;
		}
	}
	return (len);
}

int	check_what_it_is(char *form, va_list args)
{
	int i;

	i = 0;
	if (*(form + 1) == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	if (*(form + 1) == 's')
		return (ft_putstr_fd((va_arg(args, void *)), 1));
	if (*(form + 1) == 'p')
	{
		write(1, "0x", 2);
		return (ft_putnbr_base(va_arg(args, unsigned long int))+2);
	}
	if (*(form + 1) == 'd' || *(form + 1) == 'i' || *(form + 1) == 'u')
	{
		i = va_arg(args, int);
		ft_putnbr_fd(i, 1);
		return (nbrlen(i));
		// printf("THE FUN %d\n")
	}
	// if (*(form + 1) == 'u')
		// ft_putnbr_fd(va_arg(args, unsigned int), 1);
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
// int	main(void)
// {
// 	char *a;
// 	char L = 'L';
// 	a = "@@@@@";
// 	int i = 012;
	
// 	ft_printf("abcde %i %i abcde %s abcde %c abcde",i ,i ,a , L);
// 	// i*=-1;
// 	printf("\n unsigned %i %d %p\\?\n", i, i, 'L');
// }

/*
int main() {
    int integerValue = 42;
	int *ptr = &integerValue;
    // float floatValue = 3.14;
    char charValue = 'A';
    char stringValue[] = "Hello, World!";
    unsigned int unsignedValue = 99;

    ft_printf("ft_Char:		_|%c\n", charValue);
    ft_printf("ft_String: 		_|%s\n", stringValue);
    ft_printf("ft_Hexadecimal void:	_|%p\n", ptr);
    ft_printf("ft_Decimal:	 	_|%d\n", integerValue);
    ft_printf("ft_Integer:		_|%i\n", integerValue);
    ft_printf("ft_Unsigned Int:	_|%u\n", unsignedValue);
    ft_printf("ft_Hexadecimal:		_|%x\n", integerValue);
	ft_printf("ft_Hexadecimal Cap:	_|%X\n", integerValue);
   ft_printf("%d\n\n", ft_printf("Ayo%d\n\n", integerValue));
	
    printf("Char:			_|%c\n", charValue);
    printf("String: 		_|%s\n", stringValue);
    printf("Hexadecimal void:	_|%p\n", ptr);
    printf("Decimal:	 	_|%d\n", integerValue);
    printf("Integer:		_|%i\n", integerValue);
    printf("Unsigned Int:		_|%u\n", unsignedValue);
    printf("Hexadecimal:		_|%x\n", integerValue);
    printf("Hexadecimal Cap:	_|%X\n", integerValue);
    printf("%d", printf("Ayo%d\n\n", integerValue));

    return 0;
}
*/