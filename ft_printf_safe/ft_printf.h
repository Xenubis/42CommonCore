/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmusquer <mmusquer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:47:32 by mmusquer          #+#    #+#             */
/*   Updated: 2025/11/18 19:19:33 by mmusquer         ###   ########.fr       */
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
int	ft_conversion(char c, va_list args, int *count);
int	ft_print_char(char c, int *count);
int	ft_print_str(char *str, int *count);
int	ft_print_nbr(int n, int *count);
int	ft_print_unbr(unsigned int n, int *count);
int	ft_print_ptr(unsigned long long ptr, int *count);
int	ft_print_hex(unsigned int n, int c, int *count);
int	ft_write(char *ptr, size_t len, int *count);

#endif