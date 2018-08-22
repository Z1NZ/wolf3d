/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah <srabah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 16:08:16 by srabah            #+#    #+#             */
/*   Updated: 2015/05/03 00:15:18 by srabah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int				expose_hook(void)
{
	raycaster();
	return (1);
}

int				loop_hook(void *param)
{
	(void)param;
	return (1);
}

void			free_all(void)
{
	int i;

	i = 0;
	while (i <= G(monde).sizey)
	{
		free(G(monde).worldmap[i]);
		i++;
	}
	free(g());
}
