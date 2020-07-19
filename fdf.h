/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fself <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 21:48:12 by fself             #+#    #+#             */
/*   Updated: 2020/07/13 21:48:14 by fself            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

typedef struct 
{
    int width;
    int height;
    int **z_matrix;
    int zoom;
    int color;
    int shift_x;
    int shift_y;

    void    *mlx_ptr;
    void    *win_ptr;
}           fdf;

void    read_file(char *file_name, fdf *data);
void    bresenham(float x, float y, float x1, float y1, fdf *data);
void    draw(fdf *data);
void    print_menu(fdf data);
int     dial_key(int key, fdf *data);

#endif
