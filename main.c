#include "include/raylib.h"
#include "include/gol.h"
#include "include/cell_system.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()	{
	bool is_first_buffer_active = true;
	bool draw_mode = true;
	short buffer1[TOTAL_CELL_Y][TOTAL_CELL_X] = { 0 };
	short buffer2[TOTAL_CELL_Y][TOTAL_CELL_X] = { 0 };

	time_t t;
	srand((unsigned int) time(&t));

	InitWindow(WIN_WIDTH, WIN_HEIGHT, "Game of life");
	SetTargetFPS(5);

	while(!WindowShouldClose())	{
		draw_grid(WIN_HEIGHT, WIN_WIDTH, GRAY);
		ClearBackground(WHITE);

		if (!draw_mode)	{
			if (is_first_buffer_active)	{
				show_buffer(buffer1, BLACK);
				calc_next_buffer(buffer2, buffer1);
			}
			else	{
				show_buffer(buffer2, BLACK);
				calc_next_buffer(buffer1, buffer2);
			}
			is_first_buffer_active = !is_first_buffer_active;
		}
		else	{
			show_buffer(buffer1, YELLOW);
			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))	{
				write_to_buffer(buffer1, GetMouseX(), GetMouseY());
			}
			if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))	{
				draw_mode = false;
			}
			if (IsMouseButtonPressed(MOUSE_MIDDLE_BUTTON))	{
				for (int i=0; i < TOTAL_CELL_Y; ++i)	{
					for (int j=0; j < TOTAL_CELL_X; ++j)	{
						buffer1[i][j] = rand() % 4 == 0;
					}
				}
				draw_mode = false;
			}
		}


		draw_in_cell_using_pixel(GetMouseX(), GetMouseY(), RED);
		// gol_vec_t pointer = get_cell_coords(GetMouseX(), GetMouseY());
		// printf("Cell coords; x: %d, y: %d, Total Neighbours: %d\r", pointer.x, pointer.y, get_total_neighbours(buffer1, pointer.x+1, pointer.y+1));

		DrawFPS(WIN_WIDTH*0.85, WIN_HEIGHT*0.95);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}

