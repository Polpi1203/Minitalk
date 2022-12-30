/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <afaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 11:46:01 by polpi             #+#    #+#             */
/*   Updated: 2022/11/17 13:04:01 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_flag_d(int c);
int		ft_strlen_int(int len);
void	ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(char *str);
int		ft_check(va_list ap, char check);
int		ft_strlen_int(int nbr);
int		ft_flag_c(int c);
int		ft_flag_s(char *str);
int		ft_unsigned_putnbr(unsigned int nbr);
int		ft_flag_u(unsigned int nbr);
int		ft_flag_prc(int c);
int		ft_convert_base(unsigned int nbr, char *str);
int		ft_convert_long(unsigned long nbr, char *str);

#endif