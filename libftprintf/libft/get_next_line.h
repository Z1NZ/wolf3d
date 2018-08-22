/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiane <sofiane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 02:36:07 by srabah            #+#    #+#             */
/*   Updated: 2015/05/02 23:26:02 by sofiane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>
# include <sys/wait.h>

# define BUFF_SIZE 4

int		get_next_line(int const fd, char **line);

#endif
