/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:22:03 by nvoltair          #+#    #+#             */
/*   Updated: 2023/11/26 22:30:36 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "some_header_for_printf.h"
// #include "ft_putnbr_base.c"
#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *form, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, form);
	while (form[i])
	{
		if (form[i] == '%')
		{
			check_what_it_is(((char *)form + i), args);
			i += 2;
		}
		else if (form[i] == '\\')
		{
			check_backslashes((char *)form + i);
			i += 2;
		}
		else
		{
			write(1, &form[i], 1);
			i++;
		}
	}
	return (0);
	//write whatever tf there is the 1st-str until %is met
		// check what it is, and write accordingly,
		//then go back to wrting after %%
		//back to step one
	// '\' is for weird character
}

void	check_what_it_is(char *form, va_list args)
{
	if (*(form + 1) == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	if (*(form + 1) == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	// if (*(form + 1) == 'p')
		// ft_pustr_fd(va_arg(args, char *), 1);
	// if (*form == '%' || *(form + i) == 'd')
		// ft_putnbr_fd(va_arg(args, int), 1);
	if (*(form + 1) == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	if (*(form + 1) == 'x')
		ft_putnbr_base(va_arg(args, int));
	if (*(form + 1) == 'X')
		ft_putnbr_base_cap(va_arg(args, int));
	if (*(form + 1) == '%')
		write(1, "%", 1);
		return;
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


int main() {
    int integerValue = 42;
    // float floatValue = 3.14;
    char charValue = 'A';
    char stringValue[] = "Hello, World!";
    unsigned int unsignedValue = 99;

    ft_printf("ft_Char:		%c\n", charValue);
    ft_printf("ft_String: 		%s\n", stringValue);
	
    printf("Char:			%c\n", charValue);
    printf("String: 		%s\n", stringValue);
    printf("Hexadecimal void:	%x\n", integerValue);
    printf("Decimal:	 	%d\n", integerValue);
    printf("Integer:		%i\n", integerValue);
    printf("Unsigned Int:		%u\n", unsignedValue);
    printf("Hexadecimal:		%x\n", integerValue);
    ft_printf("ft_Hexadecimal:		%x\n", integerValue);
    printf("Hexadecimal Cap:	%X\n", integerValue);
	ft_printf("ft_Hexadecimal Cap:	%X\n\n", integerValue);

    return 0;
}