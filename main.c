#include <unistd.h>

int	solve(int board[4][4], int *clues);

void	empty_board(int (*board)[4][4])
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			(*board)[row][col] = 0;
			col++;
		}
		row++;
	}
}

int	parse_clues(char *av, int *clues)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		if ((av[i] >= '1' && av[i] <= '4'))
		{
			clues[j] = (av[i] - '0');
			j++;
			i++;
		}
		if (av[i] == ' ')
			i++;
		else
			return (j);
	}
	return (j);
}

void	print_board(int board[4][4])
{
	int		row;
	int		col;
	char	c;

	row = 0;
	col = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			c = board[row][col] + '0';
			write(1, &c, 1);
			if (col == 3)
				col++;
			else
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

int	main(int ac, char **av)
{
	int	clues[16];
	int	board[4][4];

	if (ac != 2)
	{
		write(1, "Invalid amount of arguments (ac != 2)\n", 38);
		return (1);
	}
	if (parse_clues(av[1], clues) != 16)
	{
		write(1, "Invalid clue edges provided\n", 28);
		return (1);
	}
	empty_board(&board);
	if (!solve(board, clues))
	{
		write(1, "Unsolvable puzzle\n", 18);
		return (1);
	}
	print_board(board);
	return (0);
}
