/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_header_for_printf.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noam <noam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:48:42 by nvoltair          #+#    #+#             */
/*   Updated: 2023/11/26 22:24:08 by noam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOME_HEADER_FOR_PRINTF_H
# define SOME_HEADER_FOR_PRINTF_H

# include <stdio.h>
# include <unistd.h>
// # include "ft_putnbr_base.c"

void	check_what_it_is(char *form, va_list args);
char	ft_strchr(char *s, int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	check_backslashes(char *form);
void	ft_putnbr_base(int nbr);
void	ft_putnbr_base_cap(int nbr);

#endif