/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpailhe <vpailhe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 17:00:31 by vpailhe           #+#    #+#             */
/*   Updated: 2015/02/19 05:22:51 by vpailhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include </usr/X11/include/X11/X.h>
# include <mlx.h>
# include "libft/libft.h"

typedef struct		s_mandel{
	double			new_re;
	double			new_im;
	double			old_re;
	double			old_im;
	double			pi;
	double			pr;
}					t_mandel;

typedef struct		s_julia{
	long double		new_re;
	long double		new_im;
	double			old_re;
	double			old_im;
}					t_julia;

typedef	struct		s_env{
	void			*mlx;
	void			*win;
	void			*img;
	char			*dat;
	int				fract_num;
	int				ratio;
	int				bpp;
	int				sl;
	int				endi;
	int				iter;
	int				color;
	int				zoom_count;
	double			mouse_x;
	double			mouse_y;
	float			zoom;
	float			move_x;
	float			move_y;
	t_julia			julia;
}					t_env;

typedef	struct		s_color{
	int				red;
	int				green;
	int				blue;
}					t_color;

typedef	struct		s_fract{
	int				max_iter;
	int				iter;
	long double		y;
	long double		x;
	int				win_y;
	int				win_h;
}					t_fract;

int					main(int argc, char **argv);
void				e_init(t_env *e);
void				refresh_value(t_env *e);
int					expose_hook(t_env *e);
int					mouse_hook(int button, int x, int y, t_env *e);

int					key_hook(int keycode, t_env *e);
void				key_zoom(t_env *e, int keycode);
void				key_movement(t_env *e, int keycode);

void				arg_check(char *arg, t_env *e);
void				print_man(void);

int					get_color(int iteration, int choose);
void				init_fract(t_fract *f);
void				put_pixel_to_image(t_env *e, int x, int y,
					unsigned int color);
void				draw_fractal(t_env *e);

void				julia_iter(t_julia *j, t_env *e);
void				julia_calculation(t_julia *j, t_fract *f, t_env *e);
void				draw_julia(t_env *e);

void				third_iter(t_julia *j);
void				third_calculation(t_julia *j, t_fract *f, t_env *e);
void				draw_third(t_env *e);

void				mandel_iter(t_mandel *m);
void				mandel_calculation(t_mandel *m, t_fract *f, t_env *e);
void				draw_mandel(t_env *e);

#endif
