#pragma once

#define WIN_WIDTH 1360
#define WIN_HEIGHT 760
#define CELL_SIZE 10
#define TOTAL_CELL_X WIN_WIDTH/CELL_SIZE
#define TOTAL_CELL_Y WIN_HEIGHT/CELL_SIZE

#include "raylib.h"
#include "types.h"

typedef struct gol_vec	{
	i32 x;
	i32 y;
} gol_vec_t;

void draw_grid(i32 win_height, i32 win_width, Color color);
void draw_in_cell(i32 cellX, i32 cellY, Color color);	
void draw_in_cell_using_pixel(i32 x, i32 y, Color color);
void show_buffer(const u16 buffer[TOTAL_CELL_Y][TOTAL_CELL_X], Color color);
gol_vec_t get_cell_coords(i32 pixelX, i32 pixelY);
void write_to_buffer(u16 buffer[TOTAL_CELL_Y][TOTAL_CELL_X], i32 pixelX, i32 pixelY);
