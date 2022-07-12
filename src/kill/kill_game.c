/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:57:06 by nadesjar          #+#    #+#             */
/*   Updated: 2022/07/06 20:41:57 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3D.h"

void	kill_game(t_game *game, char *str)
{
	free(game->map);
	free(game->ray.last_ray);
	free(game->ray.ray);
	perror(str);
	exit (0);
}

int	x_quit(t_game *game)
{
	free(game->map);
	free(game->ray.last_ray);
	free(game->ray.ray);
	perror("Why did you kill me !#*@**#?");
	exit (0);
}
