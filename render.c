/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmohamm <anmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:06:35 by anmohamm          #+#    #+#             */
/*   Updated: 2023/09/28 19:43:25 by anmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

double	compute_x0(t_data *img, int w)
{
	double	result;

	result = (w - img->width / 2)
		/ (0.25 * img->zoom * img->width) + img->x_move;
	return (result);
}

double	compute_y0(t_data *img, int h)
{
	double	result;

	result = (h - img->height / 2)
		/ (0.25 * img->zoom * img->height) + img->y_move;
	return (result);
}

void	ft_error(void)
{
	ft_putstr("Invalid Arguments\n");
	ft_putstr("For Mandelbrot set: Enter => ./fractol 1\n");
	ft_putstr("For Julia set: Enter => ./fractol <value> <value>");
	ft_putstr("(The values must be between -2.0 & 2.0)\n");
	ft_putstr("For Tricorn set: Enter => ./fractol 2\n");
	exit(1);
}

int	ft_close(void)
{
	exit (1);
	return (0);
}
