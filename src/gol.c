#include "../include/gol.h"

int get_total_neighbours(const short buffer[WIN_HEIGHT][WIN_WIDTH], int posX, int posY)	{
	int total = 0;

	if (posX-1 >= 0 && posY-1 >= 0 && buffer[posY-1][posX-1])	{
		//draw_in_cell(posX-1, posY-1, GREEN);
		++total;
	}
	if (posX >= 0 && posY-1 >= 0 && buffer[posY-1][posX])	{
		//draw_in_cell(posX, posY-1, GREEN);
		++total;
	}
	if (posX+1 <= WIN_WIDTH && posY-1 >= 0 && buffer[posY-1][posX+1])	{
		//draw_in_cell(posX+1, posY-1, GREEN);
		++total;
	}
	if (posX-1 >= 0 && posY >= 0 && buffer[posY][posX-1])	{
		//draw_in_cell(posX-1, posY, GREEN);
		++total;
	}
	if (posX+1 <= WIN_WIDTH && posY >= 0 && buffer[posY][posX+1])	{
		//draw_in_cell(posX+1, posY, GREEN);
		++total;
	}
	if (posX-1 >= 0 && posY+1 <= WIN_HEIGHT && buffer[posY+1][posX-1])	{
		//draw_in_cell(posX-1, posY+1, GREEN);
		++total;
	}
	if (posX >= 0 && posY+1 >= 0 && buffer[posY+1][posX])	{
		//draw_in_cell(posX, posY+1, GREEN);
		++total;
	}
	if (posX+1 <= WIN_WIDTH && posY+1 <= WIN_HEIGHT && buffer[posY+1][posX+1])	{
		//draw_in_cell(posX+1, posY+1, GREEN);
		++total;
	}

	return total;
}

void calc_next_buffer(short new_buffer[WIN_HEIGHT][WIN_WIDTH], const short old_buffer[WIN_HEIGHT][WIN_WIDTH])	{
	for (int y=0; y<WIN_HEIGHT; ++y)	{
		for (int x=0; x<WIN_WIDTH; ++x)	{
			new_buffer[y][x] = 0;
		}
	}

	for (int y=0; y<WIN_HEIGHT; ++y)	{
		for (int x=0; x<WIN_WIDTH; ++x)	{
			int total_neighbours = get_total_neighbours(old_buffer, x, y);
			if (old_buffer[y][x] && total_neighbours < 2)	new_buffer[y][x] = 0;
			if (old_buffer[y][x] && (total_neighbours == 2 || total_neighbours == 3))	new_buffer[y][x] = 1;
			if (old_buffer[y][x] && total_neighbours > 3)	new_buffer[y][x] = 0;
			if (!old_buffer[y][x] && total_neighbours == 3)	new_buffer[y][x] = 1;
		}
	}
}
