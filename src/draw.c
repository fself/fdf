/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fself <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 19:42:06 by fself             #+#    #+#             */
/*   Updated: 2020/07/19 19:48:39 by fself            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	fmodule(float i)
{
	return (i < 0) ? -i : i;
}

void	line(t_data a, t_data b, t_data *param)
{
	float	step_x;
	float	step_y;
	float	max;
	int		color;

	set_param(&a, &b, param);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = MAX(fmodule(step_x), fmodule(step_y));
	step_x /= max;
	step_y /= max;
	color = (b.z || a.z) ? 0xfc0345 : 0xBBFAFF;
	color = (b.z != a.z) ? 0xfc031c : color;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, a.x, a.y, color);
		a.x += step_x;
		a.y += step_y;
		if (a.x > param->win_x || a.y > param->win_y || a.y < 0 || a.x < 0)
			break ;
	}
}

void	draw(t_data **matrix)
{
	int		y;
	int		x;

	print_menu(PRM);
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (1)
		{
			if (matrix[y + 1])
				line(matrix[y][x], matrix[y + 1][x], &PRM);
			if (!matrix[y][x].is_last)
				line(matrix[y][x], matrix[y][x + 1], &PRM);
			if (matrix[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
}
