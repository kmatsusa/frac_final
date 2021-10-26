/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsusa </var/mail/kmatsusa>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:33:14 by kmatsusa          #+#    #+#             */
/*   Updated: 2021/10/23 16:33:21 by kmatsusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_err_message(void)
{
	ft_putstr_fd("\x1b[31m", 2);
	ft_putstr_fd("ERROR\n", 2);
	ft_putstr_fd("\x1b[0m", 2);
	ft_putstr_fd("\x1b[1m\tWrong input\n\n", 2);
	ft_putstr_fd("\x1b[0m", 2);
	ft_putstr_fd("\x1b[1margv[1]\x1b[0m", 2);
	ft_putstr_fd(":Fractal name\n", 2);
	ft_putstr_fd("\tjulia\n", 2);
	ft_putstr_fd("\tmandelbrot\n", 2);
	ft_putstr_fd("\tburningship\n", 2);
	ft_putstr_fd("\n\x1b[1margv[2]\x1b[0m", 2);
	ft_putstr_fd(":Cursor effect (mandelbrot, julia) \n", 2);
	ft_putstr_fd("\tplain\n", 2);
	ft_putstr_fd("\tdynamic\n", 2);
	ft_putstr_fd("\n\x1b[1margv[3]\x1b[0m", 2);
	ft_putstr_fd(":Real number (julia) \n", 2);
	ft_putstr_fd("\n\x1b[1margv[4]\x1b[0m", 2);
	ft_putstr_fd(":Imaginary number (julia) \n", 2);
	exit(1);
}

int	ft_exit(t_all *all)
{
	if (all->win)
		mlx_destroy_window(all->mlx, all->win);
	if (all->data.img)
		mlx_destroy_image(all->mlx, all->data.img);
	if (all->mlx)
	{
		mlx_destroy_display(all->mlx);
		free(all->mlx);
	}
	exit(0);
	return (0);
}
