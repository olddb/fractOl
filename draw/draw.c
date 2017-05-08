/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpailhe <vpailhe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 18:59:47 by vpailhe           #+#    #+#             */
/*   Updated: 2015/02/19 01:15:35 by vpailhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../fractol.h"

void		refresh_value(t_env *e)
{
	e->move_x = 0;
	e->move_y = 0;
	e->zoom = 1;
	e->mouse_x = -0.7;
	e->mouse_y = 0.27015;
	e_init(&(*e));
	draw_fractal(&(*e));
}

int			get_color(int iteration, int choose)
{
	int		color;

	color = 0x646465;
	if (choose == 1)
	{
		if (iteration % 2 == 0)
			return (0xFFFFFF);
		else
			return (0x000000);
	}
	if (iteration < 2 && iteration >= 0)
		color = 0x000000;
	if (iteration < 5 && iteration >= 2)
		color = 0xFF0000;
	if (iteration < 20 && iteration >= 5)
		color = 0x000066;
	if (iteration < 45 && iteration >= 20)
		color = 0x990033;
	if (iteration < 60 && iteration >= 45)
		color = 0xCC6699;
	if (iteration < 90 && iteration >= 60)
		color = 0xFF9900;
	return (color * (iteration * 100));
}

void		init_fract(t_fract *f)
{
	f->max_iter = 90;
	f->iter = 0;
	f->y = 0;
	f->x = 0;
	f->win_y = 1000;
	f->win_h = 700;
}

void		put_pixel_to_image(t_env *e, int x, int y, unsigned int color)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int				index;

	index = ((y * e->sl) + (x * (e->bpp / 8)));
	r = ((color & 0xFF0000) >> 16);
	g = ((color & 0xFF00) >> 8);
	b = ((color & 0xFF));
	e->dat[index] = b;
	e->dat[index + 1] = g;
	e->dat[index + 2] = r;
}

void		draw_fractal(t_env *e)
{
	if (e->fract_num == 1)
		draw_mandel(&(*e));
	if (e->fract_num == 2)
		draw_julia(&(*e));
	if (e->fract_num == 3)
		draw_third(&(*e));
}
