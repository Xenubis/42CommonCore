/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:47:32 by mmusquer          #+#    #+#             */
/*   Updated: 2025/11/18 16:08:30 by mmusquer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_conversion(va_list args, char c);
int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_nbr(int n);
int	ft_print_unbr(unsigned int n);
int	ft_print_ptr(unsigned long long ptr);
int	ft_print_hex(unsigned int n, char c);

#endif