/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_julia.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsusa </var/mail/kmatsusa>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:34:46 by kmatsusa          #+#    #+#             */
/*   Updated: 2021/10/28 18:42:26 by kmatsusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	calc_julia(int x, int y, t_all *all)
{
	int			i;
	t_complex	constant;
	t_complex	standard;
	t_complex	tmp;

	standard.x = (double)x * (all->end_re - all->start_re)
		/ WIDTH + all->start_re;
	standard.y = -(double)y * (all->end_im - all->start_im)
		/ HEIGHT + all->end_im;
	constant.x = all->constant_real_num;
	constant.y = all->constant_imaginary_num;
	i = 0;
	while (i < MAXCALC && fabs(standard.x + standard.y) <= 2)
	{
		tmp.x = standard.x * standard.x - standard.y
			* standard.y + constant.x;
		tmp.y = 2 * standard.x * standard.y + constant.y;
		standard.x = tmp.x;
		standard.y = tmp.y;
		i++;
	}
	return (i);
}

int	ft_update_constant_of_julia(int x, int y, t_all *all)
{
	all->constant_real_num = ((double)x / WIDTH)
		* (all->end_re - all->start_re) + all->start_re;
	all->constant_imaginary_num = ((double)y / HEIGHT)
		* (all->end_im - all->start_im) + all->start_im;
	return (0);
}

void	set_pixel_julia(int x, int y, t_all *all)
{
	int	count_calc;
	int	color;

	count_calc = calc_julia(x, y, all);
	color = count_calc * 10000 + x + y;
	if (count_calc == MAXCALC)
		all->buf[y][x] = 0x00000000;
	else
		all->buf[y][x] = color;
}
