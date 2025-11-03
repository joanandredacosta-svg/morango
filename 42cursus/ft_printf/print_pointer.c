/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jda-cost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 02:21:21 by jda-cost          #+#    #+#             */
/*   Updated: 2025/08/15 02:21:29 by jda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(unsigned long ptr)
{
	int		i;
	int		count;
	char	*base;
	char	buffer[16];

	i = 0;
	count = 0;
	base = "0123456789abcdef";
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	while (ptr)
	{
		buffer[i++] = base[ptr % 16];
		ptr /= 16;
	}
	while (i--)
		count += write(1, &buffer[i], 1);
	return (count);
}
