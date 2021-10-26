/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_info_from_parameters.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsusa </var/mail/kmatsusa>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:33:58 by kmatsusa          #+#    #+#             */
/*   Updated: 2021/10/23 16:34:00 by kmatsusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_fractol(char **av, t_all *all)
{
	if (!ft_strncmp(av[1], "mandelbrot", 11))
		all->type_fractol = MANDELBROT;
	else if (!ft_strncmp(av[1], "julia", 6))
		all->type_fractol = JULIA;
	else if (!ft_strncmp(av[1], "burningship", 12))
		all->type_fractol = BURNINGSHIP;
	else
		print_err_message();
}

static void	switch_cursor_effect(char **av, t_all *all)
{
	if (all->type_fractol == MANDELBROT || all->type_fractol == JULIA)
	{
		if (av[2] && !ft_strncmp(av[2], "plain", 6))
			all->flag_cursor_effect = OFF;
		else if (av[2] && !ft_strncmp(av[2], "dynamic", 8))
			all->flag_cursor_effect = ON;
		else
			print_err_message();
	}
	else if (all->type_fractol == BURNINGSHIP && !av[2])
		return ;
	else
		print_err_message();
}

static double	get_const_number(char *num)
{
	double	*tmp;
	double	res;

	if (ft_strlen(num) > 20)
		print_err_message();
	tmp = ft_atof(num);
	if (!tmp)
		print_err_message();
	res = *tmp;
	free(tmp);
	tmp = NULL;
	return (res);
}

static void	set_const_number(char **av, int ac, t_all *all)
{
	if (ac > 3 && all->type_fractol == MANDELBROT)
		print_err_message();
	all->constant_real_num = -0.8;
	if (av[3] && all->type_fractol == JULIA)
		all->constant_real_num = get_const_number(av[3]);
	all->constant_imaginary_num = 0.15;
	if (av[3] && av[4] && all->type_fractol == JULIA)
		all->constant_imaginary_num = get_const_number(av[4]);
}

void	load_info_from_parameters(int ac, char **av, t_all *all)
{
	if (ac > 5)
		print_err_message();
	set_fractol(av, all);
	switch_cursor_effect(av, all);
	set_const_number(av, ac, all);
}
