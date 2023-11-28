/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:54:15 by nvoltair          #+#    #+#             */
/*   Updated: 2023/11/27 22:04:44 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	prt(char c)
{
	write(1, &c, 1);
}

void	writestuff(long int nbr, char *base, int baselength)
{
	char	symb;

	if (nbr >= baselength)
		writestuff(nbr / baselength, base, baselength);
	symb = base[nbr % baselength];
	prt(symb);
	while (*base != symb)
			base++;
}

int	ft_putnbr_base(long long nbr)
{
	int	len;
	char hum[17] = "0123456789abcdef";

	len = 0;
	// if (nbr == -214748364)
	// {
	// 	write (1, "80000000", 8);
	// 	return (8);
	// }
	if (nbr < 0)
		nbr = nbr * -1;
	// baselength = ft_strlen(base);
	// if (baselength < 2 || check_doubles(base) == 1)
		// return ;
	writestuff(nbr, hum, 16);
	if (!nbr)
		return(1);
	while (nbr && (len++ < __INT16_MAX__))
		nbr /= 16;
	return (len);
}

int	ft_putnbr_base_cap(long int nbr)
{
	int	len;
	char hum[17] = "0123456789ABCDEF";

	len = 0;
	if (nbr < 0)
		nbr = nbr * -1;
	// baselength = ft_strlen(base);
	// if (baselength < 2 || check_doubles(base) == 1)
		// return ;
	writestuff(nbr, hum, 16);
	if (!nbr)
		return(1);
	while (nbr && (len++ < __INT16_MAX__))
		nbr /= 16;
	return (len);
}

//0123456789ABCDEF
//0123456789abcdef
// int main ()
// {
// 	ft_putnbr_base(42);
// }
/*
int	main()
{
	ft_putnbr_base(0,"01");
	// printf("%s\n", ft_putnbr_base(42,"01"));
	//  printf("%d\n", ft_strlen("01"));

}

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);

int		main(void)
{
	write(1, "42:", 3);
	ft_putnbr_base(42, "0123456789");
	write(1, "\n2a:", 4);
	ft_putnbr_base(42, "0123456789abcdef");
	write(1, "\n-2a:", 5);
	ft_putnbr_base(-42, "0123456789abcdef");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "0");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "+-0123456789abcdef");
	write(1, "\n:", 2);
	ft_putnbr_base(42, "\t0123456789abcdef");
}
*/