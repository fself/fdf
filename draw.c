/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fself <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 21:47:23 by fself             #+#    #+#             */
/*   Updated: 2020/07/13 21:47:29 by fself            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

#define MAX1(a, b) (a > b ? a : b)
#define MOD(a) ((a < 0) ? -a : a)

float   mod(float i)
{
    return(i < 0) ? -i : i;
}

void    isometric(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(0.5);
    *y = (*x + *y) * sin(0.5) - z;
}

void    bresenham(float x, float y, float x1, float y1, fdf *data)
{
    float x_step;
    float y_step;
    int max;
    int z;
    int z1;

    z = data->z_matrix[(int)y][(int)x];
    z1 = data->z_matrix[(int)y1][(int)x1];
    //__________zoom__________
    x *= data->zoom;
    y *= data->zoom;
    x1 *= data->zoom;
    y1 *= data->zoom;
    //__________color_________
    data->color = (z || z1) ? 0xe80c0c : 0xffffff;
    //__________3D____________
    isometric(&x, &y, z); 
    isometric(&x1, &y1, z1);
    //__________shift_________
    x += data->shift_x;
    y += data->shift_y;
    x1 += data->shift_x;
    y1 += data->shift_y;
    
    x_step = x1 - x;
    y_step = y1 - y;
    max = MAX(MOD(x_step), MOD(y_step));
    x_step /= max;
    y_step /= max;
    while((int)(x - x1) || (int)(y - y1))
    {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color );
        x += x_step;
        y += y_step;
    }
}

void    draw(fdf *data)
{
    int x;
    int y;
    
    y = 0;
    while (y < data->height)
    {
        x = 0;
        while (x < data->width)
        {
            if (x < data->width - 1)
                bresenham(x, y, x + 1, y, data);
            if (y < data->height - 1)
                bresenham(x, y, x, y + 1, data);
            x++;
        }
        y++;
    }
    
}
