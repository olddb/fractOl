/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   juju.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpailhe <vpailhe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 03:50:00 by vpailhe           #+#    #+#             */
/*   Updated: 2015/02/18 22:46:14 by vpailhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void		julia_iter(t_julia *j, t_env *e)
{
	j->old_re = j->new_re;
	j->old_im = j->new_im;
	j->new_re = j->old_re * j->old_re - j->old_im * j->old_im + e->mouse_x;
	j->new_im = 2 * j->old_re * j->old_im + e->mouse_y;
}

void		julia_calculation(t_julia *j, t_fract *f, t_env *e)
{
	j->new_re = 1.5 * (f->x - f->win_y / 2) /
		(0.5 * e->zoom * f->win_y) + e->move_x;
	j->new_im = (f->y - f->win_h / 2) / (0.5 * e->zoom * f->win_h) + e->move_y;
	f->iter = 0;
}

void		draw_julia(t_env *e)
{
	t_fract	f;
	t_julia	j;

	init_fract(&f);
	while (f.x < f.win_y)
	{
		while (f.y < f.win_h)
		{
			julia_calculation(&j, &f, e);
			while (f.iter < f.max_iter)
			{
				julia_iter(&j, &(*e));
				if ((j.new_re * j.new_re + j.new_im * j.new_im) > 4)
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
