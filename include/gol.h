#pragma once

#include "cell_system.h"
#include "types.h"

i32 get_total_neighbours(const u8 buffer[TOTAL_CELL_Y][TOTAL_CELL_X], i32 posX, i32 posY);
void calc_next_buffer(u8 new_buffer[TOTAL_CELL_Y][TOTAL_CELL_X], const u8 old_buffer[TOTAL_CELL_Y][TOTAL_CELL_X]);
