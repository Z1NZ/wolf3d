/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 15:06:00 by srabah            #+#    #+#             */
/*   Updated: 2015/05/03 00:23:19 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <stdio.h>

t_global	*g(void)
{
	static t_global *sg;

	if (!sg)
		sg = malloc(sizeof(t_global));
	return (sg);
}

int			ft_strlen2(char **line)
{
	int i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

void		ft_init_map(void)
{
	int nb[3];

	G(monde).posx = 7;
	G(monde).posy = 7;
	G(monde).dirx = -1;
	G(monde).diry = 0;
	G(monde).planex = 0;
	G(monde).planey = 0.66;
	G(monde).c_time = 0;
	G(monde).oldtime = 0;
	G(monde).movespeed = 0.7;
	G(monde).rotspeed = 0.3;
	G(env).mlx = mlx_init();
	G(env).win = mlx_new_window(g()->env.mlx, L_W, H_W, "wolf3d");
	G(env).img = mlx_new_image (g()->env.mlx, L_W, H_W);
	G(env).img_data = mlx_get_data_addr(g()->env.img, &nb[0], &nb[1], &nb[2]);
	G(monde).sizex = 0;
	G(monde).sizey = 0;
}

int			main(int argc, char *argv[])
{
	int fd;

	fd = -1;
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) < 0)
		{
			ft_putstr("\033[31mwolf3d: ");
			perror(argv[1]);
			ft_putstr("\033[m");
			exit(-1);
		}
		else
		{
			ft_init_map();
			ft_size_tab(fd, argv[1]);
		}
	}
	else
		ft_putendl("\033[31mUn seul argument requis\033[m");
	return (0);
}
