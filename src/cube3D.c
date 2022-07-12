/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:43:17 by nadesjar          #+#    #+#             */
/*   Updated: 2022/07/10 19:40:06 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3D.h"

int	main(int entry, char **name)
{
	t_game	game;

	init_var(&game);
	// printf("MAIN 1\n");
	check_entry(entry, name, &game);
	// printf("MAIN 2\n");
	find_player(&game);
	init_window(&game);
	return (0);
}

void	init_window(t_game *game)
{
	// printf("INIT_WINDOW_00\n");
	game->mlx = mlx_init();
	// printf("INIT_WINDOW_01\n");
	game->win = mlx_new_window(game->mlx, game->utils.whide, game->utils.height, "TRY ME");
	// printf("INIT_WINDOW_02\n");
	init_imgs(game);
	mlx_hook(game->win, 2, 1L << 0, key_pressed, game);
	mlx_hook(game->win, 6, 1L << 6, mouse_move, game);
	mlx_loop_hook(game->mlx, update, game);
	// mlx_loop_hook(game->mlx, raycast_01, game);
	mlx_hook(game->win, 17, 0, x_quit, game);
	// mlx_mouse_hook(game->win, mouse_key, game);

	mlx_loop(game->mlx);
}
