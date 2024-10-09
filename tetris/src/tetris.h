#ifndef TETRIS_H
#define TETRIS_H


typedef struct TetBlock {
    int b;
} TetBlock;

typedef struct TetFigure {
    int x;
    int y;
    int size;
    TetBlock * blocks;
}TetFigure;

typedef struct TetFiguresT {
    int count;
    int size;
    TetBlocks *blocks;
} TetFiguresT;

typedef struct TetField {
    int widht;
    int height;
    TetBlock * blocks;
} TetField;

typedef struct TetGame {
    TetField *field; //информация об игровом поле
    TetFigure * figure; // информация об игровой фигуре
    TetFiguresT * figurest;
    
} TetGame;

TetGame *createTetGame(int field_width, int field_height, int figure_size, int count, TetBlock * figure_template); 

void calculate(TetGame tetg);


#endif