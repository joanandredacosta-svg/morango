/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jda-cost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 00:15:38 by jda-cost          #+#    #+#             */
/*   Updated: 2025/08/15 00:16:05 by jda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	print_char(char c);
int	print_string(const char *s);
int	print_int(int n);
int	print_unsigned(unsigned int n);
int	print_hex_lower(unsigned int n);
int	print_hex_upper(unsigned int n);
int	print_pointer(unsigned long ptr);

#endif
