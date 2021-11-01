#include "../include/gol.h"

int get_total_neighbours(const short buffer[TOTAL_CELL_Y][TOTAL_CELL_X], int posX, int posY)	{
	int total = 0;

	if (posX-1 >= 0 && posY-1 >= 0 && buffer[posY-1][posX-1])	++total;
	if (posX >= 0 && posY-1 >= 0 && buffer[posY-1][posX])	++total;
	if (posX+1 < TOTAL_CELL_X && posY-1 >= 0 && buffer[posY-1][posX+1])	++total;
	if (posX-1 >= 0 && posY >= 0 && buffer[posY][posX-1])	++total;
	if (posX+1 < TOTAL_CELL_X && posY >= 0 && buffer[posY][posX+1])	++total;
	if (posX-1 >= 0 && posY+1 < TOTAL_CELL_Y && buffer[posY+1][posX-1])	++total;
	if (posX >= 0 && posY+1 >= 0 && buffer[posY+1][posX])	++total;
	if (posX+1 < TOTAL_CELL_X && posY+1 < TOTAL_CELL_Y && buffer[posY+1][posX+1])	++total;

	return total;
}

void calc_next_buffer(short new_buffer[TOTAL_CELL_Y][TOTAL_CELL_X], const short old_buffer[TOTAL_CELL_Y][TOTAL_CELL_X])	{
	for (int y=0; y<TOTAL_CELL_Y; ++y)	{
		for (int x=0; x<TOTAL_CELL_X; ++x)	{
			new_buffer[y][x] = 0;
			int total_neighbours = get_total_neighbours(old_buffer, x, y);
			if (old_buffer[y][x] && total_neighbours < 2)	new_buffer[y][x] = 0;
			if (old_buffer[y][x] && (total_neighbours == 2 || total_neighbours == 3))	new_buffer[y][x] = 1;
			if (old_buffer[y][x] && total_neighbours > 3)	new_buffer[y][x] = 0;
			if (!old_buffer[y][x] && total_neighbours == 3)	new_buffer[y][x] = 1;
		}
	}
}
