/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 15:06:00 by srabah            #+#    #+#             */
/*   Updated: 2015/05/03 00:25:37 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <unistd.h>

static void	ft_error(char *path)
{
	ft_putstr("\033[31mwolf3d: ");
	perror(path);
	ft_putstr("\033[m");
	exit(-1);
}

static void	init_hook(void)
{
	mlx_do_key_autorepeaton(G(env).mlx);
	mlx_hook(G(env).win, KEYPRESS, KEYPRESSMASK, key_hook, NULL);
	mlx_expose_hook(g()->env.win, expose_hook, NULL);
	mlx_loop(g()->env.mlx);
}

void		ft_create_map(int x, int y, char *path)
{
	char	**tmp;
	char	*line;
	int		*tab_num[y];
	int		i;

	line = NULL;
	((G(monde).fd = open(path, O_RDONLY)) < 0) ? ft_error(path) : ' ';
	y = 0;
	while ((get_next_line(G(monde).fd, &line)) > 0)
	{
		i = 0;
		tab_num[y] = (int *)malloc(sizeof(int) * x + 1);
		tmp = ft_strsplit(line, ' ');
		while (i < x)
		{
			tab_num[y][i] = ft_atoi(tmp[i]);
			free(tmp[i]);
			i++;
		}
		free(tmp);
		ft_memdel((void **)&line);
		y++;
	}
	ft_memdel((void **)&line);
	tab_num[y] = NULL;
	G(monde).worldmap = tab_num;
	(close(G(monde).fd) < 0) ? ft_error(path) : ' ';
	init_hook();
}

void		ft_size_tab(int fd, char *path)
{
	char	**tab;
	char	*line;
	int		v;

	tab = NULL;
	line = NULL;
	while ((get_next_line(fd, &line)) > 0)
	{
		v = 0;
		tab = ft_strsplit(line, ' ');
		if (ft_strlen2(tab) > G(monde).sizex)
			G(monde).sizex = ft_strlen2(tab);
		while (tab[v])
		{
			ft_memdel((void**)&tab[v]);
			v++;
		}
		ft_memdel((void **)&line);
		ft_memdel((void**)&tab);
		G(monde).sizey++;
	}
	ft_memdel((void **)&line);
	(close(fd) < 0) ? ft_error(path) : ' ';
	ft_create_map(G(monde).sizex, G(monde).sizey, path);
}
