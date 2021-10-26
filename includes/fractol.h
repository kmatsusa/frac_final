/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsusa </var/mail/kmatsusa>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:38:55 by kmatsusa          #+#    #+#             */
/*   Updated: 2021/10/26 14:56:50 by kmatsusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <float.h>
# include <unistd.h>
# include <errno.h>
# include <stdlib.h>
# include <stdbool.h>
# include "struct.h"
# include "define.h"
# include "key_linux.h"

int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_init(t_all *all);
void	ft_coordinate_init(t_all *all);
void	print_err_message(void);
int		ft_exit(t_all *all);
int		ft_key_press(int key, t_all *all);
int		ft_zoom_on(int key, int x, int y, t_all *all);
void	load_info_from_parameters(int ac, char **av, t_all *all);
double	*ft_atof(char *str);
void	set_pixel_mandelbrot(int x, int y, t_all *all);
int		ft_update_color_of_mandelbrot(int x, int y, t_all *all);
void	set_pixel_julia(int x, int y, t_all *all);
int		ft_update_constant_of_julia(int x, int y, t_all *all);
void	set_pixel_burningship(int x, int y, t_all *all);

#endif
