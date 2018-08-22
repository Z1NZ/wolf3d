/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 15:06:00 by srabah            #+#    #+#             */
/*   Updated: 2015/05/03 00:17:39 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "../minilibx_macos/mlx.h"
# include "../libftprintf/includes/ft_printf.h"
# include "../libftprintf/libft/includes/libft.h"
# include "../libftprintf/libft/get_next_line.h"
# include <math.h>

# define G(x)			g()->x
# define RGB_BLUE		255
# define RGB_RED		16711680
# define RGB_GREEN		65280
# define RGB_WHITE		16777215
# define RGB_YELLOW		16776960
# define L_W 			512
# define H_W 			384
# define KEYPRESS		2
# define COL_B(i)		(i >> 16) & 0x000000ff
# define COL_G(i)		(i >> 8) & 0x000000ff
# define COL_R(i)		i & 0x000000ff
# define KEYPRESSMASK	(1L<<0)
# define KEYRELEASEMASK	(1L<<1)

typedef struct	s_world
{
	int			fd;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		c_time;
	double		camerax;
	double		movespeed;
	double		oldtime;
	double		rotspeed;
	double		rayposx;
	double		rayposy;
	double		raydiry;
	double		raydirx;
	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
	double		sidedistx;
	double		sidedisty;
	int			hit;
	int			side;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			**worldmap;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			color;
	int			sizex;
	int			sizey;
}				t_world;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_data;
}				t_env;

typedef struct	s_global
{
	t_world		monde;
	t_env		env;

}				t_global;

typedef enum	e_keys
{
	UP = 126,
	DOWN = 125,
	RIGHT = 124,
	LEFT = 123,
}				t_key;
/*
**	wolf3d.c
*/
int				ft_strlen2(char **line);
t_global		*g(void);
/*
**	maps pars.c
*/
void			ft_size_tab(int fd, char *path);
void			ft_create_map(int x, int y, char *path);
/*
**	Raycaster.c
*/
void			raycaster(void);
/*
**	draw.c
*/
void			verline(int x, int drawstart, int drawend, int color);
void			ft_color(void);
void			ft_put_img_pix(int x, int y, int color);
/*
**	control.c
*/
int				key_hook(int keycode);
/*
**	loop.c
*/
int				expose_hook(void);
int				loop_hook(void *param);
void			free_all(void);

#endif
