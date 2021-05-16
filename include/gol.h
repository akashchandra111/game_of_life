#ifndef GOL_H
#define GOL_H

#include "cell_system.h"

int get_total_neighbours(const short buffer[WIN_HEIGHT][WIN_WIDTH], int posX, int posY);
void calc_next_buffer(short new_buffer[WIN_HEIGHT][WIN_WIDTH], const short old_buffer[WIN_HEIGHT][WIN_WIDTH]);

#endif
