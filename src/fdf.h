/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fself <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 19:43:01 by fself             #+#    #+#             */
/*   Updated: 2020/07/19 19:51:02 by fself            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <math.h>
# include "../minilibx_macos/mlx.h"
# define PRM matrix[0][0]

typedef struct
{
	float		x;
	float		y;
	float		z;
	int			is_last;

	int			color;
	int			scale;
	int			z_scale;
	int			shift_x;
	int			shift_y;
	int			is_isometric;
	double		angle;
	int			win_x;
	int			win_y;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_data;

t_data			**read_map(char *file_name);
void			isometric(t_data *dot, double angle);
void			draw(t_data **matrix);
int				deal_key(int key, t_data **matrix);
void			set_param(t_data *a, t_data *b, t_data *param);
void			print_menu(t_data param);
void			ft_error(char *msg);
void			new_window(int key, t_data **matrix);

#endif
