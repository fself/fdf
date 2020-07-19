/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fself <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 21:48:25 by fself             #+#    #+#             */
/*   Updated: 2020/07/13 21:48:27 by fself            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
    fdf *data;
    
    data = (fdf*)malloc(sizeof(fdf));
    read_file(argv[1], data);
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, 600, 600, "FDF");
    data->zoom =  20;

    // bresenham(10, 10, 600, 300, data);
    draw(data);
    mlx_key_hook(data->win_ptr, dial_key, data);
    mlx_loop(data->mlx_ptr);
}