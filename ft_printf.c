/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:22:03 by nvoltair          #+#    #+#             */
/*   Updated: 2023/11/25 18:10:51 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "some_header_for_printf.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_printf(const char *form, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, form);
	while (/*form[i]*/ i < 10)
	{
		if (form[i] == '%')
		{
			check_what_it_is((char *)form + i, args);
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
	if (*form == '%' || *(form + 1) == 'c')
		ft_putchar_fd(va_arg(args, char), 1);
	if (*form == '%' || *(form + 1) == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	// if (*form == '%' || *(form + 1) == 'p')
		// ft_pustr_fd(va_arg(args, char *), 1);
	// if (*form == '%' || *(form + i) == 'd')
		// ft_putnbr_fd(va_arg(args, int), 1);
	if (*form == '%' || *(form + 1) == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
}

int	main(void)
{
	char a[] = "@@@@@";
	int i = 123456789;
	
	ft_printf("abcde%iAAABBB%s cool",i ,a);
}
