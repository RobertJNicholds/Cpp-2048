#include <iostream>
#include <time.h>

using namespace std;

void create_grid(int grid[][5]);
void display_grid(int grid[][5]);
void pair_values(int grid[][5], char direction);

bool running = true;

int main()
{	
	
	srand(static_cast<unsigned int>(time(NULL)));
	int grid[5][5];
	create_grid(grid);

	while (running)
	{
		display_grid(grid);
		char input;
		cin >> input;		
		pair_values(grid, input);
	}

	int exit;
	cin >> exit;
	return 0;
}

void create_grid(int grid[][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			grid[i][j] = 0;
		}
	}	

	for (int count = 0; count < 2; count++)
	{
		int x = rand() % 5;
		int y = rand() % 5;

		if(grid[x][y] == 0)
			grid[x][y] = 2;

		grid[0][0] = 2;
		grid[0][1] = 2;
	}
}

void display_grid(int grid[][5])
{
	system("cls");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << grid[i][j] << " ";
		}

		cout << endl;
	}
}

void pair_values(int grid[][5], char direction)
{
	switch (direction)
	{
	//UP
	case 'w':
		for (int x = 0; x < 5; x++)
		{
			for (int y = 0; y < 5; y++)
			{
				if (grid[x][y] == grid[x - 1][y])
				{
					grid[x - 1][y] += grid[x][y];
					grid[x][y] = 0;						
				}	
			}
		} 		
		break;

	//LEFT
	case 'a':
		for (int x = 0; x < 5; x++)
		{
			for (int y = 0; y < 5; y++)
			{
				if (grid[x][y] == grid[x][y - 1])
				{
					grid[x][y - 1] += grid[x][y];
					grid[x][y] = 0;
				}
			}
		}
		break;
	//DOWN
	case 's':
		for (int x = 0; x < 5; x++)
		{
			for (int y = 0; y < 5; y++)
			{
				if (grid[x][y] == grid[x + 1][y])
				{
					grid[x + 1][y] += grid[x][y];
					grid[x][y] = 0;
				}
			}
		}
		break;
	//RIGHT
	case 'd':
		for (int x = 0; x < 5; x++)
		{
			for (int y = 0; y < 5; y++)
			{
				if (grid[x][y] == grid[x][y + 1])
				{
					grid[x][y + 1] += grid[x][y];
					grid[x][y] = 0;
				}
			}
		}
		break;

	case 'e':
		running = false;		
	}
}