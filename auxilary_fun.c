/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxilary_fun.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:53:34 by nvoltair          #+#    #+#             */
/*   Updated: 2023/11/27 22:13:44 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "some_header_for_printf.h"
#include "ft_printf.h"


// char	ft_strchr(char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (c == 0)
// 	{
// 		while (s[i])
// 			i++;
// 		return ((char )s + i);
// 	}
// 	while (s[i])
// 	{
// 		if (s[i] == (char )c)
// 			return ((char )s + i + 1);
// 		i++;
// 	}
// 	return (0);
// }

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] /* && s[i] != '%' */)
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

void	ft_putnbr_fd(long int n, int fd)
{
	long	boi;

	boi = n;
	if (boi == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else
	{
		if (boi >= 0 && boi <= 9)
			ft_putchar_fd('0' + (boi), fd);
		else if (boi < 0)
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(boi * -1, fd);
		}
		else if (boi > 9)
		{
			ft_putnbr_fd(boi / 10, fd);
			ft_putnbr_fd(boi % 10, fd);
		}
	}
}

int	nbrlen(int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		len++;
	while (nbr && (len++ < __INT16_MAX__))
		nbr /= 10;
	// printf("MYBRO IS = %d \n", len);
	return (len);
}
