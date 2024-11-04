/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:17:44 by moritzknoll       #+#    #+#             */
/*   Updated: 2024/11/04 16:42:30 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>

int	ft_printf(const char *format, ...);
int	ft_check_type(char type, va_list args);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putunsigned(unsigned int nb);
int	ft_putnbr(int nb);
int	ft_puthex(uintptr_t num);
int	ft_putHEX(uintptr_t num);
int	ft_putptr(void *ptr);
#endif
