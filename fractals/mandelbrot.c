/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpailhe <vpailhe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 04:22:55 by vpailhe           #+#    #+#             */
/*   Updated: 2015/02/18 22:46:32 by vpailhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void			mandel_iter(t_mandel *m)
{
	m->old_re = m->new_re;
	m->old_im = m->new_im;
	m->new_re = m->old_re * m->old_re - m->old_im * m->old_im + m->pr;
	m->new_im = 2 * m->old_re * m->old_im + m->pi;
}

void			mandel_calculation(t_mandel *m, t_fract *f, t_env *e)
{
	m->pr = 1.5 * (f->x - f->win_y / 2) /
		(0.5 * e->zoom * f->win_y) + e->move_x;
	m->pi = (f->y - f->win_h / 2) / (0.5 * e->zoom * f->win_h) + e->move_y;
	m->old_im = 0;
	m->old_re = 0;
	m->new_im = 0;
	m->new_re = 0;
	f->iter = 0;
}

void			draw_mandel(t_env *e)
{
	t_fract		f;
	t_mandel	m;

	init_fract(&f);
	while (f.x < f.win_y)
	{
		while (f.y < f.win_h)
		{
			mandel_calculation(&m, &f, e);
			while (f.iter < f.max_iter)
			{
				mandel_iter(&m);
				if ((m.new_re * m.new_re + m.new_im * m.new_im) > 4)
					break ;
				f.iter++;
			}
			put_pixel_to_image(&(*e), f.x, f.y, get_color(f.iter, e->color));
			f.y++;
		}
		f.y = 0;
		f.x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
