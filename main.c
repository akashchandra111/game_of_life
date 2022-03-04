#include "include/raylib.h"
#include "include/gol.h"
#include "include/cell_system.h"
#include "include/types.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FPS 30 

void set_buffer_with_random_vals(u16 buffer[TOTAL_CELL_Y][TOTAL_CELL_X]);

i32 main()	{
	bool is_first_buffer_active = true;
	bool draw_mode = true;
	u16 buffer1[TOTAL_CELL_Y][TOTAL_CELL_X] = { 0 };
	u16 buffer2[TOTAL_CELL_Y][TOTAL_CELL_X] = { 0 };

	time_t t;
	srand((u32) time(&t));
	
	// CELL_SIZE is subtracted to render the cells from 0 to WIN_WIDTH/CELL_SIZE excluding last one for correct calculations
	InitWindow(WIN_WIDTH-CELL_SIZE, WIN_HEIGHT-CELL_SIZE, "Game of life");		
	SetTargetFPS(FPS);

	while(!WindowShouldClose())	{
		draw_grid(WIN_HEIGHT-CELL_SIZE, WIN_WIDTH-CELL_SIZE, GRAY);
		ClearBackground(BROWN);

		if (!draw_mode)	{
			if (is_first_buffer_active)	{
				show_buffer(buffer1, BLACK);
				calc_next_buffer(buffer2, buffer1);
			} else	{
				show_buffer(buffer2, BLACK);
				calc_next_buffer(buffer1, buffer2);
			}

			if (IsMouseButtonPressed(MOUSE_MIDDLE_BUTTON))	{
				if (is_first_buffer_active)	set_buffer_with_random_vals(buffer2);
				else	set_buffer_with_random_vals(buffer1);
			}

			is_first_buffer_active = !is_first_buffer_active;

			if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))	{
				draw_mode = true;
				is_first_buffer_active = true;
			}
		} else	{
			show_buffer(buffer1, YELLOW);
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))	{
				write_to_buffer(buffer1, GetMouseX(), GetMouseY());
			}
			if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))	{
				draw_mode = false;
			}
			if (IsMouseButtonPressed(MOUSE_MIDDLE_BUTTON))	{
				set_buffer_with_random_vals(buffer1);
				draw_mode = false;
			}
		}

		draw_in_cell_using_pixel(GetMouseX(), GetMouseY(), RED);

		DrawFPS(WIN_WIDTH*0.85, WIN_HEIGHT*0.95);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}

void set_buffer_with_random_vals(u16 buffer[TOTAL_CELL_Y][TOTAL_CELL_X])	{
	for (u32 i=0; i < TOTAL_CELL_Y; ++i)	{
		for (u32 j=0; j < TOTAL_CELL_X; ++j)	{
			buffer[i][j] = rand() % 4 == 0;
		}
	}
}
