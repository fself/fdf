/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fself <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 14:38:28 by fself             #+#    #+#             */
/*   Updated: 2020/07/15 14:38:32 by fself            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    print_menu(fdf data)
{
    char *menu;

	menu = "up, down, left, right: move picture";
	mlx_string_put(data.mlx_ptr, data.win_ptr, 10, 5, 0x03fc35, menu);
	menu = "esc: exit";
    mlx_string_put(data.mlx_ptr, data.win_ptr, 10, 20, 0x03fc35, menu);
}
