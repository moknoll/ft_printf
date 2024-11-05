/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:28:28 by moritzknoll       #+#    #+#             */
/*   Updated: 2024/11/05 10:53:31 by mknoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	printed_chars;

	printed_chars = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	printed_chars += ft_putstr("0x");
	printed_chars += ft_puthex((uintptr_t)ptr);
	return (printed_chars);
}
