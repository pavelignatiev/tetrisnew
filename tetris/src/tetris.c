#include "tetris.h"
#include <stdlib.h>

#ifndef TETRIS_C
#define TETRIS_C

TetGame *createTetGame(int field_width, int field_height, int figure_size, int count, TetBlock * figure_template) {

TetField* tetf = (TetField*) malloc(sizeof(TetField));

}

TetGame * tetg = (TetGame*) malloc(sizeof(Tetgame));
tetg->field = createTetField(field_width, field_height);
tetg->figurest = createTetFiguresT(figures_size, count,figures_template);
tetg


void calculate(TetGame tetg);



#ifndef