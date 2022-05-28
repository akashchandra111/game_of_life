#include "../include/cell_system.h"

void draw_grid(i32 win_height, i32 win_width, Color color)	{
	for (i32 i=0; i<win_height; i += CELL_SIZE)	{
		DrawLine(0, i, win_width, i, color);
	}

	for (i32 i=0; i<win_width; i += CELL_SIZE)	{
		DrawLine(i, 0, i, win_height, color);
	}
}

inline void draw_in_cell(i32 cellX, i32 cellY, Color color)	{
	DrawRectangle(((cellX-1)*CELL_SIZE), ((cellY-1)*CELL_SIZE)+1, CELL_SIZE-1, CELL_SIZE-1, color);
}

void show_buffer(const u8 buffer[TOTAL_CELL_Y][TOTAL_CELL_X], Color color)	{
	for (u16 y=0; y < TOTAL_CELL_Y; ++y)	{
		for (u16 x=0; x < TOTAL_CELL_X; ++x)	{
			if (buffer[y][x])	draw_in_cell(x, y, color);
		}
	}
}

void draw_in_cell_using_pixel(i32 x, i32 y, Color color)	{
	draw_in_cell(x/CELL_SIZE+1, y/CELL_SIZE+1, color);
}

inline gol_vec_t get_cell_coords(i32 pixelX, i32 pixelY)	{
	return (gol_vec_t)	{
		.x = pixelX/CELL_SIZE,
		.y = pixelY/CELL_SIZE,
	};
	/*gol_vec_t return_it;
	return_it.x = pixelX/CELL_SIZE;
	return_it.y = pixelY/CELL_SIZE;
	return return_it;*/
}

void write_to_buffer(u8 buffer[TOTAL_CELL_Y][TOTAL_CELL_X], i32 pixelX, i32 pixelY)	{
	gol_vec_t vec = get_cell_coords(pixelX, pixelY);
	buffer[vec.y+1][vec.x+1] = 1;
}
