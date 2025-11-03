/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jda-cost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 02:20:04 by jda-cost          #+#    #+#             */
/*   Updated: 2025/08/15 02:20:14 by jda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	return ((write(1, &c, 1)));
}

int	print_string(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		s = "(null)";
	while (s[len])
		write(1, &s[len++], 1);
	return (len);
}
