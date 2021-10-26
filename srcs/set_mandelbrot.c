/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mandelbrot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsusa </var/mail/kmatsusa>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:35:01 by kmatsusa          #+#    #+#             */
/*   Updated: 2021/10/23 16:35:03 by kmatsusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	calc_mandelbrot(int x, int y, t_all *all)
{
	int			i;
	t_complex	constant;
	t_complex	standard;
	t_complex	tmp;

	standard.x = 0;
	standard.y = 0;
	constant.x = (double)x * (all->end_re - all->start_re)
		/ WIDTH + all->start_re;
	constant.y = -(double)y * (all->end_im - all->start_im)
		/ HEIGHT + all->end_im;
	i = 0;
	while (i < MAXCALC && fabs(standard.x + standard.y) <= 2)
	{
		tmp.x = standard.x * standard.x - standard.y * standard.y + constant.x;
		tmp.y = 2 * standard.x * standard.y + constant.y;
		standard.x = tmp.x;
		standard.y = tmp.y;
		i++;
	}
	return (i);
}

int	ft_update_color_of_mandelbrot(int x, int y, t_all *all)
{
	all->color_shift = x + y;
	return (0);
}

void	set_pixel_mandelbrot(int x, int y, t_all *all)
{
	int	count_calc;
	int	color;

	count_calc = calc_mandelbrot(x, y, all);
	color = count_calc * 30 + all->color_shift;
	if (count_calc == MAXCALC)
		all->buf[y][x] = 0x0000000;
	else
		all->buf[y][x] = color;
}
