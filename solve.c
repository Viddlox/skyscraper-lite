#include <unistd.h>
#include <stdbool.h>

bool	check_board(int board[4][4], int *cell);

bool	search_traverse_empty(int board[4][4], int *row, int *col)
{
	*row = 0;
	*col = 0;
	while (*row < 4)
	{
		*col = 0;
		while (*col < 4)
		{
			if (board[*row][*col] == 0)
				return (true);
			*col += 1;
		}
		*row += 1;
	}
	return (false);
}

bool	check_no_duplicates_col(int board[4][4], int col, int tower_height)
{
	int	row;

	row = 0;
	while (row < 4)
	{
		if (board[row][col] == tower_height)
			return (false);
		row++;
	}
	return (true);
}

bool	check_no_duplicates_row(int board[4][4], int row, int tower_height)
{
	int	col;

	col = 0;
	while (col < 4)
	{
		if (board[row][col] == tower_height)
			return (false);
		col++;
	}
	return (true);
}

bool	check_no_duplicates(int board[4][4], int r, int c, int tower_height)
{
	if (check_no_duplicates_row(board, r, tower_height)
		&& check_no_duplicates_col(board, c, tower_height))
		return (true);
	return (false);
}

bool	solve(int board[4][4], int *clues)
{
	int	row;
	int	col;
	int	tower_height;

	tower_height = 1;
	if (!search_traverse_empty(board, &row, &col) && check_board(board, clues))
		return (true);
	while (tower_height <= 4)
	{
		if (check_no_duplicates(board, row, col, tower_height)
			&& board[row][col] == 0)
		{
			board[row][col] = tower_height;
			if (solve(board, clues))
				return (true);
			board[row][col] = 0;
		}
		tower_height++;
	}
	return (false);
}
