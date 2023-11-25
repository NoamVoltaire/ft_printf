/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_header_for_printf.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvoltair <nvoltair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:48:42 by nvoltair          #+#    #+#             */
/*   Updated: 2023/11/25 18:02:58 by nvoltair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOME_HEADER_FOR_PRINTF_H
# define SOME_HEADER_FOR_PRINTF_H

# include <stdio.h>
# include <unistd.h>

void	check_what_it_is(char *form, va_list args);
char	ft_strchr(char *s, int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif