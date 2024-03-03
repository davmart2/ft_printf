/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmart2 <davmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:12:02 by davmart2          #+#    #+#             */
/*   Updated: 2024/01/28 11:41:12 by davmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char spec, va_list args)
{
	int	count;

	count = 0;
	if (spec == 'c')
		count += print_char(va_arg(args, int));
	else if (spec == 's')
		count += print_string(va_arg(args, char *));
	else if (spec == 'd' || spec == 'i')
		count += print_nbr((va_arg(args, int)), "0123456789");
	else if (spec == 'u')
		count += print_unbr((va_arg(args, unsigned int)), "0123456789");
	else if (spec == 'x')
		count += print_hexnbr((va_arg(args, unsigned int)), "0123456789abcdef");
	else if (spec == 'X')
		count += print_hexnbr((va_arg(args, unsigned int)), "0123456789ABCDEF");
	else if (spec == 'p')
	{
		count = print_string("0x");
		count += point((unsigned long)va_arg(args, void *), "0123456789abcdef");
	}
	else if (spec == '%')
		count = print_char('%');
	else
		count = write(1, &spec, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			count += print_format(*(++format), args);
		}
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(args);
	return (count);
}
