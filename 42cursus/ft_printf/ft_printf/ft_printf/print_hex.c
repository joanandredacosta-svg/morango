/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jda-cost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 02:20:53 by jda-cost          #+#    #+#             */
/*   Updated: 2025/08/15 02:21:01 by jda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex_lower(unsigned int n)
{
	int		i;
	int		count;
	char	*base;
	char	buffer[8];

	i = 0;
	count = 0;
	base = "0123456789abcdef";
	if (n == 0)
		return ((write(1, "0", 1)));
	while (n)
	{
		buffer[i++] = base[n % 16];
		n /= 16;
	}
	while (i--)
		count += write(1, &buffer[i], 1);
	return (count);
}

int	print_hex_upper(unsigned int n)
{
	int		i;
	int		count;
	char	*base;
	char	buffer[8];

	i = 0;
	count = 0;
	base = "0123456789ABCDEF";
	if (n == 0)
		return (write(1, "0", 1));
	while (n)
	{
		buffer[i++] = base[n % 16];
		n /= 16;
	}
	while (i--)
		count += write(1, &buffer[i], 1);
	return (count);
}
