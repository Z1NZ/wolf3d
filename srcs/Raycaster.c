/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 15:06:00 by srabah            #+#    #+#             */
/*   Updated: 2015/05/02 19:35:18 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/wolf3d.h"
#include <math.h>
#include <assert.h>

static	void	ray_init(int x)
{
	G(monde).camerax = 2 * x / (double)L_W - 1;
	G(monde).rayposx = G(monde).posx;
	G(monde).rayposy = G(monde).posy;
	G(monde).raydirx = G(monde).dirx + G(monde).planex * G(monde).camerax;
	G(monde).raydiry = G(monde).diry + G(monde).planey * G(monde).camerax;
	G(monde).mapx = (int)G(monde).rayposx;
	G(monde).mapy = (int)G(monde).rayposy;
	G(monde).deltadistx = sqrt(1 + (G(monde).raydiry * G(monde).raydiry) /
	(G(monde).raydirx * G(monde).raydirx));
	G(monde).deltadisty = sqrt(1 + (G(monde).raydirx * G(monde).raydirx) /
	(G(monde).raydiry * G(monde).raydiry));
	G(monde).hit = 0;
}

static	void	ft_dda(void)
{
	while (G(monde).hit == 0)
	{
		if (G(monde).sidedistx < G(monde).sidedisty)
		{
			G(monde).sidedistx += G(monde).deltadistx;
			G(monde).mapx += G(monde).stepx;
			G(monde).side = 0;
		}
		else
		{
			G(monde).sidedisty += G(monde).deltadisty;
			G(monde).mapy += G(monde).stepy;
			G(monde).side = 1;
		}
		if (G(monde).worldmap[G(monde).mapx][G(monde).mapy] != 0)
			G(monde).hit = 1;
	}
}

static	void	step_init(void)
{
	if (G(monde).raydirx < 0)
	{
		G(monde).stepx = -1;
		G(monde).sidedistx = (G(monde).rayposx - G(monde).mapx) *
		G(monde).deltadistx;
	}
	else
	{
		G(monde).stepx = 1;
		G(monde).sidedistx = (G(monde).mapx + 1.0 - G(monde).rayposx) *
		G(monde).deltadistx;
	}
	if (G(monde).raydiry < 0)
	{
		G(monde).stepy = -1;
		G(monde).sidedisty = (G(monde).rayposy - G(monde).mapy) *
		G(monde).deltadisty;
	}
	else
	{
		G(monde).stepy = 1;
		G(monde).sidedisty = (G(monde).mapy + 1.0 - G(monde).rayposy) *
		G(monde).deltadisty;
	}
}

void			ft_init_wall(void)
{
	if (G(monde).side == 0)
		G(monde).perpwalldist = fabs((G(monde).mapx - G(monde).rayposx +
		(1 - G(monde).stepx) / 2) / G(monde).raydirx);
	else
		G(monde).perpwalldist = fabs((G(monde).mapy - G(monde).rayposy +
		(1 - G(monde).stepy) / 2) / G(monde).raydiry);
	G(monde).lineheight = abs((int)(H_W / G(monde).perpwalldist));
	G(monde).drawstart = -G(monde).lineheight / 2 + H_W / 2;
	if (G(monde).drawstart < 0)
		G(monde).drawstart = 0;
	G(monde).drawend = G(monde).lineheight / 2 + H_W / 2;
	if (G(monde).drawend >= H_W - 1)
		G(monde).drawend = H_W - 1;
}

void			raycaster(void)
{
	int x;

	x = 0;
	while (x < L_W)
	{
		ray_init(x);
		step_init();
		ft_dda();
		ft_init_wall();
		ft_color();
		verline(x, G(monde).drawstart, G(monde).drawend, G(monde).color);
		x++;
	}
	mlx_put_image_to_window(G(env).mlx, G(env).win, G(env).img, 0, 0);
}
