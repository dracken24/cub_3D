/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:57:06 by nadesjar          #+#    #+#             */
/*   Updated: 2022/06/23 19:57:59 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3D.h"

void	kill_game(t_game *game, t_imgs *imgs, char *str)
{
	imgs->test = 0;
	free(game->map);
	perror(str);
	exit (0);
}

int	x_quit(t_game *game)
{
	free(game->map);
	perror("Why did you kill me !#*@**#?");
	exit (0);
}
