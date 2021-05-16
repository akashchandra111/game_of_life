#ifndef GOL_CELL_SYSTEM_H
#define GOL_CELL_SYSTEM_H

#define CELL_SIZE 20
#define WIN_WIDTH 800
#define WIN_HEIGHT 600 

#define TOTAL_CELL_X WIN_WIDTH/CELL_SIZE
#define TOTAL_CELL_Y WIN_HEIGHT/CELL_SIZE

#include "raylib.h"

typedef struct gol_vec	{
	int x;
	int y;
} gol_vec_t;

void draw_grid(int win_height, int win_width, Color color);
void draw_in_cell(int cellX, int cellY, Color color);	
void draw_in_cell_using_pixel(int x, int y, Color color);
void show_buffer(const short buffer[TOTAL_CELL_Y][TOTAL_CELL_X], Color color);
gol_vec_t get_cell_coords(int pixelX, int pixelY);
void write_to_buffer(short buffer[TOTAL_CELL_Y][TOTAL_CELL_X], int pixelX, int pixelY);

#endif
