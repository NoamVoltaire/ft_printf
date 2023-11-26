/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:54:15 by nvoltair          #+#    #+#             */
/*   Updated: 2023/11/26 22:18:29 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	prt(char c)
{
	write(1, &c, 1);
}

void	writestuff(int nbr, char *base, int baselength)
{
	char	symb;

	if (nbr >= baselength)
		writestuff(nbr / baselength, base, baselength);
	symb = base[nbr % baselength];
	prt(symb);
	while (*base != symb)
			base++;
}

void	ft_putnbr_base(int nbr)
{
	// int	baselength;
	char hum[17] = "0123456789abcdef";

	// base = 
	if (nbr < 0)
		nbr = nbr * -1;
	// baselength = ft_strlen(base);
	// if (baselength < 2 || check_doubles(base) == 1)
		// return ;
	writestuff(nbr, hum, 16);
}

void	ft_putnbr_base_cap(int nbr)
{
	// int	baselength;
	char hum[17] = "0123456789ABCDEF";

	// base = 
	if (nbr < 0)
		nbr = nbr * -1;
	// baselength = ft_strlen(base);
	// if (baselength < 2 || check_doubles(base) == 1)
		// return ;
	writestuff(nbr, hum, 16);
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