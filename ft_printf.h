/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jruhlman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:10:17 by jruhlman          #+#    #+#             */
/*   Updated: 2023/11/10 18:22:04 by jruhlman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

typedef struct	s_t
{
	int	precision;
	int	min_w;
	int	offset;
	int	tots_put;
	int	sharp;
	int	space;
	int	plus;
	int	zero;
	int	zero_offset;
	int	minus;
	int	dot;
}	t_t;

int	ft_printf(const char *format, ...);
int	ft_printchar(char c, t_t tt);
int	ft_printstr(char *str, t_t tt);
int	ft_printptr(void *ptr, t_t tt);
int	ft_printnum(long num, t_t tt);
int	ft_printunum(unsigned long num, t_t tt);
int	ft_printbnum(int num, int is_upper, t_t tt);

#endif
