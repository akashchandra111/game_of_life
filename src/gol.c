#include "../include/gol.h"

i32 get_total_neighbours(const u8 buffer[TOTAL_CELL_Y][TOTAL_CELL_X], i32 posX, i32 posY)	{
	i32 total = 0;

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

void calc_next_buffer(u8 new_buffer[TOTAL_CELL_Y][TOTAL_CELL_X], const u8 old_buffer[TOTAL_CELL_Y][TOTAL_CELL_X])	{
	for (u16 y=0; y<TOTAL_CELL_Y; ++y)	{
		for (u16 x=0; x<TOTAL_CELL_X; ++x)	{
			new_buffer[y][x] = 0;
			i32 const total_neighbours = get_total_neighbours(old_buffer, x, y);
			/* Old implementation (replacing with the new one to avoid branching, which may result in speedup)
			if (old_buffer[y][x] && total_neighbours < 2)	new_buffer[y][x] = 0;
			if (old_buffer[y][x] && (total_neighbours == 2 || total_neighbours == 3))	new_buffer[y][x] = 1;
			if (old_buffer[y][x] && total_neighbours > 3)	new_buffer[y][x] = 0;
			if (!old_buffer[y][x] && total_neighbours == 3)	new_buffer[y][x] = 1;
			*/

			if (old_buffer[y][x])	{
				bool const condition = (total_neighbours == 2 || total_neighbours == 3);
				(condition) && (new_buffer[y][x] = 1) || (!condition) && (new_buffer[y][x] = 0);
			} else	{
				(total_neighbours == 3) && (new_buffer[y][x] = 1);
			}
		}
	}
}
