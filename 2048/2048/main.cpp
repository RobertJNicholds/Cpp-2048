#include <iostream>

using namespace std;

void create_grid(int grid[][5]);
void display_grid(int grid[][5]);
void move();

int main()
{	
	int grid[5][5];
	create_grid(grid);
	display_grid(grid);

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
	}
}

void display_grid(int grid[][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << grid[i][j] << " ";
		}

		cout << endl;
	}
}

void move(int grid[][5], int direction)
{
	switch (direction)
	{
	//UP
	case 0:
	//RIGHT
	case 1:
	//DOWN
	case 2:
	//LEFT
	case 3:
	}
}