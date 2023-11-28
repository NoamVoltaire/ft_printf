/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:48:42 by nvoltair          #+#    #+#             */
/*   Updated: 2023/11/28 16:46:27 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *form, ...);
int		check_what_it_is(char *form, va_list args);
int		ft_putchar_fd(char c);
int		ft_putstr_fd(char *s, int fd);
void	ft_putnbr(long int n);
void	ft_putnbr_fd(unsigned int n);
void	check_backslashes(char *form);
int		ft_putnbr_base(unsigned int nbr);
int		ft_putnbr_base_cap(unsigned int nbr);
int		ft_putnbr_base_p(unsigned long long nbr);
int		nbrlen(long long nbr);
int		nbrlen_unsigned(long long nbr);

#endif