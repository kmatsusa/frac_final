/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsusa </var/mail/kmatsusa>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:32:43 by kmatsusa          #+#    #+#             */
/*   Updated: 2021/10/23 16:33:02 by kmatsusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_move(int key, t_all *all)
{
	all->old_num = all->start_re;
	if (key == K_LEFT)
	{
		all->start_re = all->start_re
			- (all->end_re - all->start_re) * 100 / WIDTH;
		all->end_re = all->end_re - (all->end_re - all->old_num) * 100 / WIDTH;
	}
	if (key == K_RIGHT)
	{
		all->start_re = all->start_re
			+ (all->end_re - all->start_re) * 100 / WIDTH;
		all->end_re = all->end_re + (all->end_re - all->old_num) * 100 / WIDTH;
	}
	if (key == K_DOWN)
	{
		all->start_im = all->start_im
			- (all->end_im - all->old_num) * 10 / HEIGHT;
		all->end_im = all->end_im - (all->end_im - all->old_num) * 10 / HEIGHT;
	}
	if (key == K_UP)
	{
		all->start_im = all->start_im
			+ (all->end_im - all->old_num) * 10 / HEIGHT;
		all->end_im = all->end_im + (all->end_im - all->old_num) * 10 / HEIGHT;
	}
}

int	ft_key_press(int key, t_all *all)
{
	if (key == K_ESC)
		ft_exit(all);
	else if (key == K_LEFT || key == K_RIGHT || key == K_DOWN || key == K_UP)
		ft_move(key, all);
	return (0);
}

static double	set_mouse_x_cordinate(int n, int size, double start, double end)
{
	double	res;

	res = ((double)n / size) * (end - start) + start;
	return (res);
}

static double	set_mouse_y_cordinate(int n, int size, double start, double end)
{
	double	res;

	res = -((double)n / size) * (end - start) + end;
	return (res);
}

int	ft_zoom_on(int key, int x, int y, t_all *all)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = set_mouse_x_cordinate(x, WIDTH, all->start_re, all->end_re);
	mouse_im = set_mouse_y_cordinate(y, HEIGHT, all->start_im, all->end_im);
	if (key == WHEEL_UP && (all->end_re - all->start_re) > 0.0000000001
		&& (all->end_im - all->start_im) > 0.0000000001)
	{
		all->start_re = mouse_re + (all->start_re - mouse_re) * 0.8;
		all->start_im = mouse_im + (all->start_im - mouse_im) * 0.8;
		all->end_re = mouse_re + (all->end_re - mouse_re) * 0.8;
		all->end_im = mouse_im + (all->end_im - mouse_im) * 0.8;
	}
	else if (key == WHEEL_DOWN && (all->end_re - all->start_re) < 1000
		&& (all->end_im - all->start_im) < 1000)
	{
		all->start_re = mouse_re + (all->start_re - mouse_re) * 1.05;
		all->start_im = mouse_im + (all->start_im - mouse_im) * 1.05;
		all->end_re = mouse_re + (all->end_re - mouse_re) * 1.05;
		all->end_im = mouse_im + (all->end_im - mouse_im) * 1.05;
	}
	else if (key == CLICK)
		ft_coordinate_init(all);
	return (0);
}
