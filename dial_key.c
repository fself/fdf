#include "fdf.h"

int dial_key(int key, fdf *data)
{
    ft_printf("%d\n", key);
    
    if (key == 126)
        data->shift_y -= 10;
    if (key == 125)
        data->shift_y += 10;
    if (key == 123)
        data->shift_x -= 10;
    if (key == 124)
        data->shift_x += 10;
    if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free(data); 
		exit(0);
	}
    
    mlx_clear_window(data->mlx_ptr, data->win_ptr); 
    draw(data);
    print_menu(*data);
    return (0);
}