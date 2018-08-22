/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 00:00:29 by srabah            #+#    #+#             */
/*   Updated: 2015/05/03 00:14:22 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static	void	ft_right(void)
{
	double oldplane;
	double olddir;

	olddir = G(monde).dirx;
	G(monde).dirx = G(monde).dirx * cos(-G(monde).rotspeed) - G(monde).diry *
		sin(-G(monde).rotspeed);
	G(monde).diry = olddir * sin(-G(monde).rotspeed) + G(monde).diry *
		cos(-G(monde).rotspeed);
	oldplane = G(monde).planex;
	G(monde).planex = G(monde).planex * cos(-G(monde).rotspeed)
	- G(monde).planey * sin(-G(monde).rotspeed);
	G(monde).planey = oldplane * sin(-G(monde).rotspeed)
	+ G(monde).planey * cos(-G(monde).rotspeed);
}

static	void	ft_left(void)
{
	double olddir;
	double oldplane;

	olddir = G(monde).dirx;
	G(monde).dirx = G(monde).dirx * cos(G(monde).rotspeed)
	- G(monde).diry * sin(G(monde).rotspeed);
	G(monde).diry = olddir * sin(G(monde).rotspeed) +
		G(monde).diry * cos(G(monde).rotspeed);
	oldplane = G(monde).planex;
	G(monde).planex = G(monde).planex * cos(G(monde).rotspeed)
		- G(monde).planey * sin(G(monde).rotspeed);
	G(monde).planey = oldplane * sin(G(monde).rotspeed)
		+ G(monde).planey * cos(G(monde).rotspeed);
}

static	void	ft_up(void)
{
	if (G(monde).worldmap[(int)(G(monde).posx + G(monde).dirx
		* G(monde).movespeed)][(int)G(monde).posy] == 0)
		G(monde).posx += G(monde).dirx * G(monde).movespeed;
	if (G(monde).worldmap[(int)G(monde).posx][(int)(G(monde).posy
		+ G(monde).diry * G(monde).movespeed)] == 0)
		G(monde).posy += G(monde).diry * G(monde).movespeed;
}

static	void	ft_down(void)
{
	if (G(monde).worldmap[(int)(G(monde).posx - G(monde).dirx
		* G(monde).movespeed)][(int)G(monde).posy] == 0)
		G(monde).posx -= G(monde).dirx * G(monde).movespeed;
	if (G(monde).worldmap[(int)G(monde).posx][(int)(G(monde).posy
		- G(monde).diry * G(monde).movespeed)] == 0)
		G(monde).posy -= G(monde).diry * G(monde).movespeed;
}

int				key_hook(int keycode)
{
	if (keycode == 53)
	{
		mlx_destroy_image(G(env).mlx, G(env).img);
		mlx_destroy_window(G(env).mlx, G(env).win);
		free_all();
		exit(1);
	}
	if (keycode == UP)
		ft_up();
	if (keycode == DOWN)
		ft_down();
	if (keycode == RIGHT)
		ft_right();
	if (keycode == LEFT)
		ft_left();
	raycaster();
	return (1);
}
