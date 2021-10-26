/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatsusa </var/mail/kmatsusa>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:35:15 by kmatsusa          #+#    #+#             */
/*   Updated: 2021/10/23 16:35:18 by kmatsusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static bool	is_double(char *str, int i)
{
	if (str[i] == '.')
		return (false);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.' && str[i + 1])
	{
		i++;
		while (ft_isdigit(str[i]))
			i++;
		if (str[i])
			return (false);
	}
	else if (!str[i])
		return (true);
	else
		return (false);
	return (true);
}

static double	get_double(char *str, int i, int sign)
{
	double	number;
	double	cnt;

	number = 0;
	while (ft_isdigit(str[i]))
		number = str[i++] - '0' + number * 10;
	if (str[i] == '.')
		i++;
	cnt = 1;
	while (ft_isdigit(str[i]))
	{
		number = str[i++] - '0' + number * 10;
		cnt *= 10;
	}
	return (sign * number / cnt);
}

double	*ft_atof(char *str)
{
	double	*number;
	double	tmp;
	int		sign;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	sign = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (is_double(str, i) == false)
		return (NULL);
	number = (double *)malloc(sizeof(double));
	if (!number)
		return (NULL);
	*number = get_double(str, i, sign);
	return (number);
}
