#include "../include/cell_system.h"

void draw_grid(int win_height, int win_width, Color color)	{
	// Divide the screen in 16:9 fragments
	for (int i=0; i<win_height; i += CELL_SIZE)	{
		DrawLine(0, i, win_width, i, color);
	}

	for (int i=0; i<win_width; i += CELL_SIZE)	{
		DrawLine(i, 0, i, win_height, color);
	}
}

inline void draw_in_cell(int cellX, int cellY, Color color)	{
	DrawRectangle(((cellX-1)*CELL_SIZE), ((cellY-1)*CELL_SIZE)+1, CELL_SIZE-1, CELL_SIZE-1, color);
}

void show_buffer(const short buffer[TOTAL_CELL_Y][TOTAL_CELL_X], Color color)	{
	for (short y=0; y < TOTAL_CELL_Y; ++y)	{
		for (short x=0; x < TOTAL_CELL_X; ++x)	{
			if (buffer[y][x])	draw_in_cell(x, y, color);
		}
	}
}

void draw_in_cell_using_pixel(int x, int y, Color color)	{
	draw_in_cell(x/CELL_SIZE+1, y/CELL_SIZE+1, color);
}

inline gol_vec_t get_cell_coords(int pixelX, int pixelY)	{
	gol_vec_t return_it;
	return_it.x = pixelX/CELL_SIZE;
	return_it.y = pixelY/CELL_SIZE;
	return return_it;
}

void write_to_buffer(short buffer[TOTAL_CELL_Y][TOTAL_CELL_X], int pixelX, int pixelY)	{
	gol_vec_t vec = get_cell_coords(pixelX, pixelY);
	buffer[vec.y+1][vec.x+1] = 1;
}
