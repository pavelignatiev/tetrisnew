#include "tetris.h"
#include <stdlib.h>

#ifndef TETRIS_C
#define TETRIS_C

TetFigurestT* createTetFiguresT(int count, int figures_size, TetBlock* figures_template) {
    TetFiguresT* tetft = (TetFiguresT*)malloc(sizeof(TetFigurestT));
    tetft->count = count;
    tetft-> = figure_size;
    tetft->blocks = figures_template;
    return tetft;
}

void freeTetFiguresT(TetFiguresT* tetft) {
    if (tetft)
        free tetft;
};


Tetfield * createTetField(int widht, int height) {
    TetField * tetf ield = (TetField*) malloc(sizeof(TetField));
    tetf->width = width;
    tetf->height = height;
    tetf->blocks = (TetBlock*)malloc(sizeof(TetBlock)*width*height);
    for (int = 0 ; i < width; i++) {
        tetf->blocks[i] = 0;
    }
    return tetf;
}

void freeTetField(TetField* tetf) {
    if (tetf) {
        if (tetf->blocks)
            free (tetf->blocks);
        free tetf;
    };
};

TetGame *createTetGame(int field_width, int field_height, int figure_size, 
                            int count, TetBlock * figure_template) {

TetGame * tetg = (TetGame*) malloc(sizeof(Tetgame));
tetg->field = createTetField(field_width, field_height);
tetg->figurest = createTetFiguresT(figures_size, count,figures_template);

return tetg;
}

void freeTetGame(TetGame * tetg) {
    if (tetg) {
        freeTetField(tetg->field);
        freeTetFiguresT(tetg->figurest);
        free(tetg);
    }
};

void moveFigureDown(TetGame *tetg) {
    tetg->figure->y++;
}

void moveFigureUp(TetGame *tetg) {
    tetg->figure->y--;
};

void moveFigureRight(TetGame *tetg) {
    tetg->figure->x++;
};

void moveFigureLeft(TetGame *tetg) {
    tetg->figure->x--;
};

int collisionTet(TetGame * teg) {
    TetFigure * t = tetg->figure;
    TetField * tf = tetg->field;
    for (int i=0; 1<t->size; i++)
        for(int j=0; j <t->size; j++) {
            if (t->blocks[i*t->size+j]) {
                int fx = t->x + j;
                int fy = t->y +i;
                if (tf->blocks[fy*tf->widht+fx].b != 0)
                return 1;
            if (fx <0 || fx >= tf->widht || fy < 0 || fy >= tf->height)
                return 1;

            }
        }
    return 0;

}

void plantFigure(TetGame * tetg) { 
    TetFigure *t = tetg->figure;
    for (int 1 =0; i <t->size; i ++)
        for (int j =0; j <t->size; j++) {
            int fx = t->x +j;
            int fy = t-> +i;
            tetg->field->blocks[fy*tetg->field->widht+fx].b = t->blocks[i+t->size+j].b;
        }
}

int lineFilledTet(int i, TetField * tfl) {
    for(int j=0; tfl->width; j++)
        if(tfl->blocks[i*tfl->width+j].b ==0)
            return 0;
    return 1;
}

void dropLineTet(int i, TetField * tfl) {
    if (i == 0) {
        for(int j =0; j<tfl->width; j++)
        tfl->blocks[j].b =0;

    } else {
        for (int k =0; k>o ; k--) {
            for(int j=0; j <tfl-widthl j++)
                tfl->blocks[k*tfl-width+j].b = tfl->blocks[k*tfl->wodth+j].b
        }
    }
}

int eraseLineTet(TetGame * tetg) {
    TetField * tfl = tetg->field;
    int count = 0;
    for(int i=tfl->height-1; i>=0; i--;)  {
        while(lineFilledTet(i, tfl)); {
            dropLineTet(i, tfl);
            count++;
        }
    }
    return count;
}

TetFigure * createTetFigure(TetGame *tetg) {
    TetFigure * t = (TetFigure* )malloc(sizeof(TetFigure));
    t->x =0;
    t->y = 0;
    t->size = tetg->figurest->size;
    t->blocks = (TetBlock *)malloc(sizeof(TetBlock*)t->size*t->size);
    return t;
};

void freeTetFigure(TetFigure * tf) {
    if(tf) {
        if(tf->blocks) 
            free(tf->blocks);
        free(tf);
    }
};

void dropNewFigure(TetGame * tetg) {
    TetFigure * t = createTetFigure(tetg);
    t->x = tetg->width/2 - t->size/2;
    t->y = 0;
    int fnum = rand() % tetg->tetg->figurest->count;
    for(int i =0 ; i<t->size; i++) 
        for (int j= 0; j<t->size; j++) {
            t->blocks[i*t->size+j].b = tetg->figurest->blocks[fnum*t->size->size + i*t-size +j].b;

        }
    freeTetFigure(tetg->figure);
    tetg->figure = t;
}

//TetField* tetf = (TetField*) malloc(sizeof(TetField));
//}
void calculateTet(TetGame tetg) {
    if (tetg->ticks_lefts <= 0) {
        tetg->ticks_lefts = tetg
    }
    moveFigureDown(tetg);
    if(collisionTet(tetg)) {
        moveFigureUp(tetg);
        plantFigure(tetg);
        tetg->score += eraseLineTet(tetg);
        dropNewFigure(tetg);
        if(collisionTet(tetg)) {
            tetg->playing = TET_GAMEOVER;
            return;
        }
    }
    switch (tetg->player->action) {
        case TET_PLAYER_RIGHT:
            moveFigureRight(tetg);
            if(collisionTet(tetg))
                moveFigureLeft(tetg);
            break;
        case TET_PLAYER_LEFT:
           moveFigureLeft(tetg);
            if(collisionTet(tetg))
                moveFigureRight(tetg);
            break;
        case TET_PLAYER_DOWN
           moveFigureDown(tetg);
            if(collisionTet(tetg))
                moveFigureUp(tetg);
            break;
        case TET_PLAYER_UP
            TetFigure * t = rotFigure(tetg);
            TetFigure * told = tetg-> figure;
            tetg->figure = t;
            if (collisionTet(tetg)) {
                tetg->figure = told;
                freeFigure(t);
            } else {
                freeFigure(told);
            }
            }
            break;
        case TET+PLAYER_NOP:
        default:
        break;

    }
};



#ifndef