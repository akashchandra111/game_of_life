#ifndef GOL_H
#define GOL_H

#include "cell_system.h"

int get_total_neighbours(const short buffer[TOTAL_CELL_Y][TOTAL_CELL_X], int posX, int posY);
void calc_next_buffer(short new_buffer[TOTAL_CELL_Y][TOTAL_CELL_X], const short old_buffer[TOTAL_CELL_Y][TOTAL_CELL_X]);

#endif
