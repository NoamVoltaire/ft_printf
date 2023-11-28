/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:48:42 by nvoltair          #+#    #+#             */
/*   Updated: 2023/11/27 22:04:55 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
// # include "ft_putnbr_base.c"

int		ft_printf(const char *form, ...);
int		check_what_it_is(char *form, va_list args);
// char	ft_strchr(char *s, int c);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(long int n, int fd);
void	check_backslashes(char *form);
int		ft_putnbr_base(long long nbr);
int		ft_putnbr_base_cap(long int nbr);
int		nbrlen(int nbr);

#endif