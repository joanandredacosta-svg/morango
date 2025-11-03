/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jda-cost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 00:16:19 by jda-cost          #+#    #+#             */
/*   Updated: 2025/08/19 19:34:36 by jda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char specifier, va_list args)
{
	if (specifier == 'c')
		return (print_char(va_arg(args, int)));
	if (specifier == 's')
		return (print_string(va_arg(args, char *)));
	if (specifier == 'p')
		return (print_pointer(va_arg(args, unsigned long)));
	if (specifier == 'd' || specifier == 'i')
		return (print_int(va_arg(args, int)));
	if (specifier == 'u')
		return (print_unsigned(va_arg(args, unsigned int)));
	if (specifier == 'x')
		return (print_hex_lower(va_arg(args, unsigned int)));
	if (specifier == 'X')
		return (print_hex_upper(va_arg(args, unsigned int)));
	if (specifier == '%')
		return (print_char('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			count += ft_format(format[++i], args);
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
