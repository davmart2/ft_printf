/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmart2 <davmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:08:51 by davmart2          #+#    #+#             */
/*   Updated: 2024/01/28 11:41:37 by davmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	print_char(int c);
int	print_string(char *str);
int	print_nbr(int n, char *base);
int	print_unbr(unsigned int n, char *base);
int	point(unsigned long n, char *base);
int	print_hexnbr(unsigned int n, char *base);
int	ft_printf(const char *format, ...);
int	print_format(char spec, va_list args);

#endif
