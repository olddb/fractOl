/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpailhe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 07:57:49 by vpailhe           #+#    #+#             */
/*   Updated: 2015/02/19 02:01:06 by vpailhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				key_hook(int keycode, t_env *e)
{
	if (keycode == 32)
	{
		if (e->color == 0)
			e->color = 1;
		else
			e->color = 0;
		draw_fractal(&(*e));
	}
	if (keycode == 65307)
		exit(0);
	if (keycode == 102)
		refresh_value(&(*e));
	if (keycode == 65453 || keycode == 65451)
		key_zoom(&(*e), keycode);
	if (keycode >= 65361 || keycode <= 65364)
		key_movement(&(*e), keycode);
	return (0);
}

void			key_zoom(t_env *e, int keycode)
{
	if (keycode == 65453)
	{
		if (e->zoom_count > 0)
		{
			e->zoom_count--;
			e->zoom -= 0.4;
			draw_fractal(&(*e));
		}
	}
	if (keycode == 65451)
	{
		e->zoom_count++;
		e->zoom += 0.4;
		draw_fractal(&(*e));
	}
}

void			key_movement(t_env *e, int keycode)
{
	if (keycode == 65361)
	{
		e->move_x -= (0.1 / e->zoom);
		draw_fractal(&(*e));
	}
	if (keycode == 65363)
	{
		e->move_x += (0.1 / e->zoom);
		draw_fractal(&(*e));
	}
	if (keycode == 65364)
	{
		e->move_y += (0.1 / e->zoom);
		draw_fractal(&(*e));
	}
	if (keycode == 65362)
	{
		e->move_y -= (0.1 / e->zoom);
		draw_fractal(&(*e));
	}
}
