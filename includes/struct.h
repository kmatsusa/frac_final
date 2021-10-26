/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsusa </var/mail/kmatsusa>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:39:22 by kmatsusa          #+#    #+#             */
/*   Updated: 2021/10/23 16:39:26 by kmatsusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "define.h"

typedef struct s_data
{
	void	*img;
	int		*addr;
	int		bpp;
	int		size_l;
	int		endian;
}	t_data;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_all
{
	void	*mlx;
	void	*win;
	int		buf[HEIGHT][WIDTH];
	t_data	data;
	double	old_num;
	double	start_re;
	double	start_im;
	double	end_re;
	double	end_im;
	double	constant_real_num;
	double	constant_imaginary_num;
	int		type_fractol;
	int		flag_cursor_effect;
	int		color_shift;
}	t_all;

#endif
