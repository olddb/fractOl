/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpailhe <vpailhe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 16:54:41 by vpailhe           #+#    #+#             */
/*   Updated: 2015/02/19 04:51:29 by vpailhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					expose_hook(t_env *e)
{
	draw_fractal(&(*e));
	return (0);
}

int					mouse_movement(int x, int y, t_env *e)
{
	double			x2;
	double			y2;

	x2 = x;
	y2 = y;
	if (e->fract_num == 2)
	{
		e->mouse_x = (x2 / 250) - 2;
		e->mouse_y = (y2 / 175) - 2;
		draw_fractal(&(*e));
	}
	return (0);
}

int					mouse_hook(int button, int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		e->zoom += 0.4;
		e->zoom_count++;
		draw_fractal(&(*e));
	}
	if (button == 5)
	{
		if (e->zoom_count > -1)
		{
			e->zoom -= 0.4;
			e->zoom_count--;
			draw_fractal(&(*e));
		}
	}
	return (0);
}

void				e_init(t_env *e)
{
	e->zoom = 1;
	e->zoom_count = 1;
	e->move_x = 0;
	e->move_y = 0;
	e->mouse_x = -0.7;
	e->mouse_y = 0.27015;
}

int					main(int argc, char **argv)
{
	static t_env	e;

	if (argc == 2)
	{
		arg_check(argv[1], &e);
		if (e.fract_num == -1)
		{
			print_man();
			return (0);
		}
		e.mlx = mlx_init();
		e_init(&e);
		e.win = mlx_new_window(e.mlx, 1000, 700, argv[1]);
		e.img = mlx_new_image(e.mlx, 1000, 700);
		e.dat = mlx_get_data_addr(e.img, &e.bpp, &e.sl, &e.endi);
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_hook(e.win, 2, 3, key_hook, &e);
		mlx_mouse_hook(e.win, mouse_hook, &e);
		mlx_hook(e.win, MotionNotify, PointerMotionMask, mouse_movement, &e);
		mlx_loop(e.mlx);
	}
	print_man();
	return (0);
}
