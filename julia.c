/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmohamm <anmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:05:59 by anmohamm          #+#    #+#             */
/*   Updated: 2023/09/21 16:06:02 by anmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "fractol.h"

static	void	algorithm(t_data *img, int w, int h)
{
	double	zx;
	double	zy;

	zx = compute_x0(img, w);
	zy = compute_y0(img, h);
	img->xtemp = 0.0;
	img->iteration = 0;
	img->max_iteration = 500;
	while (zx * zx + zy + zy < 2 * 2 && img->iteration < img->max_iteration)
	{
		img->xtemp = zx * zx - zy * zy;
		zy = 2.0 * zx * zy + img->cy;
		zx = img->xtemp + img->cx;
		img->iteration += 1;
	}
	if (img->iteration == img->max_iteration)
		my_mlx_pixel_put(img, w, h, img->base_color);
	else
		my_mlx_pixel_put(img, w, h, img->base_color * img->iteration);
	w++;
}

void	show_julia(t_data *img)
{
	int	h;
	int	w;

	h = 0;
	while (h < img->height)
	{
		w = 0;
		while (w < img->width)
		{
			algorithm(img, w, h);
			w++;
		}
		h++;
	}
}
