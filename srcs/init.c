/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsusa </var/mail/kmatsusa>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:33:32 by kmatsusa          #+#    #+#             */
/*   Updated: 2021/10/23 16:33:34 by kmatsusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_coordinate_init(t_all *all)
{
	all->start_re = -2.0;
	all->start_im = -2.0;
	all->end_re = 2.0;
	all->end_im = 2.0;
}

static void	ft_color_init(t_all *all)
{
	all->color_shift = 0;
}

void	ft_init_win(t_all *all)
{
	all->mlx = NULL;
	all->win = NULL;
	all->data.img = NULL;
	all->data.addr = NULL;
	all->mlx = mlx_init();
	if (!all->mlx)
		ft_exit(all);
	all->win = mlx_new_window(all->mlx, WIDTH, HEIGHT, "fractol");
	if (!all->win)
		ft_exit(all);
	all->data.img = mlx_new_image(all->mlx, WIDTH, HEIGHT);
	if (!all->data.img)
		ft_exit(all);
	all->data.addr = (int *)mlx_get_data_addr(all->data.img,
			&all->data.bpp, &all->data.size_l, &all->data.endian);
	if (!all->data.addr)
		ft_exit(all);
}

void	ft_init(t_all *all)
{
	ft_coordinate_init(all);
	ft_color_init(all);
	ft_init_win(all);
}
