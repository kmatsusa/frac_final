/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_julia.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsusa </var/mail/kmatsusa>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:34:46 by kmatsusa          #+#    #+#             */
/*   Updated: 2021/10/23 16:34:50 by kmatsusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	calc_burningship(int x, int y, t_all *all)
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
		tmp.x = fabs(standard.x);
		tmp.y = fabs(standard.y);
		standard.x = pow(tmp.x, 2) - pow(tmp.y, 2) + constant.x;
		standard.y = 2 * tmp.x * tmp.y + constant.y;
		i++;
	}
	return (i);
}

void	set_pixel_burningship(int x, int y, t_all *all)
{
	int	count_calc;
	int	color;

	count_calc = calc_burningship(x, y, all);
	color = count_calc * 50 + x + y;
	if (count_calc == MAXCALC)
		all->buf[y][x] = 0;
	else
		all->buf[y][x] = color;
}
