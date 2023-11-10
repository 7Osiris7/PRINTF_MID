/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruhlman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:46:25 by jruhlman          #+#    #+#             */
/*   Updated: 2023/11/10 17:58:10 by jruhlman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	forme(char **format, t_t *tt, va_list *args)
{
	(*format)++;
	while (**format)
	{
		if (**format == 'c')
			tt->tots_put += ft_printchar(va_arg(args, int), *tt);
		if (**format == 's')
			tt->tots_put += ft_printstr(va_arg(*args, char *), *tt);
		if (**format == 'p')
			tt->tots_put += ft_printptr(va_arg(*args, void *), *tt);
		if (**format == 'i' || **format == 'd')
			tt->tots_put += ft_printnum(va_arg(*args, int), *tt);
		if (**format == 'u')
			tt->tots_put += ft_printunum(va_arg(*args, unsigned int), *tt);
		if (**format == 'x')
			tt->tots_put += ft_printbnum(va_arg(*args, unsigned int), 0, *tt);
		if (**format == 'X')
			tt->tots_put += ft_printbnum(va_arg(*args, unsigned int), 1, *tt);
		if (**format == '%')
			tt->tots_put += ft_printchar('%');
		else
			break ;
		(*format)++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_t	tt;

	tt.tots_put = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			forme(&format, &t_t, &args);
		else
		{
			ft_printchar(*format);
			tt.tots_put++;
			format++;
		}
	}
	va_end(args);
	return (tt.tots_put);
}
