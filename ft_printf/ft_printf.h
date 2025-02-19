/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:16:19 by lzorzit           #+#    #+#             */
/*   Updated: 2024/07/23 17:16:35 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_countpnt(unsigned long n);
int		ft_printf(const char *par, ...);
int		ft_putex(unsigned int n, int form);
int		ft_putnbr(int n);
int		ft_putnbruns(unsigned int n);
int		ft_putpoint(uintptr_t arg);
int		sort(va_list arg, const char par);
int		ft_putchar(int c);
int		ft_putstr(char *s);

#endif
