/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 15:06:00 by srabah            #+#    #+#             */
/*   Updated: 2015/06/04 15:45:44 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	ft_put_img_pix(int x, int y, int color)
{
	unsigned long pos;

	if (x < L_W && y < H_W && x >= 0 && y >= 0)
	{
		pos = y * L_W * 4 + x * 4;
		G(env).img_data[pos] = COL_R(color);
		G(env).img_data[pos + 1] = COL_G(color);
		G(env).img_data[pos + 2] = COL_B(color);
	}
}

void	verline(int x, int drawstart, int drawend, int color)
{
	int	y;

	y = L_W;
	while (y != 0)
	{
		if (y >= drawstart && y <= drawend)
			ft_put_img_pix(x, y, color);
		else if (y > drawstart)
			ft_put_img_pix(x, y, 0x582900);
		else
			ft_put_img_pix(x, y, 0xA9EAFF);
		y--;
	}
}

int            ft_getcolor(void)
{
    if (G(monde).side == 0)
    {
        if (G(monde).stepx < 0)
            return (G(monde).color = G(monde).color / 2);
        return (G(monde).color = G(monde).color / 3);
    }
    if (G(monde).stepy < 0)
        return (G(monde).color = G(monde).color / 2);
    return (G(monde).color = G(monde).color / 3);

}

void	ft_color(void)
{
	if (G(monde).worldmap[G(monde).mapx][G(monde).mapy] == 1)
		G(monde).color = RGB_GREEN;
	else if (G(monde).worldmap[G(monde).mapx][G(monde).mapy] == 2)
		G(monde).color = RGB_RED;
	else if (G(monde).worldmap[G(monde).mapx][G(monde).mapy] == 3)
		G(monde).color = RGB_BLUE;
	else if (G(monde).worldmap[G(monde).mapx][G(monde).mapy] == 4)
		G(monde).color = RGB_WHITE;
	else
		G(monde).color = RGB_YELLOW;
	if (G(monde).side == 1)
		G(monde).color = G(monde).color / 2;
	G(monde).color = ft_getcolor();
}
