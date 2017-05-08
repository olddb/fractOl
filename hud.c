/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpailhe <vpailhe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 03:18:38 by vpailhe           #+#    #+#             */
/*   Updated: 2015/02/18 22:52:36 by vpailhe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	arg_check(char *arg, t_env *e)
{
	if (ft_strcmp("mandelbrot", arg) == 0)
		e->fract_num = 1;
	else if (ft_strcmp("julia", arg) == 0)
		e->fract_num = 2;
	else if (ft_strcmp("third", arg) == 0)
		e->fract_num = 3;
	else
		e->fract_num = -1;
}

void	print_man(void)
{
	ft_putstr("usage : Choose the fractal between \n");
	ft_putstr("      - mandelbrot\n");
	ft_putstr("      - julia\n");
	ft_putstr("      - third\n\n");
	ft_putstr("Press : <SPACE> to change colors\n");
	ft_putstr("        <ESC>   to quit\n");
	ft_putstr("        <f>     to reset\n");
	ft_putstr("        <+>     to zoom\n");
	ft_putstr("        <->     to dezoom\n");
}
