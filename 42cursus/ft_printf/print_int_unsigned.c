/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jda-cost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 02:20:29 by jda-cost          #+#    #+#             */
/*   Updated: 2025/08/15 02:20:38 by jda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(int n)
{
	int		i;
	int		count;
	long	num;
	char	buffer[12];

	i = 0;
	count = 0;
	num = n;
	if (num < 0)
	{
		count += write(1, "-", 1);
		num = -num;
	}
	if (num == 0)
		return (write(1, "0", 1));
	while (num)
	{
		buffer[i++] = '0' + (num % 10);
		num /= 10;
	}
	while (i--)
		count += write(1, &buffer[i], 1);
	return (count);
}

int	print_unsigned(unsigned int n)
{
	int		i;
	int		count;
	char	buffer[10];

	i = 0;
	count = 0;
	if (n == 0)
		return (write(1, "0", 1));
	while (n)
	{
		buffer[i++] = '0' + (n % 10);
		n /= 10;
	}
	while (i--)
		count += write(1, &buffer[i], 1);
	return (count);
}
