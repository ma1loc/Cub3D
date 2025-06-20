# include "cub3d.h"

// North(up), South(down), East(right), and West(left).

void	init_north_position(t_player *player, int row, int col)
{
	printf("get the North player position\n");

	player->p_y = row + 0.5;
	player->p_x = col + 0.5;

	player->dir_x = 0;	// >>> for the row
	player->dir_y = -1;	// >>> for the colum

	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	// setup->player->plane_x = 0.66; // Camera plane X
	// setup->player->plane_y = 0; // Camera plane Y
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

}

void	init_south_position(t_player *player, int row, int col)
{
	printf("get the South player position\n");


	player->p_y = row + 0.5;
	player->p_x = col + 0.5;

	player->dir_x = 0; // South direction
	player->dir_y = 1; // South direction

	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	// setup->player->plane_x = -0.66; // Camera plane X
	// setup->player->plane_y = 0; // Camera plane Y
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
}

void	init_east_position(t_player *player, int row, int col)
{
	printf("get the East player position\n");


	player->p_y = row + 0.5;
	player->p_x = col + 0.5;

	player->dir_x = 1; // East direction
	player->dir_y = 0; // East direction

	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	// setup->player->plane_x = 0; // Camera plane X
	// setup->player->plane_y = -0.66; // Camera plane Y
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
}

void	init_west_position(t_player *player, int row, int col)
{
	printf("get the West player position\n");

	player->p_y = row + 0.5;
	player->p_x = col + 0.5;

	player->dir_x = -1; // West direction
	player->dir_y = 0; // West direction

	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	// setup->player->plane_x = 0; // Camera plane X
	// setup->player->plane_y = 0.66; // Camera plane Y
	// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

}
void	get_player_position(t_player *player, t_game *game)
{
	int	row;
	int	col;

	row = -1;
	while (game->map[++row])
	{
		col = -1;
		while (game->map[row][++col])
		{
				if (game->map[row][col] == 'N')
					init_north_position(player, row, col);
				else if (game->map[row][col] == 'S')
					init_south_position(player, row, col);
				else if (game->map[row][col] == 'E')
					init_east_position(player, row, col);
				else if (game->map[row][col] == 'W')
					init_west_position(player, row, col);
		}
	}
}
